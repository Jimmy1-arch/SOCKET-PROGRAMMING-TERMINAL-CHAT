# SOCKET-PROGRAMMING TERMINAL CHAT

A terminal-based chat application built using socket programming in C++, enabling real-time client-server communication over TCP/IP networks. This project demonstrates low-level networking concepts such as socket creation, connection handling, and real-time data transmission.

## FEATURES
- Real-time messaging using TCP/IP sockets  
- Client-server architecture  
- Bidirectional communication  
- Lightweight terminal-based interface  
- Low-latency communication  

## ARCHITECTURE
Client ↔ Server ↔ Client  

- Server listens for incoming connections  
- Clients connect using IP and port  
- Messages are exchanged using TCP protocol  

## TECH STACK
- C++  
- TCP/IP Socket Programming  
- Linux / Unix Environment  

## PROJECT STRUCTURE

CLIENT/
├── client.cpp

SERVER/
├── server.cpp

## ⚙️ COMPILE & RUN

### Compile
```bash
g++ CLIENT/client.cpp -o CLIENT/client
g++ SERVER/server.cpp -o SERVER/server
```
Run
./SERVER/server
./CLIENT/client

##CORE CODE
Server Setup
```bash
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in address;
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(PORT);

bind(server_fd, (struct sockaddr*)&address, sizeof(address));
listen(server_fd, 3);
Accept Connection
int addrlen = sizeof(address);
int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
Client Connection
int sock = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in serv_addr;
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);

inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
Send & Receive
send(sock, message, strlen(message), 0);
read(sock, buffer, 1024);
```
##WORKFLOW
- Server starts and listens on a port
- Client connects using IP and port
- Messages are exchanged via TCP sockets
- Real-time communication continues

##FUTURE IMPROVEMENTS
- Multi-client support using threading
- Secure communication (encryption)
- GUI-based chat interface
- File transfer capability
