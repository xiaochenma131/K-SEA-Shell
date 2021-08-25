#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList_easy.h"
#include "Hashtable_easy.h"

int main() {
  FILE *fp;
  int i;
  fp = fopen("words.txt", "r");
  if (fp == NULL) {
    printf("Can't open file \n");
    return 1;
  }
  char output[1000];
  Hashtable ht = CreateHashtable(10000);
  while (fgets(output, sizeof(output), fp) != NULL) {
    HTKeyValuePtr kvp = (HTKeyValuePtr)malloc(sizeof(HTKeyValue));
    char* word = malloc(strlen(output) + 1);
    strcpy(word, output);
    word[strlen(word) - 1] = 0;
    kvp->key = SortWord(word);
    char* tmp = kvp->key;
    kvp->value = word;
    ht = PutInHashtable(ht, kvp);
    if (tmp != kvp->key) {
      printf("error\n");
    }
    free(kvp->key);
    free(kvp);
  }
  PrintHashtable(ht);
  fclose(fp);
  DestroyHashtable(ht);
  return 0;
}
