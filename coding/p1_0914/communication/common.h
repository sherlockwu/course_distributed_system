#ifndef __common_h__
#define __common_h__

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


#define TIME_RETRY 10*1e9  
#define BUFF_SIZE 255
#define ACK_MESSAGE "ACK"
// TODO test the expected time_difference


// clock_gettime in OSX

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

void current_utc_time(struct timespec *ts) {

#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  ts->tv_sec = mts.tv_sec;
  ts->tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_MONOTONIC, ts);
#endif

}




// block in sending until receive ack 
int my_sendto(int sock, const void * message, size_t message_len, int flags, const struct sockaddr_in * dest, socklen_t dest_len);
// recv with sending back ack
int my_recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len);


// call time difference
double get_time_diff(struct timespec * send_stamp, struct timespec * current_stamp);
// alert messages
void die(char * message);

//TODO int my_recvfrom();
// ack when receive packet with sepcific ID 



void die(char * message){
	perror(message);
	exit(1);
	return; 
}


double get_time_diff(struct timespec * t_start, struct timespec * t_end){
	double time_diff;
	time_diff = 1e9 * (t_end->tv_sec - t_start->tv_sec) + (t_end->tv_nsec - t_start->tv_nsec);
	return time_diff; 
}


int my_sendto(int sock, const void * message, size_t message_len, int flags, const struct sockaddr_in * dest, socklen_t dest_len){

	int sent_message;
	struct timespec send_stamp;
	struct timespec current_stamp;
	double time_diff; 
	

	int receive_len;
	struct sockaddr_in echoclient; 
	unsigned int clientlen = sizeof(echoclient);
	char buffer[BUFF_SIZE];
	memset(buffer, 0, BUFF_SIZE);
	
	while(1){
		
		
		// loop send   TODO need to be blocked? 
		sent_message = sendto(sock, message, message_len, flags, (struct sockaddr *) dest, dest_len);
		time_diff = 0.0;  
		current_utc_time(&send_stamp); 
	
		// clock and recieve data, if in time: return
		while(time_diff <= TIME_RETRY){
			// recv   recvfrom block? 
			
			receive_len = recvfrom(sock, buffer, BUFF_SIZE, 0, (struct sockaddr *) &echoclient, &clientlen);
			
			// if recvfrom ok  return
			if (receive_len >0){
				if (echoclient.sin_addr.s_addr != (dest->sin_addr).s_addr){
					die("Receive message from unknown server!");
				}
				if (strcmp(buffer, ACK_MESSAGE) == 0){
					return sent_message; 
					// TODO I will need to check the ack id(is it for what we are looking for? )
				} else{
					printf("!!!!!%s!!!\n", buffer);	
					die("Receive not ACK from the server!");
				}	
			}


			// cal time
			current_utc_time(&current_stamp);
			time_diff = get_time_diff(&send_stamp, &current_stamp); 
			
		}	
	}
	

//	return sent_message;
}


int my_recvfrom(int socket, void *restrict buffer, size_t length, int flags, struct sockaddr *restrict address, socklen_t *restrict address_len){
	int receive_len = 0;
	int sent_message;
	
	// block waiting (while the socket is unblock)
	while(receive_len <= 0){
		receive_len = recvfrom(socket, buffer, length, 0, address, address_len);
	}

	// received -> ack
	sent_message = sendto(socket, ACK_MESSAGE, strlen(ACK_MESSAGE), 0, address, *address_len);

	return receive_len; 
}

#endif 
