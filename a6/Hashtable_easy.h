#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList_easy.h"


#ifndef HASHTABLE_H
#define HASHTABLE_H

// This struct represents a hashtable, it stores the metadata of a hashtable.
struct hashtableInfo {
  int num_buckets;  // the number of buckets in the hashtable
  LinkedListOfLinkedList* buckets;  // a pointer to the LinkedListOfLinkedList
};

typedef struct hashtableInfo* Hashtable;


// Hashtables store key/value pairs.
typedef struct {
  char* key;    // the key in the key/value pair
  char* value;  // the value in the key/value pair
} HTKeyValue, *HTKeyValuePtr;

// Allocates and returns a new Hashtable.
//
// INPUT:
//   numBuckets: The number of buckets this hashtable will start with.
//
// Returns NULL if the hashtable was unable to be malloc'd, or
// the hashtable.
Hashtable CreateHashtable(int num_buckets);

// Destroys and Frees the hashtable.
//
// Input:
//   ht: the table to be free'd. It is unsafe to use the
//    hashtable after this is called.
void DestroyHashtable(Hashtable ht);

// Puts the given key value pair int the hashtable.
//
// INPUT:
//   ht: the hashtable to insert into
//   kvp: the key-value pair to put into the hashtable.
// Returns the Hashtable with the kvp added.
Hashtable PutInHashtable(Hashtable ht, HTKeyValuePtr kvp);

// Get a LinkedList of the anagram of the given key word.
//
// INPUT:
//   ht: the hashtable to check for
//   key: the given key value
//
// Returns the anagram of the given key value.
LinkedList GetFromHashtable(Hashtable ht, char* key);

// Print out the value of each kvp stored in the Hashtable;
// INPUT:
//   ht: a pointer to the hashtable that will be printed.
void PrintHashtable(Hashtable ht);

// Computes an int from a string, to be used for a key in a HTKeyValue.
//
// INPUT:
//   buffer: a pointer to the array holding the string
//   len: the length of the string
//
// Returns an int to be used as an input to FNVHashInt64 for the hash value.
uint64_t FNVHash64(unsigned char *buffer, unsigned int len);

// Creates a hashed value from a given key.
//
// INPUT:
//   makehash: an int to be hashed for the key of a HTKeyValue pair
//
// Returns the int to be used as a key.
uint64_t FNVHashInt64(uint64_t makehash);

// Sort the characters in a given word.
//
// INPUT: a pointer to the word.
//
// Returns a pointer to a sorted word.
char* SortWord(char* word);

#endif  // HASHTABLE_H

