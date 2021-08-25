#include "Hashtable_easy.h"
#include "LinkedList_easy.h"
#include "Assert007.h"
LinkedListOfLinkedList CreateLinkedListOfLinkedList();
Hashtable CreateHashtable(int num_buckets) {
  Assert007(num_buckets > 0);
  Hashtable ht =(Hashtable)malloc(sizeof(struct hashtableInfo));
  if (ht == NULL) {
    return NULL;
  }
  ht->num_buckets = num_buckets;
  ht->buckets = (LinkedListOfLinkedList*)
                malloc(sizeof(LinkedListOfLinkedList)*num_buckets);
  int i;
  for (i = 0; i < num_buckets; i++) {
    LinkedListOfLinkedList newList = CreateLinkedListOfLinkedList();
    ht->buckets[i] = newList;
  }
  return ht;
}

void DestroyHashtable(Hashtable ht) {
  Assert007(ht != NULL);
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
    DestroyLinkedListOfLinkedList(ht->buckets[i]);
  }
  free(ht->buckets);
  free(ht);
}

Hashtable PutInHashtable(Hashtable ht, HTKeyValuePtr kvp) {
  Assert007(ht != NULL);
  Assert007(kvp != NULL);
  uint64_t which_bucket =
      FNVHashInt64(FNVHash64((unsigned char*)kvp->key,
                             strlen(kvp->key)))%ht->num_buckets;
  LinkedListOfLinkedList list = ht->buckets[which_bucket];
  if (list->head == NULL) {
    LinkedList anagramListHead = CreateLinkedList();
    LinkedListOfLinkedListNodePtr newNode =
        CreateLinkedListOfLinkedListNode(anagramListHead);
    list->head = newNode;
    list->tail = newNode;
    list->num_elements = 1;
    InsertLinkedList(anagramListHead, kvp->value);
  } else {
    LinkedListOfLinkedListNodePtr curNode = list->head;
    LinkedListOfLinkedListNodePtr prevNode = NULL;
    while (curNode != NULL) {
      char* sortedword1;
      char* sortedword2;
      sortedword1 = SortWord(curNode->list->head->payload);
      sortedword2 = SortWord(kvp->value);
      if (strcmp(sortedword1, sortedword2) == 0) {
      InsertLinkedList(curNode->list, kvp->value);
      free(sortedword1);
      free(sortedword2);
      return ht;
      }
      prevNode = curNode;
      curNode = curNode->next;
      free(sortedword1);
      free(sortedword2);
    }
    LinkedList anagramListHead = CreateLinkedList();
    curNode = CreateLinkedListOfLinkedListNode(anagramListHead);
    prevNode->next = curNode;
    curNode->prev = prevNode;
    list->tail = curNode;
    list->num_elements += 1;
    InsertLinkedList(curNode->list, kvp->value);
  }
  return ht;
}

LinkedList GetFromHashtable(Hashtable ht, char* key) {
  Assert007(ht != NULL);
  Assert007(key != NULL);
  uint64_t which_bucket =
      FNVHashInt64(FNVHash64((unsigned char*)key, strlen(key)))%ht->num_buckets;
  LinkedListOfLinkedList list = ht->buckets[which_bucket];
  if (list == NULL) {
    return NULL;
  }
  LinkedListOfLinkedListNodePtr curNode = list->head;
  while (curNode != NULL) {
    char* sortedword;
    sortedword = SortWord(curNode->list->head->payload);
    if (strcmp(key, sortedword) == 0) {
      free(sortedword);
      return curNode->list;
    }
    curNode = curNode->next;
    free(sortedword);
  }
  return NULL;
}

void PrintHashtable(Hashtable ht) {
  Assert007(ht != NULL);
  int i;
  for (i = 0; i < ht->num_buckets; i++) {
      PrintLinkedListOfLinkedList(ht->buckets[i]);
  }
}

uint64_t FNVHash64(unsigned char *buffer, unsigned int len) {
  // This code is adapted from code by Landon Curt Noll
  // and Bonelli Nicola:
  //
  // http://code.google.com/p/nicola-bonelli-repo/
  static const uint64_t FNV1_64_INIT = 0xcbf29ce484222325ULL;
  static const uint64_t FNV_64_PRIME = 0x100000001b3ULL;
  unsigned char *bp = (unsigned char *) buffer;
  unsigned char *be = bp + len;
  uint64_t hval = FNV1_64_INIT;
  /*
   * FNV-1a hash each octet of the buffer
   */
  while (bp < be) {
    /* xor the bottom with the current octet */
    hval ^= (uint64_t) * bp++;
    /* multiply by the 64 bit FNV magic prime mod 2^64 */
    hval *= FNV_64_PRIME;
  }
  /* return our new hash value */
  return hval;
}


uint64_t FNVHashInt64(uint64_t makehash) {
  unsigned char buf[8];
  int i;
  for (i = 0; i < 8; i++) {
    buf[i] = (unsigned char) (makehash & 0x00000000000000FFULL);
    makehash >>= 8;
  }
  return FNVHash64(buf, 8);
}

char* SortWord(char* word) {
  Assert007(word != NULL);
  char* sortedword = malloc(strlen(word) + 1);
  strcpy(sortedword, word);
  int i;
  int j;
  char temp;
  for (i = 0; i < strlen(sortedword)-1; i++) {
    for (j = i+1; j < strlen(sortedword); j++) {
      if (sortedword[j] < sortedword[i]) {
        temp = sortedword[i];
        sortedword[i] = sortedword[j];
        sortedword[j] = temp;
      }
    }
  }
  return sortedword;
}
