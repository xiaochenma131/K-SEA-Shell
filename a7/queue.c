#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

LL_Node* CreateLLNode(TreeNode* treenode) {
  LL_Node* node = (LL_Node*)malloc(sizeof(LL_Node));
  node->treenode = treenode;
  node->next = NULL;
  return node;
}

void DestroyLLNode(LL_Node* node) {
  if (node == NULL) {
    return;
  }
  DestroyTreeNode(node->treenode);
  free(node);
}

LL_Node* LLAddBack(LL_Node* head, LL_Node* to_add) {
  if (head == NULL) {
    return to_add;
  }
  LL_Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = to_add;
  return head;
}

LL_Node* LLAddHead(LL_Node* head, LL_Node* to_add) {
  if (head == NULL) {
    return to_add;
  }
  to_add->next = head;
  return to_add;
}

Queue* CreateQueue(TreeNode* treenode) {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  queue->head = CreateLLNode(treenode);
  return queue;
}

void DestroyQueue(Queue* queue) {
  if (queue == NULL) {
    return;
  }
  LL_Node* curNode = queue->head;
  while (curNode != NULL) {
    DestroyLLNode(curNode);
    curNode = curNode->next;
  }
  free(queue);
}

void Enqueue(Queue* queue, TreeNode* treenode) {
  LL_Node* newhead = LLAddBack(queue->head, CreateLLNode(treenode));
  queue->head = newhead;
}

LL_Node* Dequeue(Queue* queue) {
  LL_Node* head = queue->head;
  if (head == NULL) {
    return NULL;
  }
  LL_Node* next = head->next;
  queue->head = next;
  return head;
}

/**
int main() {
  TreeNode* node1 = CreateTreeNode("Desktop/","a1");
  TreeNode* node2 = CreateTreeNode("Desktop/", "a2");
  TreeNode* node3 = CreateTreeNode("Desktop/", "a3");
  Queue* queue = CreateQueue(node1);
  Enqueue(queue, node2);
  Enqueue(queue, node3);
  LL_Node* ll_node1 = Dequeue(queue);
  LL_Node* ll_node2 = Dequeue(queue);
  LL_Node* ll_node3 = Dequeue(queue);
  printf("the first file is: %s\n", ll_node1->treenode->name);
  printf("the second file is : %s\n", ll_node2->treenode->name);
  printf("the third file is : %s\n", ll_node3->treenode->name);
  free(queue);
  DestroyLLNode(ll_node1);
  DestroyLLNode(ll_node2);
  DestroyLLNode(ll_node3); // the program runs correctly and no memory leak.
}
*/
