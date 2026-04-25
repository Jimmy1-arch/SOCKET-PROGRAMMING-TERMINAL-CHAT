# 💬 SOCKET-PROGRAMMING TERMINAL CHAT

A terminal-based chat application built using socket programming in C++, enabling real-time client-server communication over TCP/IP networks. This project demonstrates low-level network programming concepts including socket creation, connection handling, and real-time data transmission.

---

## 🚀 FEATURES

- 📡 Real-time communication using TCP/IP sockets  
- 💻 Client-server architecture  
- ⚡ Low-latency message exchange  
- 🔄 Bidirectional communication  
- 🖥 Lightweight terminal interface  
- 🧠 Hands-on implementation of networking concepts  

---

## 🧠 SYSTEM ARCHITECTURE

Client ↔ Server ↔ Client  

- **Server:** Listens for incoming connections and manages communication  
- **Client:** Connects to server and sends/receives messages  
- **Socket Layer:** Handles TCP/IP communication  

---

## 🛠 TECH STACK

- C++  
- Socket Programming (TCP/IP)  
- Linux / Unix Environment  

---

## 📂 PROJECT STRUCTURE


CLIENT/
├── client.cpp
├── client

SERVER/
├── server.cpp
├── server


---

## ⚙️ INSTALLATION

### Clone the repository
```bash
git clone https://github.com/your-username/socket-chat.git
cd socket-chat
Compile the code
g++ CLIENT/client.cpp -o CLIENT/client
g++ SERVER/server.cpp -o SERVER/server
▶️ RUN THE PROJECT
Step 1: Start Server
./SERVER/server
Step 2: Start Client
./CLIENT/client
💻 CORE CODE IMPLEMENTATION
🔹 Server Socket Setup
int server_fd = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in address;
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(PORT);

bind(server_fd, (struct sockaddr*)&address, sizeof(address));
listen(server_fd, 3);
🔹 Accept Client Connection
int addrlen = sizeof(address);
int new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
🔹 Client Connection Setup
int sock = socket(AF_INET, SOCK_STREAM, 0);

struct sockaddr_in serv_addr;
serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);

inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
🔹 Send and Receive Messages
send(sock, message, strlen(message), 0);
read(sock, buffer, 1024);
📡 WORKFLOW
Server initializes socket and starts listening
Client connects using IP and port
Messages are transmitted using TCP protocol
Server receives and responds to messages
Communication continues in real-time
🧪 SAMPLE OUTPUT
Client: Hello
Server: Hello from server
Client: How are you?
Server: Connection active
