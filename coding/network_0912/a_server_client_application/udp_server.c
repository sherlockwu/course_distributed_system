#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>



#define SERVER_PORT "88"
#define BUFF_SIZE 255

int create_socket(struct sockaddr_in * echoserver);
void start_listen(int sock);
void die(char * message);

int main(int argc, char * argv[]){
    // setting
	int sock;
	struct sockaddr_in echosever;

    // create server socket/ bind socket to server
	sock = create_socket(&echoserver);
    
    start_listen(sock); 
    // listening     sending back or other operation
    
    //wrapup
    return 0;
}



void die(char * message){
	fprintf(stderr, message);
	exit(1);
	return; 
}



int create_socket(struct sockaddr_in * echoserver){
	int sock;

	// create server socket 
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	memset(echoserver, 0, sizeof(struct sockaddr_in));
	echoserver->sin_family = AF_INET;                  		/* Internet/IP */
    (echoserver->sin_addr).s_addr = htonl(INADDR_ANY);  	/* Any server address */
   	echoserver->sin_port = htons(atoi(SERVER_PORT);       	/* server port */

	// bind to server itself
	bind(sock, (struct sockaddr *) echoserver, sizeof(struct sockaddr_in));


	return sock; 
}

void start_listen(int sock){
	int receive_len = 0; 
	char buff[BUFF_SIZE];
	struct sockaddr_in echoclient;


	// loop
	while(1){
		// 	recvfrom 
		int clientlen = sizeof(echoclient);
		receive_len = recvfrom(sock, buffer, BUFFSIZE, 0, (struct sockaddr *) &echoclient,
                                       &clientlen);
		// operation		
		int sent_message; 
		sent_message = sendto(sock, buffer, receive_len, 0, (struct sockaddr *) &echoclient, sizeof(echoclient);

	}
	
	return;

}