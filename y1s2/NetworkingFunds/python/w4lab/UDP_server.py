# py UDP server 
# to convert msg from client to uppercase then return message
from socket import *
import sys

print("lmao")
sPort = 12001
s = socket(AF_INET, SOCK_DGRAM)
print("something is happening")

s.bind(('172.19.147.184', sPort)) # Something is happening here
print("server iz up boye")

while True:
    print("wtf is happening")
    message , clAddress = s.recvfrom(2048)
    print("the message is " + message.decode())
    moddedMsg = message.decode().upper()
    s.sendto(moddedMsg.encode(), clAddress)