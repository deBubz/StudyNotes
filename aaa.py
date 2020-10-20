import random as rand

input = list(input("Enter String: ").lower())

for i in range(len(input)):
    input = (input[i].upper(), input[i].lower())[rand.randint(0, 1)]
print(out)