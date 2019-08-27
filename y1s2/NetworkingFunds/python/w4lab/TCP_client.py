from socket import *
sName = '172.19.147.184'
sPort = 12001

clSocket = socket(AF_INET, SOCK_STREAM)
clSocket.connect((sName,sPort))
sentence = input("input sometext: ")

clSocket.send(sentence.encode())
moddedSentence = clSocket.recv(1024)

print('From Server: ', moddedSentence.decode())
clSocket.close()