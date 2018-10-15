#	for (; i < l; ++i) {
#		buf[i] = str[i] ^ (0x20 + i);
#	}


import sys

a = sys.argv[1]
a += "\n"
i = 0
buf = ""
for c in a:
	buf += chr(ord(c) ^ (0x25 + i))
	i += 1

print str(buf)
print repr(buf)

sys.stdout.write('"')
for c in buf:
	sys.stdout.write("\\x%02x" % ord(c))
print('"')