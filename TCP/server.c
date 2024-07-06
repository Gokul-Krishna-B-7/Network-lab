#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void main()
{
    int ss, cs, port; //initialize serversocket, clientsocket and port
    struct sockaddr_in server, client; //initialize serversocket and clientsocket addresses
    socklen_t len; //initialize the length of the socket
    int i, flag, length;
    char b1[20];

    ss = socket(AF_INET, SOCK_STREAM, 0); //create socket with IPv4, TCP and default protocol
    server.sin_family =AF_INET; //set serversocket address family to IPv4

    printf("Enter the port number:");
    scanf("%d",&port); //get port number form the user

    printf("Listening for connections...\n");
    
    server.sin_port = htons(port); //convert port to network byte order
    server.sin_addr.s_addr = INADDR_ANY; // set serversocket address to any local IP address

    bind(ss, (struct sockaddr*)&server, sizeof(server)); //bind the serversocket to the server address

    listen(ss,1); //listen for incoming connections on the serversocket

    len = sizeof(client); //set length of clientsocket
    cs = accept(ss, (struct sockaddr*)&client, &len); //accept incoming connections on the server socket
    printf("Connected to the client...\n");

    for(;;)
    {
        memset(b1, 0, sizeof(b1)); //clear the buffer
        int byte_recv = recv(cs, b1, sizeof(b1), 0); //receive message from the client

        if(byte_recv == 0)
        {
            printf("Connection closed\n");
            break;
        }
        
        printf("The string received is: %s\n",b1);

        flag = 1;
         // Check if string is a palindrome
        length = strlen(b1); // get length of string
        for (i = 0; i < length / 2; i++)
        {
            if (b1[i] != b1[length - i - 1])
            { // If characters do not match
                flag = 0;
                break;
            }
        }

        send(cs, &flag, sizeof(flag), 0);
    }
    close(ss);
    close(cs);
}

/*
        // Check if the number is prime
         int num = atoi(b1); // Convert string to integer
         for (i = 2; i <= num / 2; i++){
             if (num % i == 0){ // If number is divisible by i
                 flag = 0;
                 break;
             }
         }

        // Check if the number is amstrong
         int num = atoi(b1); // Convert string to integer
         int sum = 0, temp = num;
         while (temp != 0){
             int rem = temp % 10;
             sum += rem * rem * rem;
             temp /= 10;
         }
         if (num != sum){
             flag = 0;
         }
*/
