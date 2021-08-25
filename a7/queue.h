# include <stdio.h>
# include <stdlib.h>
# include "tree.h"

#ifndef QUEUE_H
#define QUEUE_H

typedef struct ll_node LL_Node;

struct ll_node {
  TreeNode* treenode;
  LL_Node* next;
};

typedef struct queue Queue;

struct queue {
  LL_Node* head;
};

LL_Node* CreateLLNode(TreeNode* treenode);

void DestroyLLNode(LL_Node* node);

LL_Node* LLAddBack(LL_Node* head, LL_Node* to_add);

LL_Node* LLAddHead(LL_Node* head, LL_Node* to_add);

Queue* CreateQueue(TreeNode* treenode);

void DestroyQueue(Queue* queue);

void Enqueue(Queue* queue, TreeNode* treenode);

LL_Node* Dequeue(Queue* queue);

#endif  // QUEUE_H
