/*
Coded By Ryan Boudreaux
This code demonstrates the use
of the 'fork()' function.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

        pid_t pid = fork();
        if(pid < 0) printf("Creation failed\n");
        else if(pid == 0) printf("Child process created\n");
        else printf("This is the parent process\n");
        return 0;
}
