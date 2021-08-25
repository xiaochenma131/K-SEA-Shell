#include<stdio.h>
#include "LinkedList_easy.h"
#include "Assert007.h"

LinkedListNode* CreateLinkedListNode(char* data) {
  Assert007(data != NULL);
  LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(struct ll_node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->payload = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

int DestroyLinkedListNode(LinkedListNode* node) {
  if (node == NULL) {
    return -1;
  }
  free(node->payload);
  free(node);
  return 0;
}

LinkedListOfLinkedListNode* CreateLinkedListOfLinkedListNode
(LinkedListHead* list) {
  LinkedListOfLinkedListNode* newNode = (LinkedListOfLinkedListNode*)
                                        malloc(sizeof(struct ll_ll_node));
  if (newNode == NULL) {
    return NULL;
  }
  newNode->list = list;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

int DestroyLinkedListOfLinkedListNode(LinkedListOfLinkedListNodePtr node) {
  if (node == NULL) {
    return -1;
  }
  DestroyLinkedList(node->list);
  free(node);
  return 0;
}

LinkedList CreateLinkedList() {
  LinkedList newList = (LinkedList)malloc(sizeof(struct ll_head));
  Assert007(newList != NULL);
  newList->num_elements = 0;
  newList->head = NULL;
  newList->tail = NULL;
  return newList;
}

LinkedListOfLinkedList CreateLinkedListOfLinkedList() {
  LinkedListOfLinkedList newList = (LinkedListOfLinkedList)
                                   malloc(sizeof(struct ll_ll_head));
  Assert007(newList != NULL);
  newList->num_elements = 0;
  newList->head = NULL;
  newList->tail = NULL;
  return newList;
}

int DestroyLinkedList(LinkedList list) {
  Assert007(list != NULL);
  LinkedListNodePtr curNode = list->head;
  LinkedListNodePtr nextNode = NULL;
  while (curNode != NULL) {
    nextNode = curNode->next;
    DestroyLinkedListNode(curNode);
    curNode = nextNode;
  }
  free(list);
  return 0;
}

int DestroyLinkedListOfLinkedList(LinkedListOfLinkedList list) {
  Assert007(list != NULL);
  LinkedListOfLinkedListNodePtr curListHead = list->head;
  LinkedListOfLinkedListNodePtr  nextListHead = NULL;
  while (curListHead != NULL) {
    nextListHead = curListHead->next;
    DestroyLinkedListOfLinkedListNode(curListHead);
    curListHead = nextListHead;
  }
  free(list);
  return 0;
}

int InsertLinkedList(LinkedList list, char* data) {
  Assert007(data != NULL);
  LinkedListNodePtr newNode = CreateLinkedListNode(data);
  if (newNode == NULL) {
    return -1;
  }
  newNode->next = list->head;
  if ((list->head) != NULL) {
    list->head->prev = newNode;
    list->head = newNode;
    list->num_elements++;
  } else {
    list->head = newNode;
    list->tail = newNode;
    list->num_elements++;
  }
  return 0;
}

void PrintLinkedList(LinkedList list) {
  Assert007(list != NULL);
  if (list->head != NULL) {
    LinkedListNodePtr curNode = list->head;
    while (curNode != NULL) {
      printf("%s ", curNode->payload);
      curNode = curNode->next;
    }
    printf("\n");
  }
}

void PrintLinkedListOfLinkedList(LinkedListOfLinkedList list) {
  if (list->head != NULL) {
    LinkedListOfLinkedListNodePtr curListHead = list->head;
    while (curListHead != NULL) {
      PrintLinkedList(curListHead->list);
      curListHead = curListHead->next;
    }
  }
}
