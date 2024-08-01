## Multi Lingual User Chat Room Application using TCP Socket Programming

A multi-user chat room application, where each user can communicate to every other user in the chat room in their desired language.

## Working
1) The client is assigned a new user_id when they join the chat and specify the language in which they will communicate in the chat.
2) 
## Project Structure
-**client.py**: contains client side script that sends client messages to server and recieves server mesages.Each client can send message to another client in the chatroom in their desired language . Each clinet can see the messages shred across all clients using threads.
-**server.py**: contains server side scipt that translates client messages it recived to "English" and translates it from "English" to the desired language of another client in the chatroom.

## Note
- This translation works only for very short words and for some specific languages like French, English, German ,Kannada
- The translation is not completely accurate as is works only for short phrases like "Good morning","How are you" etc..., doesn't work for long sentences.
