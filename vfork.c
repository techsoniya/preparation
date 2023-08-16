#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
    pid_t pid;
    pid=vfork();
    if(pid==-1)
    {
        perror("vfork()");
        return 0;
    }
    else if(pid==0)
    {
        //child processs
        printf("Child process :This is the child process \n");
        printf("Child process :child process exceuted with pid %d\n",getpid());
        printf("Child process :parent process exceuted with pid %d\n",getpid());
        _exit(0);
    }
    else{
        //parent processs
        printf("parent process :This is the child process \n");
        printf("parent process :parent process exceuted with pid %d\n",getpid());
        printf("parent process :child process exceuted with pid %d\n",pid);
        int status;
        waitpid(pid,&status,0);
        if(WIFEXITED(status))
        {
            printf("parents and child process executed normally");
        }
        else{
            printf("parents and child process executed abnormally");
        }


    }
    return 0;
}