# Assignment 6: Finding Anagrams with Hashtables


## Included files: 

* ```words.txt```: The word file to read in to find anagrams with. 
* ```Hashtable_easy.h```: The header file for the hashtable that contains APIs for a Hashtable that holds linkedlist of linkedlist that holds strings. 
* ```Hashtable.c```: Contains hashtable code, contains FNV Hash function and SortWord function. 
* ```LinkedList_easy.h```: Contains API for a LinkedList that holds strings. 
* ```LinkedList_easy.c```: Constains LinkedList code. 
* ```Makefile```: The Makefile that can build all, make run, make test and make clean.
* ```test_example1.cc```: The test file to test my LinkedList and hashtable implementation.
* ```main.c```: Contains the main function which reads word from the txt file, sorts the word and uses the sorted word as the key value and put the key-value pair into the hashtable. Finally, print the anagrams out.
* ```Assert007.h & Assert007.c```: Assert files for testing.

## How to build and run the codes:

* First, run ```make all``` to build the test_suite file testing and compile the a.out file of the program.
* To run the finding anagram program, you can use```make run``` to run the a.out file. The anagrams will be printed out directly (takes some time).
* To run test, you can use ```make test```. The test result will be shown directly.
* To delete the compiled file, you can use ```make clean``` to delete. 

## Example INPUT and OUTPUT:

* Input: ```make run```
* Part of the output: 
```
acidimetries
sapinda anaspid anapsid
beefer
teaching cheating
coplotter
cyclopedic
partedness depressant
```
* Input: ```make test```
* Output:
```
./test_suite
[==========] Running 6 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from TestLinkedList
[ RUN      ] TestLinkedList.CreateLinkedListNode
[       OK ] TestLinkedList.CreateLinkedListNode (0 ms)
[ RUN      ] TestLinkedList.CreateLinkedList
[       OK ] TestLinkedList.CreateLinkedList (0 ms)
[ RUN      ] TestLinkedList.InsertLinkedList
[       OK ] TestLinkedList.InsertLinkedList (0 ms)
[----------] 3 tests from TestLinkedList (0 ms total)

[----------] 3 tests from TestHashtable
[ RUN      ] TestHashtable.CreateHashtable
[       OK ] TestHashtable.CreateHashtable (0 ms)
[ RUN      ] TestHashtable.SortWord
[       OK ] TestHashtable.SortWord (0 ms)
[ RUN      ] TestHashtable.GetFromHashtable
[       OK ] TestHashtable.GetFromHashtable (0 ms)
[----------] 3 tests from TestHashtable (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 6 tests.
```

## Summary:

In this assignment, we wrote a program to find anagrams from a txt file by using Hashtable. Specifically, I used LinkedListOfLinkedList in each buckets to store the anagrams. 

## What went well and what was hard:

The implementation of hashtable functions and linkedlist functions went well. It was hard for me to figure out the source of memory leak.

## Time spent:
* 4 days
