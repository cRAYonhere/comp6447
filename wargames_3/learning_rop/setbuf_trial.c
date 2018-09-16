#include <stdio.h>

int main () {
   char bufffy[1024];
   char buf2[8]="\x61\x61\x61\x61\x61\x61";
   setbuf(stdout, bufffy);
   puts(buf2);
   puts(bufffy);
   fflush(stdout);
   return(0);
}
//edx 0xffffcb60
//eax 0xf7f9ed80
