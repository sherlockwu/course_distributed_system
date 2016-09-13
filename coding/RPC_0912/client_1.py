#!usr/bin/env python
import sys
# import package
from xmlrpclib import ServerProxy
s= ServerProxy("http://localhost:4242")

# call RPC
a = int(sys.argv[1])
b = int(sys.argv[2])
rs = s.mult(a, b)

# Print
print(rs)
