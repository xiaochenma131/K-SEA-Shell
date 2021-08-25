#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

struct stack {
  LL_Node* top;
};

Stack* CreateStack(TreeNode* treenode);

void DestroyStack(Stack* stack);

void Push(Stack* stack, TreeNode* treenode);

LL_Node* Pop(Stack* stack);

#endif  // STACK_H
