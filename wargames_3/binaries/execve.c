#include <unistd.h>
int main() {
       	char *args[1];
       	args[0] = "/bin/sh";
        //args[1] = NULL;
	//char args[10]="/bin/sh";        
	execve(args[0], NULL, NULL);
}
