#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

// Empty handler that just returns
void sigint_handler(int sig) {
    return;
}

int main() {
    sigset_t block_set, pending_set;
    struct sigaction sa; // sa stands for sigaction
    // signal sets
    sigfillset(&block_set);
    sigdelset(&block_set, SIGINT);
    sigprocmask(&block_set, NULL);

    //Blocks all signals except SIGINT using sigprocmask()
        sigfillset(&block_set);
        sigdelset(&block_set, SIGINT);
        if (sigprocmask(&block_set, NULL) == -1) {
            return 1;
    }
    printf("process ID: %d\n", getpid()); 
    printf("Waiting for signals... (Press Ctrl-C to continue)\n");

    // calls pause to wait for a signal
    pause();


    // After pause returns 


    // Get pending signals using sigpending()
    sigpending(&pending_set);
    // Check and print pending signals
    printf("\nPending signals:\n");
    
    for (int sig = 1; sig < NSIG; sig++) //NSIG stands for number of signals in the system
    {
        if (sigismember(&pending_set, sig)) {
            printf("Signal %d: %s\n", sig, strsignal(sig)); // Print the pending signals
        }
    }
    return 0;
}