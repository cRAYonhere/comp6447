#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void not_called() {
    printf("Enjoy your shell!\n");
    system("/bin/bash");
}

void vulnerable_function(char* string) {
    char buffer[100];
    printf("%s\n",string);
    strcpy(buffer, string);
}

int main(int argc, char** argv) {
    char buffer[100];
    printf("Feed Me:");
    scanf("%s",buffer);
    vulnerable_function(buffer);
    return 0;
}
