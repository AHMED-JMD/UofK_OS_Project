#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define TEMP_FILE "compfile"

// Signal handler for SIGINT (Ctrl-C)
void handle_sigint(int sig)
{
    // Attempt to delete the temporary file
    if (remove(TEMP_FILE) == 0)
    {
        printf("\nSuccessfully deleted temporary file\n");
    }
    else
    {
        perror("Error deleting temporary file");
    }
    exit(0); // Terminate the program
}

int main()
{
    // Set up the signal handler for SIGINT
    if (signal(SIGINT, handle_sigint) == SIG_ERR)
    {
        perror("Error setting signal handler");
        return EXIT_FAILURE;
    }

    // Create and write to the temporary file
    FILE *file = fopen(TEMP_FILE, "w");
    if (!file)
    {
        perror("Error creating file");
        return EXIT_FAILURE;
    }
    fprintf(file, "This is a temporary file created by the compiler.\n");
    fclose(file);
    printf("Temporary file '%s' created and written to successfully.\n", TEMP_FILE);

    // Infinite loop to simulate work
    printf("Compiler simulation running... Press Ctrl-C to terminate.\n");
    while (1)
    {
        sleep(1); // Simulate work with a delay
    }

    return 0;
}
