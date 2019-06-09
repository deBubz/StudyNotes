from socket import *

print('lmao')
sPort = 12001
sSocket = socket(AF_INET, SOCK_STREAM)

sSocket.bind(('127.0.0.1', sPort))
sSocket.listen(1)

print('TCP is up Boye')

while True:
    conSocket, addr = sSocket.accept()
    sentence = conSocket.recv(1024).decode().upper()
    conSocket.send(sentence.encode())
    conSocket.close()
