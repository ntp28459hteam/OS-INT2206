#include <sys/types.h>
#include <sys/wait.h> // for using wait() system call
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // for using exit() system call

int main()
{
    pid_t pid;
    int i;
    for(i = 0; i < 16; i++)
    {
        //fork a child process
        pid = fork();
        if(pid == 0)
        {
            fprintf(stdout, "fork() system call returned pid = 0, a child process with unknown pid is running\n");
        }
        if(pid > 0)
        {
            fprintf(stdout, "Parent process is running, a new process created with pid %d\n", pid);
        }
        if (pid < 0)
        {
            fprintf(stderr, "Fork failed");
            exit(-1);
        }
        else if (pid == 0)
        {
            fprintf(stdout, "ahihi");
            execlp("/bin/ls", "ls", NULL);
            fprintf(stdout, "Child process terminate normally");
        }
        else
        {
            int pid_wait = wait(NULL);
            fprintf(stdout, "Child process with pid %d complete, now return t\
o parent\n\n", pid_wait);
        }
    }
    fprintf(stdout, "---------------\nParent complete\n");
    exit(0);
}
