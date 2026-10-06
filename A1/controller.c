#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Not enought arguments!");
        return 1;
    }

    if (strcmp(argv[1], argv[2]) == 0)
    {
        printf("You have entered the same file twice...");
        exit(0);
    }

    int pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // This block runs in the child process
        printf("Hello from the child process! PID: %d\n", getpid());
    }
    else
    {
        // This block runs in the parent process
        printf("Hello from the parent process! Child PID is: %d\n", pid);
    }

    return 0;
}