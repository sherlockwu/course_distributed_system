#!/usr/bin/env python
# import
from SimpleXMLRPCServer import SimpleXMLRPCServer

# new server
s = SimpleXMLRPCServer(("", 4242))

# procedure
def mult(input_a, input_b):
    return (input_a * input_b)

# register procedure
s.register_function(mult)

# start server
s.serve_forever()
