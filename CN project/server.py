import socket
import threading
#import tkinter as tk
#from tkinter import scrolledtext
#from tkinter import messagebox
#from googletrans import Translator
HOST='127.0.0.1'
PORT=1234 #use any port b/w 0-65535
LISTENER_LIMIT=5
active_clients=[]#list of all connected users
#translator=Translator()
from translate import Translator
#translator= Translator(to_lang="English")

#func to listen for upcoming msg from client
def listen_for_messages(client,username):
    while(1):
        message=client.recv(2048).decode('utf-8')
        #message=client.recv(2048)
        #result=translator.translate(message,src='kn',dest='en')
        #print(result.text)
        if message !='':
            #translation = translator.translate(message)
            print (message)
            #tm=translator.translate(message.decode()).text
            final_msg=username+'~'+message
            
            #client.sendall(translation.encode())
            #send msg to all clients
            #send_messages_to_all(final_msg)
            send_messages_to_all(final_msg)

        else:
            print(f'msg sent from client{username} is empty')

#fun to send msg to client serially which r there in a list
def send_message_to_client(client,message):
    client.sendall(message.encode())

#server sends msg to all clients
def send_messages_to_all(message):
    for user in active_clients:
        send_message_to_client(user[1],message)

#func to handle client
def client_handler(client):
    #server will listen for client msg that contains username
    while(1):
        username=client.recv(2048).decode('utf-8')#2048-ms size
        if username !='':
            active_clients.append((username,client))
            break
        else:
            print('client is empty')
    threading.Thread(target=listen_for_messages,args=(client,username)).start()
def main():
    #'AF-NET:using IPV4 '
    server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    print(f"running server on {HOST} {PORT}")
    try:
        server.bind((HOST,PORT))
    except:
        print(f'unable to bind to host{HOST} and port{PORT}')

    #set server limit
    server.listen(LISTENER_LIMIT)

    while(1):
        client,address=server.accept()
        print(f'successfully connected to client{address[0]} {address[1]}')
        threading.Thread(target=client_handler,args=(client,)).start() #start- tostart thread
if __name__=='__main__':
    main()