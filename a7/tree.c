#include "tree.h"

TreeNode* CreateTreeNode(char* path, char* name) {
      TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
      newNode->path = path;
      newNode->name = name;
      newNode->children = NULL;
      newNode->siblings = NULL;
      newNode->level = 0;
      return newNode;
}

void DestroyTreeNode(TreeNode *node) {
  if (node == NULL) {
    return;
  }
  DestroyTreeNode(node->siblings);
  DestroyTreeNode(node->children);
  free(node->path);
  free(node->name);
  free(node);
}

/**
void AddChild(TreeNode *root, char* path, char* name) {
  TreeNode* children = CreateTreeNode(path, name);
  TreeNode* childListHead = root->children;
  if (childListHead == NULL) {
    root->children = children;
    children->level = root->level + 1;
  }
  else {
    while (childListHead->siblings != NULL) {
      childListHead = childListHead->siblings;
    }
    childListHead->siblings = children;
    children->level = childListHead->level;
  }
}
*/

void AddChild(TreeNode* root, TreeNode* children) {
  TreeNode* childListHead = root->children;
  if (childListHead == NULL) {
    root->children = children;
    children->level = root->level + 1;
  } else {
    while (childListHead->siblings != NULL) {
      childListHead = childListHead->siblings;
    }
    childListHead->siblings = children;
    children->level = childListHead->level;
  }
}

/**
int main() {
  TreeNode* root = CreateTreeNode("Desktop/", "myfile");
  TreeNode* child1 = CreateTreeNode("Desktop/myfile/","a1");
  TreeNode* child2 = CreateTreeNode("Desktop/myfile/", "a2");
  // AddChild(root, "Desktop/myfile/", "a1");
  // AddChild(root, "Desktop/myfile/", "a2");
  AddChild(root, child1);
  AddChild(root, child2);
  TreeNode* node1 = CreateTreeNode("Desktop/myfile/a1/", "tree");
  AddChild(child1, node1);
  //AddChild(node1, "Desktop/myfile/a1/", "tree");
  printf("the root is: %s\n", root->name);
  printf("the child is: %s\n", root->children->name);
  printf("the child is: %s\n", root->children->siblings->name);
  printf("the child is: %s\n", root->children->children->name);
  DestroyTreeNode(root);
  return 0;// checked, the program runs correctly and no memory leak!
}
*/
