# UDP-Client_Server-ReverseMessage-Chatbot
This application implements a UDP-based chatbot in C language, where the server reverses the message sent by the client. The chatbot allows for communication between a client and server using UDP sockets.

**Instructions to Run:**

Compilation:
Open a terminal or command prompt.
Navigate to the directory containing the source code files.
Compile the server.c file using the following command:
**gcc server.c -o server**

Compile the client.c file using the following command:
**gcc client.c -o client**

Running the Server:
In the terminal or command prompt, run the server executable using the following command:
**./server**
The server will start and bind to a specific port.

Running the Client:
In a separate terminal or command prompt, run the client executable using the following command:
**./client**

The client will prompt you to enter a message.
Type a message and press Enter to send it to the server.
The server will reverse the message and send it back to the client.
Repeat the process to continue the conversation.

**Notes:**
Ensure that both the server and client are running simultaneously for proper communication.
You can modify the server's logic in server.c to implement different functionalities.
It is recommended to test the chatbot on the same machine or within a local network for simplicity.
