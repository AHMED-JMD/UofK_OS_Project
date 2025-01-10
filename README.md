# UofK_OS_Project

## Inter Proccess Communication Using Signals

### Members in the Project

- Ahmed abd alrahman Altayeb
- Ahmed Hussein AbuHamad
- Ahmed Salah Haj Hamad
- Abdulrahman Abdalaziz Hassan

### Excersie (1)

### Exercise (2)

### Excersice (3)

The program calculates the time difference between now and the alarm time.
It sets a timeout for the alarm.
When the alarm triggers, it prompts the user to stop or snooze.
If the user chooses to snooze, it resets the alarm based on the provided time or defaults to 1 minute.

#### used the help of chatgpt to develop the code

Key Features:

- Input Parsing:
  Accepts HH:MM for time and optional YYYY-MM-DD for date.
- Validation:
  Ensures the given time is in the future.
- Signal Handling:
  Uses a minimal SIGALRM handler to set a flag.
- Users Action:
  Prompts the user to stop or snooze the alarm.
  Resets the alarm based on user input.
- Default Snooze:
  Defaults to 2 minute if no snooze time is entered
