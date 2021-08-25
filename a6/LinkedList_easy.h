
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
// This struct represents an individual node within a linked list.  A node
// contains next and prev pointers as well as a customer-supplied payload
// pointer.
typedef struct ll_node {
    char           *payload;  // Pointer to a string, most likely on the heap
    struct ll_node *next;     // next node in list, or NULL
    struct ll_node *prev;     // prev node in list, or NULL
} LinkedListNode, *LinkedListNodePtr;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_head {
    uint64_t          num_elements;  //  # elements in the list
    LinkedListNodePtr head;  // head of linked list, or NULL if empty
    LinkedListNodePtr tail;  // tail of linked list, or NULL if empty
} LinkedListHead;

// This struct represetns an individual node within a linked list of linked list
// A node contains list which represents a linked list, next and prev pointers.
typedef struct ll_ll_node {
  LinkedListHead* list;  // Pointer to a linked list.
  struct ll_ll_node *next;  // next node in linked list of linked list, or NULL
  struct ll_ll_node *prev;  // prev node in linked list of linked list, or NULL
}LinkedListOfLinkedListNode, *LinkedListOfLinkedListNodePtr;

// This struct represents the entire linked list of linkedlist.This struct
// contains metadata about the linked list of linked list.
typedef struct ll_ll_head {
  uint64_t num_elements;  // number of list elements in the list
  LinkedListOfLinkedListNodePtr head;  // head of linked list of linked list
  LinkedListOfLinkedListNodePtr tail;  // tail of linked list of linked list
} LinkedListOfLinkedListHead;

// A LinkedList is a pointer to a ll_head struct.
// To hide the implementation of LinkedList, we declare the "struct ll_head"
// structure here, but we *define* the structure in the internal header
// LinkedList_priv.h. This lets us define a pointer to LinkedList as a new
// type while leaving the implementation details opaque to the customer.
typedef struct ll_head *LinkedList;

// A LinkedListOfLinkedList is a pointer to a ll_ll_head struct
typedef struct ll_ll_head *LinkedListOfLinkedList;

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNode* CreateLinkedListNode(char *data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNode(LinkedListNode *node);

// Create a LinkedListOfLinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the list of the returned LL_LL_Node will point to

// Returns a pointer to the new LinkedlistOfLinkedListNode
LinkedListOfLinkedListNode* CreateLinkedListOfLinkedListNode
(LinkedListHead* list);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListOfLinkedListNode(LinkedListOfLinkedListNodePtr node);

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy and free the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error.
LinkedList CreateLinkedList();

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
// INPUT: A pointer to a LinkedList.
// Returns 0 if the destroy was successful; non-zero for failure.
int DestroyLinkedList(LinkedList list);
// Adds an element to the head of a LinkedList, with the string
// as the given pointer.
// The customer is responsible for allocating the string.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A pointer to a string for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure.
int InsertLinkedList(LinkedList, char*);

// Print out the payload character stored in a given LinkedList
// INPUT: A pointer to the LinkedList that will be printed
void PrintLinkedList(LinkedList);

// Create a LinkedListOfLinkedList.
// Returns a LinkedListOfLinkedList. Return NULL if error happens.
LinkedListOfLinkedList CreateLinkedListOfLinkedList();

// Destroy a LinkedListOfLinkedList.
//
// INPUT: a pointer to a LinkedListOfLinkedList
//
// Returns 0 if destroy was successful.
int DestroyLinkedListOfLinkedList(LinkedListOfLinkedList list);

// Print the words in a LinkedListOfLinkedList
//
// INPUT: A pointer to the LinkedListOfLinkedList
void PrintLinkedListOfLinkedList(LinkedListOfLinkedList list);
#endif  // LINKEDLIST_H
