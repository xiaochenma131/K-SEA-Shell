# Assignment 7

## Files included:
* stack.c
* stack.h
* queue.c
* queue.h
* tree.c
* tree.h
* files.c
* Makefile
* README.md

## How to run the program:
To run the program, you can directly type in ```make all``` to make the a.out file, then use ```make run``` to run. The program will print out a directory tree showing the files under the current directory. For me, I wrote the code in order to print out the files under the a7 folder. If you want to print out the files under another directory, you may need to change the ```path``` and ```name``` variables in the main function in files.c.(on line 12 and line 13 in files.c)   

### Example Input and Output:
* INPUT: ```make run```
* OUTPUT: 
```
 --a7
  --tree.h~
  --tree.h.gch
  --tree.h
  --tree.c~
  --tree.c
  --testfolder2
    --testfolder3
      --testfile
    --file2
    --file1
  --testfolder1
    --Hello
    --3
    --2
    --1
  --stack.h~
  --stack.h.gch
  --stack.h
  --stack.c~
  --stack.c
  --queue.h~
  --queue.h.gch
  --queue.h
  --queue.c~
  --queue.c
  --files.c~
  --files.c
  --a.out
  --README.md
  --Makefile~
  --Makefile
  --#files.c#
  ```
  In order to check the program runs correctly, I created the testfolder1, testfolder2 under the a7 folder and created testfolder3 under the testfolder2. The program printed out the directory correctly.
  
  ## How long did it take?
  8 hours.
