#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

// TODO set this??
#define IP_ADDR "192.168.1.1"
#define IP_PORT "88"
#define BUFF_SIZE 255

int	creat_socket(struct sockaddr_in * echoserver, char * message);
void send_message(int sock, struct sockaddr_in * echoserver, char * message);
void receive_message(int sock, char * buffer, struct sockaddr_in * echoserver);
void die(char * message);
// TODO add die test 

int main(int argc, char *argv[]){
    // setting
	int sock; 
	char * message;
	struct sockaddr_in echoserver;
	char buff[BUFF_SIZE];

    // create scoket & the server's data structure
	
	sock = creat_socket(&echoserver);
    
    // send message   
	send_message(sock, &echoserver, argv[1]);

    // receive message
	receive_message(sock, buffer, &echoserver);
		// receive, check received source with echoserver, printf something 
    
    //wrapup
	close(scok);

    return 0;
}

void die(char * message){
	fprintf(stderr, message);
	exit(1);
	return; 
}

int	creat_socket(struct sockaddr_in * echoserver, char * message){

	int sock;

	// create sock
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	// set the remote server addr data structure
	memset(echoserver, 0, sizeof(struct sockaddr_in));
	echoserver->sin_family = AF_INET;                  		/* Internet/IP */
    (echoserver->sin_addr).s_addr = inet_addr(IP_ADDR);  	/* IP address */
   	echoserver->sin_port = htons(atoi(IP_PORT);       		/* server port */

	return sock; 
}

void send_message(int sock, struct sockaddr_in * echoserver, char * message){
	int message_len = strlen(message);
	int success_len; 
	success_len = sendto(sock, message, message_len, 0, (struct sockaddr *)echoserver, sizeof(struct sockaddr_in)); 
	return; 
}

void receive_message(int sock, char * buffer, struct sockaddr_in * echoserver){
	int receive_len; 
	struct sockaddr_in echoclient; 
	// receive
	receive_len = recvfrom(sock, buffer, BUFF_SIZE, 0, (struct sockaddr *) &echoclient, sizeof(echoclient));
	// check received source with echoserver
	if (echoserver.sin_addr.s_addr != (echoserver->sin_addr).s_addr){
		die("Receive message from unkown server!");
	}
	
	// printf something 
	buffer[receive_len] = '\0';
	printf("received: %s \n", buffer);
	return;
}



