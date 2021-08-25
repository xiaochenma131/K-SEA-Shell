#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_H
#define TREE_H

// This struct represents a tree node.

typedef struct treeNode TreeNode;

struct treeNode {
  char* path;  // The directory this file is in.
  char* name;  // The name of this file.
  TreeNode* children;  // Essentially a linked list of children
  TreeNode* siblings;  // Essentially a linked list of siblings
  int level;  // How deep in the tree this node is
};

TreeNode* CreateTreeNode(char* path, char* name);

void AddChild(TreeNode* root, TreeNode* children);
// void AddChild(TreeNode* root, char* path, char* name);

void DestroyTreeNode(TreeNode* node);

#endif  // TREE_H
