#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
        // need a command to run
        if (argc <= 1) return 1;

        // fork to disown the child
        pid_t child;
        if (child = fork())
        {
                if (child == -1)
                {
                        perror("fork");
                        return 1;
                }

                printf("%ld\n", (long)child);
                return 0;
        }

        // silence output
        if (!freopen("/dev/null", "w", stdout)) fprintf(stdout, "Failed to silence stdout\n");
        if (!freopen("/dev/null", "w", stderr)) fprintf(stderr, "Failed to silence stderr\n");

        // run the command
        execvp(argv[1], argv + 1);

        // if execvp returns, it's an error
        if (freopen("/dev/tty", "w", stderr)) perror(argv[0]);

        return 1;
}
 