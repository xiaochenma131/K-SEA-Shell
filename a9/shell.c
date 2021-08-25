#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#define MAXARGS 2
#define MAXLINE 80
void k_sea_cd(char** argv);
void k_sea_helper(char** argv);
void k_sea_exit(char** argv);
void k_sea_game(char** argv);

char* builtin_commands[4] = {"cd", "helper", "exit", "game"};
void (*builtin_func[]) (char**) =
{&k_sea_cd, &k_sea_helper, &k_sea_exit, &k_sea_game};
// ===============================
// Helper Functions
// ===============================

void k_sea_cd(char** argv) {
  if (argv[1] == NULL) {
    fprintf(stderr, "k-sea-shell> expected argument to \"cd\"\n");
  } else {
    if (chdir(argv[1]) != 0) {
      perror("k-sea-shell>\n");
    }
  }
}

void k_sea_helper(char** argv) {
  int i;
  printf("The following commands are built in: \n");
  for (i = 0; i < 4; i++) {
    printf("%s\n", builtin_commands[i]);
  }
}

void k_sea_exit(char** argv) {
  exit(0);
}

void k_sea_game(char** argv) {
  int number;
  int guess;
  int numberofguess = 0;
  number = rand() % 100;
  printf("Guess a number between 1 and 100\n");
  do {
    if (numberofguess > 9) {
      printf("\nYou Loose!\n");
      break;
    }
    scanf("%d", &guess);
    if (guess > number) {
      printf("Lower number please! \n");
      numberofguess++;
    } else if (number > guess) {
      printf("Higher number please! \n");
      numberofguess++;
    } else {
      printf("You guessed the number in %d attemps!\n", numberofguess);
    }} while (guess != number);
}

// calling fork(), but also checking for any errors, and just returning the pid.
pid_t Fork(void) {
  pid_t pid;
  if ((pid = fork()) < 0) {
    fprintf(stderr, "%s: %s\n", "fork error", strerror(errno));
    exit(0);
  }
  return pid;
}

// read n chars from FILE into ptr.
char* Fgets(char* ptr, int n, FILE* stream) {
  char* rptr;
  if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream)) {
    fprintf(stderr, "%s\n", "fgets error");
    exit(0);
  }
  return rptr;
}

// Is the command one built into the shell?
// That is, that the *shell* has implemented?
// If so, call it here
// argv is an array of strings
int IsBuiltinCommand(char** argv) {
  // Step3: Determine if it is a builtin command
  // Loop through the list of commands to see if it's "built in"
  // by using strcmp
  int i;
  for (i = 0; i < 4; i++) {
    int res = strcmp(builtin_commands[i], argv[0]);
    if (res == 0) {
      (*builtin_func[i])(argv);
      return 1;
    }
  }
  return 0;
}

// Eval takes in the input from the user, parses it, and does something.
void Eval(char* cmdline) {
  // Args to pass to execve()
  // (think of it as an array of strings)
  char* argv[MAXARGS];

  // Modified command line
  char buf[MAXLINE];

  // Keep track of the child pid
  pid_t pid;

  // Copy into 'buf' so we can do something with it
  strcpy(buf, cmdline);

  // Step 2: Parse but into command line arguments.
  // (put the command/args into argv)
  // Make sure the element after the last argument is NULL
  const char* delim = " ";
  char* rest = &buf[0];
  char* token = strtok_r(rest, delim, &rest);
  int i = 0;
  while (token != NULL) {
    argv[i] = token;
    i++;
    token = strtok_r(rest, delim, &rest);
  }
  argv[i] = NULL;
  // Ignore empty lines
  if (argv[0] == NULL) {
    return;
  }

  if (IsBuiltinCommand(argv) == 0) {
    // Step 4:
    // Check that the command/program exists in Unix(ie/bin/) or (see below)
    // Create a child process
    // Run the program/command (execve...)
    // -- what is the result of exec if the command is bogus?
    int res;
    if (Fork() == 0) {
      res =  execve(argv[0],argv, NULL);
     // Some form of: execve(argv);
      if (res < 0) {
        // print error message
        printf("k-sea-shell>Command not found--Did you mean something else?\n");
        exit(0);
      }
      // exit(0);
    }else {
      wait(NULL);
    }
  // Step 5: Parent waits for foreground job (child process) to terminate
  }
}

//Ignore this.
void handle_sigint(int signal) {
  exit(0);
}

int main() {
  signal(SIGINT, handle_sigint); // ignore this line.
  char cmdline[MAXLINE];

  // Infinite loop, reading from user
  while (1) {
    // Step 1: wrtie the code to read user input into cmdline
    printf("\nk-sea-shell> ");
    Fgets(cmdline, MAXLINE,stdin);
    if ((strlen(cmdline) > 0) && (cmdline[strlen(cmdline) - 1] == '\n')) {
      cmdline[strlen(cmdline) - 1] = '\0';
      Eval(cmdline);
    }
  }
  return 0;
}
