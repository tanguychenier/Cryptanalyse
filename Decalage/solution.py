# Rootme Challenge 7 : T. chenier

data = open('ch7.bin', 'rb').read()
out = ''
for d in data:
	out += chr(ord(d)-10)
print out
