#include <iostream>
#include <thread>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8086
#define BUFFER_SIZE 1024

int sockfd;

void receiveMessages()
{
    char buffer[BUFFER_SIZE];

    while(true)
    {
        int bytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);

        if(bytes <= 0)
        {
            std::cout << "Server disconnected\n";
            break;
        }

        buffer[bytes] = '\0';
        std::cout << "\nServer: " << buffer << std::endl;
    }
}

void sendMessages()
{
    std::string message;

    while(true)
    {
        std::getline(std::cin, message);

        if(message == "exit")
        {
            close(sockfd);
            exit(0);
        }

        send(sockfd, message.c_str(), message.length(), 0);
    }
}

int main()
{
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        std::cout << "Socket creation failed\n";
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    if(connect(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        std::cout << "Connection failed\n";
        return -1;
    }

    std::cout << "Connected to server\n";
    std::cout << "Type messages (type 'exit' to quit)\n";

    std::thread recvThread(receiveMessages);
    std::thread sendThread(sendMessages);

    recvThread.join();
    sendThread.join();

    close(sockfd);

    return 0;
}