#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <locale.h>
#include "tree.h"
#include "queue.h"
#include "stack.h"

int main() {
  char* path = ".";
  char* name = "a7";
  TreeNode* root = CreateTreeNode(path, name);
  Queue* queue = CreateQueue(root);
  while (queue->head != NULL) {
    LL_Node* node = Dequeue(queue);
    TreeNode* roottreenode = node->treenode;
    char* dir = roottreenode->path;
    free(node);
    struct stat s;
    struct dirent **namelist;
    int num_files;
    num_files = scandir(dir, &namelist, 0, alphasort);
    if (num_files < 0) {
      perror("scandir");
      printf("dir: %s\n", dir);
      return;
    } else {
      int i = 0;
      while (i < num_files) {
      // Ignore dotfiles, such as .emacs
        if (namelist[i]->d_name[0] == '.') {
          free(namelist[i]);
          i++;
          continue;
        }
        char *directory;
        int length = strlen(dir) + strlen(namelist[i]->d_name);
        directory = (char*) malloc(((length + 3)*sizeof(*directory)));
        if (directory == NULL) {
          printf("Couldn't malloc for filecrawler.directory\n");
          return;
        }
        // Copy the path and file name into the print function
        snprintf(directory, length + 3, "%s/%s", dir, namelist[i]->d_name);
        char* newpath = (char*)malloc(sizeof(*newpath)*
                                       (strlen(dir) +
                                        strlen(namelist[i]->d_name) + 3));
        strcpy(newpath, dir);
        strcat(newpath, "/");
        strcat(newpath, namelist[i]->d_name);
        char* name = (char*)malloc
                     (sizeof(*name)*(strlen(namelist[i]->d_name) + 3));
        strcpy(name, namelist[i]->d_name);
        TreeNode* childnode = CreateTreeNode(newpath, name);
        AddChild(roottreenode, childnode);
        // Use stat() to get info about the given directory (or file)
        if (0 == stat(directory, &s)) {
          // Tells us if the given directory/file is a directory or not
          if (S_ISDIR(s.st_mode)) {
            strcat(directory, "/");
            Enqueue(queue, childnode);
          }
        } else {
          printf("no stat; %s\n", directory);
        }
        free(namelist[i]);
        i++;
        free(directory);
      }
    }
    free(namelist);
  }
  Stack* stack = CreateStack(root);
  LL_Node* node = Pop(stack);
  TreeNode* treenode;
  while (node != NULL) {
    treenode = node->treenode;
    free(node);
    printf("%*c", treenode->level*2, ' ');
    printf("--\033[1;93m%s\033[0m\n", treenode->name);
    TreeNode* childnode = treenode->children;
    while (childnode != NULL) {
      Push(stack, childnode);
      childnode = childnode->siblings;
    }
    node = Pop(stack);
  }
  DestroyQueue(queue);
  DestroyStack(stack);
  DestroyTreeNode(root->children);
  free(root);
  return 0;
}
