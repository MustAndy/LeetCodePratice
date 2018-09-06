
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TREENODE;

void PreOrderBTree(TREENODE *T) {
  if (T == NULL) {
    return;
  } else {
    printf("%d \n", T->val);
    PreOrderBTree(T->left);
    PreOrderBTree(T->right);
  }
}
int TreeDeep(TREENODE *T) {
  int deep = 0;
  if (T != NULL) {
    int leftdeep = TreeDeep(T->left);
    int rightdeep = TreeDeep(T->right);
    deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
  }

  return deep;
}

void CreateBTree(TREENODE **T) {
  int ch;
  scanf("%d", &ch);
  if (ch == -1) {
    *T = NULL;
    return;
  } else {
    *T = (TREENODE *)malloc(sizeof(TREENODE));
    (*T)->val = ch;
    printf("输入%d的左子节点：", ch);
    CreateBTree(&((*T)->left));
    printf("输入%d的右子节点：", ch);
    CreateBTree((&(*T)->right));
  }

  return;
}
struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2) {
  if (!t2)
    return t1;
  if (!t1)
    return t2;
  t1->val += t2->val;
  t1->left = mergeTrees(t1->left, t2->left);
  t1->right = mergeTrees(t1->right, t2->right);
  return t1;
}
int main() {
  TREENODE *t1, *t2;
  CreateBTree(&t1);
  CreateBTree(&t2);

  TREENODE *result = mergeTrees(t1, t2);
  PreOrderBTree(t1);
  // printf("%d", result);
  return 0;
}