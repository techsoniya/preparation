#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    int status;
    pid=fork();
    if(pid<0)
    {
        printf("error: fork() failed ");
        return 1;
    }
    else if(pid==0)
    {
        printf("child process executed with pid : %d \n",getpid());
        printf("parent process executed with pid : %d \n",getpid());
        execlp("/bin/ls","ls",NULL);
        printf("This will not be printed if exec is executed");
        return 0;
        
    }
    else
    {
        printf("parent process executed with pid : %d \n ",getpid());
        printf("child process executed with pid : %d \n",getpid());
        wait(&status);
        printf("Child process executed with status : %d \n",status);
        return 0;
    }
   
}