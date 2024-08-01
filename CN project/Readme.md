## Multi Lingual User Chat Room Application using TCP Socket Programming

A multi-user chat room application, where each user can communicate to every other user in the chat room in their desired language.

## Working

1) The client is assigned a new user_id when they join the chat and specify the language in which they will communicate in the chat.
2) The client sends their message to all other clients in the chat in their specified language via the server.
3) The server translates the messages exchanged between clients into English and displays them to acknowledge the messages shared by each client.
4) The server translates the messages from "English" to respective language of other clients.
5) A client thread is created for every client  to exchange messages.
6) A server thread is created to handle all client messages.
   
## Project Structure

- **client.py**: contains client side script that sends client messages to server and recieves server mesages.Exchange of messages is handled via threading.

- **server.py**: contains server side scipt that translates client messages it recived to "English" and translates it to the respective language of other clients in the chatroom.Exchange of messages is handled via threading.

## Tech Stack Used
1. **Python**: The primary programming language for both client and server scripts.
2. **Socket Programming**: Used for establishing and handling communication between the server and multiple clients.
3. **Threading**: Used to handle multiple clients simultaneously by running separate threads for listening and sending messages.
4. **Translation Module**:
   - **translate**: A library used to translate messages to and from English to the user's preferred language.

## Note
- This translation works only for very short words and for some specific languages like French, English, German .
- The translation works only for short phrases like "Good morning","How are you" etc..., it doesn't work for long sentences.
- This project focuses on facilitating multilingual communication rather than performing precise language translation, therefore we do not have specific accuracy metrics or performance benchmarks related to translation quality.

## Future Enhancements
Work on precision of language translation.
