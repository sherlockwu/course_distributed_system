#include "common.h"




// TODO set this??
#define IP_ADDR "127.0.0.1"
#define IP_PORT "1111"

int  creat_socket(struct sockaddr_in * echoserver);
void send_message(int sock, struct sockaddr_in * echoserver, char * message);
void receive_message(int sock, char * buffer, struct sockaddr_in * echoserver);
//void die(char * message);

int main(int argc, char *argv[]){
    // setting
	int sock;
	struct sockaddr_in echoserver;
	char buff[BUFF_SIZE];

	if (argc < 2){
		die("Usage: udp_client char* message ");
	}

    // create scoket & the server's data structure

	sock = creat_socket(&echoserver);

    // send message
	send_message(sock, &echoserver, argv[1]);

    // receive message
	receive_message(sock, buff, &echoserver);

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

int	creat_socket(struct sockaddr_in * echoserver){

	int sock;

	// create sock
	sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);


	// set to unblock
	int flags = fcntl(sock, F_GETFL, 0);
	fcntl(sock, F_SETFL, O_NONBLOCK|flags);


	// set the remote server addr data structure
	memset(echoserver, 0, sizeof(struct sockaddr_in));
	echoserver->sin_family = AF_INET;                  		/* Internet/IP */
    (echoserver->sin_addr).s_addr = inet_addr(IP_ADDR);  	/* IP address */
   	echoserver->sin_port = htons(atoi(IP_PORT));       		/* server port */

	return sock;
}

void send_message(int sock, struct sockaddr_in * echoserver, char * message){
	int message_len = strlen(message);
	int success_len;


	// loop send/ wait ack
	//success_len = sendto(sock, message, message_len, 0, (struct sockaddr *)echoserver, sizeof(struct sockaddr_in));
	success_len = my_sendto(sock, message, message_len, 0, echoserver, sizeof(struct sockaddr_in));

	return;

}

void receive_message(int sock, char * buffer, struct sockaddr_in * echoserver){
	int receive_len=0;
	struct sockaddr_in echoclient;
	unsigned int clientlen = sizeof(echoclient);
	// receive
	//receive_len = recvfrom(sock, buffer, BUFF_SIZE, 0, (struct sockaddr *) &echoclient, &clientlen);
	// check received source with echoserver

	receive_len = my_recvfrom(sock, buffer, BUFF_SIZE, 0, (struct sockaddr *) &echoclient, &clientlen);

	if (echoclient.sin_addr.s_addr != (echoserver->sin_addr).s_addr){
		die("Receive message from unknown server!");
	}

	// printf something
	buffer[receive_len] = '\0';
	printf("Client: receive %s \n", buffer);
	return;
}



