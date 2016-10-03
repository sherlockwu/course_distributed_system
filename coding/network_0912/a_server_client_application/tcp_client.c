#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

// buffersize
#define BUFFSIZE 24

// error function
void die(char * err_msg){
    perror(err_msg);
    exit(1);
}

int main(int argc, char * argv[]){
    // Setup client
    struct sockaddr_in server_address;
    char * message_out;
    int received_message = 0;
    char buffer[BUFFSIZE];

    // create socket
    int sock;

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        die("Failed to create socket");
    }
    // set connection for the socket
        // set the destination structure
        memset(&server_address, 0, sizeof(struct sockaddr_in));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(atoi(argv[2]));
        server_address.sin_addr.s_addr = inet_addr(argv[1]);

        // connect
        if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0 ){
            die("Failed to connect to the server");
        }
    // send, receive data
        // prepare data
        message_out = malloc(10*sizeof(char));
        strcpy(message_out, "Hello, world!");
        // send out
        if (send(sock, message_out, strlen(message_out), 0) != strlen(message_out)){
            die("Cannot send out message!");
        }
        //receive data
        while (received_message < strlen(message_out)){
            // receive
            int counter;
            if ( (counter = recv(sock, buffer, BUFFSIZE-1, 0)) < 1 ){
                die("Failed to receive message");
            }
            // ++
            received_message += counter;
            buffer[counter] = '\0';
            printf("%s", buffer);


        }
    // wrapup
    printf("\n");
    close(sock);
    return 0;
}
