#!usr/bin/env python
import sys, socket

# input
host = sys.argv[1]
# lookup
name = socket.gethostbyname(host)
# output
print(name)

