#!/bin/bash

echo "ecnrypting and decrypting txt"
openssl enc -bf-cbc -e -in text.md -out encrTxt.md  -K 1234 -iv 1234
openssl enc -bf-cbc -d -in encrTxt.md -out orTxt.md -K 1234 -iv 1234

sleep 1s

echo "ecnrypting and decrypting img"
openssl enc -bf-cbc -e -in fl2.jpg -out encrImg  -K 1234 -iv 1234
openssl enc -bf-cbc -d -in encrImg -out image.jpg -K 1234 -iv 1234

