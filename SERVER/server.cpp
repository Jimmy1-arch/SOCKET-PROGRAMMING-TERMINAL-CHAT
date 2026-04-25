#include <iostream>
#include <thread>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8086
#define BUFFER_SIZE 1024

int clientSocket;

void receiveMessages()
{
    char buffer[BUFFER_SIZE];

    while(true)
    {
        int bytes = recv(clientSocket, buffer, BUFFER_SIZE - 1, 0);

        if(bytes <= 0)
        {
            std::cout << "Client disconnected\n";
            break;
        }

        buffer[bytes] = '\0';
        std::cout << "\nClient: " << buffer << std::endl;
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
            close(clientSocket);
            exit(0);
        }

        send(clientSocket, message.c_str(), message.length(), 0);
    }
}

int main()
{
    int serverFd;
    struct sockaddr_in serverAddr, clientAddr;

    serverFd = socket(AF_INET, SOCK_STREAM, 0);

    if(serverFd < 0)
    {
        std::cout << "Socket creation failed\n";
        return -1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverFd, (sockaddr*)&serverAddr, sizeof(serverAddr));

    listen(serverFd, 5);

    std::cout << "Server listening on port " << PORT << std::endl;

    socklen_t addrSize = sizeof(clientAddr);

    clientSocket = accept(serverFd, (sockaddr*)&clientAddr, &addrSize);

    std::cout << "Client connected\n";

    std::thread recvThread(receiveMessages);
    std::thread sendThread(sendMessages);

    recvThread.join();
    sendThread.join();

    close(serverFd);

    return 0;
}