#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

volatile sig_atomic_t alarm_triggered = 0; // Flag to indicate alarm signal

// Signal handler
void alarm_handler(int sig)
{
    (void)sig; // Silence unused parameter warning
    alarm_triggered = 1;
}

// Validate if the provided time is in the future
int validate_time(struct tm *input_time)
{
    time_t current_time = time(NULL);
    time_t input_epoch = mktime(input_time);
    return input_epoch > current_time;
}

// Parse date and time from command-line arguments
void parse_datetime(int argc, char *argv[], struct tm *input_time)
{
    time_t now = time(NULL);
    *input_time = *localtime(&now);

    if (argc >= 2)
    { // Parse time
        if (sscanf(argv[1], "%2d:%2d", &input_time->tm_hour, &input_time->tm_min) != 2)
        {
            fprintf(stderr, "Invalid time format. Use HH:MM.\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Time argument is required. Use HH:MM.\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 3)
    { // Parse date
        if (sscanf(argv[2], "%d-%d-%d", &input_time->tm_year, &input_time->tm_mon, &input_time->tm_mday) != 3)
        {
            fprintf(stderr, "Invalid date format. Use YYYY-MM-DD.\n");
            exit(EXIT_FAILURE);
        }
        input_time->tm_year -= 1900; // Adjust year
        input_time->tm_mon -= 1;     // Adjust month
    }
}

void prompt_snooze(int *snooze_time)
{
    printf("Do you want to stop or snooze the alarm? (stop/snooze): ");
    char choice[10];
    if (scanf("%9s", choice) != 1 || strcmp(choice, "stop") == 0)
    {
        printf("Alarm stopped. Goodbye!\n");
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(choice, "snooze") == 0)
    {
        printf("Enter snooze time in minutes (default 1 minute): ");
        if (scanf("%d", snooze_time) != 1)
        {
            *snooze_time = 1; // Default snooze time
        }
    }
    else
    {
        fprintf(stderr, "Invalid choice. Exiting.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    struct tm alarm_time;
    parse_datetime(argc, argv, &alarm_time);

    if (!validate_time(&alarm_time))
    {
        fprintf(stderr, "Invalid time. Alarm time must be in the future.\n");
        exit(EXIT_FAILURE);
    }

    time_t alarm_epoch = mktime(&alarm_time);
    time_t now = time(NULL);
    int sleep_seconds = (int)difftime(alarm_epoch, now);

    signal(SIGALRM, alarm_handler);
    alarm(sleep_seconds);

    printf("Alarm set for %s", asctime(&alarm_time));

    while (1)
    {
        if (alarm_triggered)
        {
            alarm_triggered = 0; // Reset the flag
            printf("\nALARM! Current time: %s", asctime(localtime(&now)));

            int snooze_time = 2; // Default snooze time
            prompt_snooze(&snooze_time);

            now = time(NULL);
            alarm(now + snooze_time * 60);
        }
        sleep(1); // Prevent busy waiting
    }

    return 0;
}
.