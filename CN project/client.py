import socket
import threading
import tkinter as tk
#from googletrans import Translator,constants
from tkinter import scrolledtext
from tkinter import messagebox
HOST='127.0.0.1'
PORT=1234
#translator=Translator()
from translate import Translator
#translator= Translator(to_lang="French")


#client to listen to server msg
def listen_for_messages_from_server(client,lang):
    while(1):
        message=client.recv(2048).decode('utf-8')
        if message!='':
            username=message.split("~")[0]
            content=message.split("~")[1]
            translator= Translator(to_lang=lang)
            translationreceived = translator.translate(content)
            #content=translator.translate(content,src='en',dest='kn')
            print(f"[{username}]{translationreceived}")
        else:
            print('message recieved from client os empty')

def send_message_to_server(client,lang):
    while(1):
        message=input("Msg:")
        
        #m=message
        if(message!='\n'):
            #result=translator.translate("Hello",src='en',dest='fr')
            #print(f'{result.text}')
            
            #result=translator.translate('ಕನ್ನಡ',dest='en').text
            #print(result)
            
            translator1= Translator(to_lang="English",from_lang=lang)
            translation = translator1.translate(message)
            
            client.sendall(translation.encode())
        else:
            print('empty message')
            exit(0)

def communicate_to_server(client):
    username=input('enter username')
    lang=input("Enter Language")
    if username!='':
        client.sendall(username.encode())
    else:
        print('username cant be empty')
        exit(0)
    threading.Thread(target=listen_for_messages_from_server,args=(client,lang)).start()
    send_message_to_server(client,lang)
def main():
    client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    #connect ro server
    try:
        client.connect((HOST,PORT))
        print('successfully connected to server')
    except:
        print(f'unable to bind to host{HOST} and port{PORT}')
    
    communicate_to_server(client)

if __name__=='__main__':
    main()