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

    // create socket
    int sock;

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
        die("Failed to create socket");
    }
    // set connection for the socket

    // send, receive data

    // wrapup
    return 0;
}
