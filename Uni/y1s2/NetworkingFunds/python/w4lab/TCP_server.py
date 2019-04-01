from socket import *

print('lmao')
sPort = 12001
sSocket = socket(AF_INET, SOCK_STREAM)

sSocket.bind(('172.19.147.184', sPort))
sSocket.listen(1)

print('TCP is up Boye')

while True:
    conSocket, addr = sSocket.accept()
    sentence = conSocket.recv(1024).decode().upper()
    conSocket.send(sentence.encode())
    conSocket.close()