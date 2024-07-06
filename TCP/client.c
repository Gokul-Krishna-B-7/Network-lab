#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void main()
{
    int cs, port; //initialize clientsocket, port
    struct sockaddr_in client; //initialize clientsocket
    int flag, res;
    char buffer[20];

    cs = socket(AF_INET, SOCK_STREAM,0); //create a clientsocket with IPv4, TCP and default protocol
    client.sin_family = AF_INET; //set clientsocket address family to IPv4
    printf("Enter the port number:");
    scanf("%d",&port); 
    client.sin_port = htons(port);
    connect(cs, (struct sockaddr*)&client, sizeof(client));

    do{
        printf("Enter a string to check:");
        scanf("%s",buffer);
        printf("Client: %s",buffer);

        send(cs, buffer,sizeof(buffer), 0); //send message to the server

        recv(cs, &flag, sizeof(flag), 0); //receive message from the server

        if(flag == 1)
            printf("Server: The string is a pallindrome.\n");
        else
            printf("Server: The string is not a pallindrome.\n");
        printf("Do you wish to continue?(1/0):");
        scanf("%d",&res);
    }while(res == 1);
    close(cs);
}