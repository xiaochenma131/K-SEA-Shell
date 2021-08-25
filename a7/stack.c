#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
#include "stack.h"

Stack* CreateStack(TreeNode* treenode) {
  Stack* stack = (Stack*)malloc(sizeof(Stack));
  stack->top = CreateLLNode(treenode);
  return stack;
}

void DestroyStack(Stack* stack) {
  if (stack == NULL) {
    return;
  }
  LL_Node* curNode = stack->top;
  while (curNode != NULL) {
    DestroyLLNode(curNode);
    curNode = curNode->next;
  }
  free(stack);
}

void Push(Stack* stack, TreeNode* treenode) {
  if (treenode == NULL) {
    return;
  }
  LL_Node* newhead = LLAddHead(stack->top, CreateLLNode(treenode));
  stack->top = newhead;
}

LL_Node* Pop(Stack* stack) {
  LL_Node* node = stack->top;
  if (node == NULL) {
    return NULL;
  }
  LL_Node* next = node->next;
  stack->top = next;
  return node;
}
/**
int main() {
  TreeNode* node1 = CreateTreeNode("Desktop/", "a1");
  TreeNode* node2 = CreateTreeNode("Desktop/", "a2");
  TreeNode* node3 = CreateTreeNode("Desktop/", "a3");
  Stack* stack = CreateStack(node1);
  Push(stack, node2);
  Push(stack, node3);
  LL_Node* ll_node1 = Pop(stack);
  LL_Node* ll_node2 = Pop(stack);
  LL_Node* ll_node3 = Pop(stack);
  printf("The first file is: %s\n", ll_node1->treenode->name);
  printf("The second file is: %s\n", ll_node2->treenode->name);
  printf("The third file is: %s\n", ll_node3->treenode->name);
  DestroyStack(stack);
  DestroyLLNode(ll_node1);
  DestroyLLNode(ll_node2);
  DestroyLLNode(ll_node3);
  return 0;  // Program runs correctly and no memory leak
}
*/
