# Assignment 9: K-SEA Shell
## Name: 
* Xiaochen Ma
## How many hours did it take you to complete this homework?
* 4hours
## Did you collaborate with others?
* No
## Did you use any external resources?
* No
## Added Command: game
* Synopsis: This command will play a guessing game with the user.
* Description: When the program receives the "game" command from the user, it will ask the user to guess a number between 1 and 100. If the input number is smaller than the target number, the shell will ask the user to guess a higher number. Otherwise, it will ask the user to guess a smaller number. This process will keep running until the user guess the target number or the user guess too many times.
* Notes: I implement the "game" command by first generate a random number between 1 and 100 as the target number of this guessing game. Then the function will ask for a guessing number from the user and evaluate it by comparing the input number with the target number. The function will print out a message to prompt the user. This process will be repeated unti th user gets the target number or the user guess morn than 10 times. 
## Example input and output:
```
k-sea-shell> helper
The following commands are built in:
cd
helper
exit
game
```
```
k-sea-shell> game
Guess a number between 1 and 100
67
Higher number please!
90
Lower number please!
80
Higher number please!
83
You guessed the number in 3 attemps!
```
```
k-sea-shell> /bin/ls
README.md  a.out  shell.c

k-sea-shell> /bin/pwd
/home/xiaochenma1996/xiaochenma1996_CS5008/a9

k-sea-shell> cd ../

k-sea-shell> /bin/pwd
/home/xiaochenma1996/xiaochenma1996_CS5008
```
```
k-sea-shell> ./a.out

k-sea-shell> exit

k-sea-shell> exit
```
