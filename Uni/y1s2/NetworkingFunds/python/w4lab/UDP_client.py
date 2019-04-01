# py UDP client
# push send input to UDp server to be converted
# from socket import *
from socket import *
import sys

sName = '172.19.147.184'
sPort = 12001
clSocket = socket(AF_INET, SOCK_DGRAM)
msg = input('input lowercase txt: ')

clSocket.sendto(msg.encode(), (sName, sPort))
moddedMsg, sAddr = clSocket.recvfrom(2048) 
print(moddedMsg.decode()) # Error here, server not working atm
clSocket.close() 