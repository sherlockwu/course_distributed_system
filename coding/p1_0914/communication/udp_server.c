#include "common.h"


#define SERVER_PORT "1111"
#define BUFF_SIZE 255

int create_socket(struct sockaddr_in * echoserver);
void start_listen(int sock);
void self_intro(void);

int main(int argc, char * argv[]){
    // setting
	int sock;
	struct sockaddr_in echoserver;

	self_intro();

    // create server socket/ bind socket to server
	sock = create_socket(&echoserver);

    start_listen(sock);
    // listening     sending back or other operation

    //wrapup
    close(sock);
    return 0;
}


/*
void die(char * message){
	perror(message);
	exit(1);
	return;
}
*/


int create_socket(struct sockaddr_in * echoserver){
	int sock;

	// create server socket
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);


	// set to unblock
	int flags = fcntl(sock, F_GETFL, 0);
	fcntl(sock, F_SETFL, O_NONBLOCK|flags);




	memset(echoserver, 0, sizeof(struct sockaddr_in));
	echoserver->sin_family = AF_INET;                  		/* Internet/IP */
    (echoserver->sin_addr).s_addr = htonl(INADDR_ANY);  	/* Any server address */
   	echoserver->sin_port = htons(atoi(SERVER_PORT));       	/* server port */

	// bind to server itself
	if (bind(sock, (struct sockaddr *) echoserver, sizeof(struct sockaddr_in)) <0 ){
		die("Fail to bind!");
	} else{
		printf("Bind Successfully!\n");
	}



	return sock;
}

void start_listen(int sock){
	int receive_len = 0;
	char buffer[BUFF_SIZE];
	struct sockaddr_in echoclient;

	printf("Start Listening!\n");

	// loop
	while(1){
		// 	recvfrom
		unsigned int clientlen = sizeof(echoclient);
		receive_len = my_recvfrom(sock, buffer, BUFF_SIZE, 0, (struct sockaddr *) &echoclient, &clientlen);
		/*
		receive_len = 0;
		while (receive_len <=0){
			receive_len = recvfrom(sock, buffer, BUFF_SIZE, 0, (struct sockaddr *) &echoclient, &clientlen);
		}

		// send ack
		sent_message = sendto(sock, ack_message, strlen(ack_message), 0, (struct sockaddr *) &echoclient, sizeof(echoclient));

		*/

		// operation
		buffer[receive_len]='\0';
		printf("Server: receive %s, len: %d \n", buffer, receive_len);
		int sent_message;

		// send message (operation)  my_sendto

		sent_message = my_sendto(sock, buffer, receive_len, 0, &echoclient, sizeof(echoclient));

	}
	return;

}

void self_intro(){

	printf("The udp sercer is running\n");
	return;
}
