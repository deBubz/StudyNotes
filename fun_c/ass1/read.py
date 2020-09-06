file = open("database_sol", "rb")

byte = file.read(1)

while byte:
    print(byte)
    byte = file.read(1)


file.close()