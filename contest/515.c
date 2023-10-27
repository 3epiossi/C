#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
  struct TreeNode *left;
  struct TreeNode *right;
  int val;

} typedef TreeNode;
struct node {
  TreeNode *treenode;
  struct node *next;
  struct node *prev;
} typedef Node;
struct queue {
  Node *front;
  Node *rear;
  int count;
} typedef Queue;
void enque(Queue**queue, TreeNode *treenode) {
  if (!treenode) {
    return;
  }
  if ((*queue)->count == 0) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->treenode = treenode;
    node->next = NULL;
    node->prev = NULL;
    node->treenode = treenode;
    (*queue)->front = node;
    (*queue)->rear = node;
    (*queue)->count += 1;
    return;
  }
  (*queue)->front->prev = (Node *)malloc(sizeof(Node));
  (*queue)->front->prev->next = (*queue)->front;
  (*queue)->front->prev->prev = NULL;
  (*queue)->front->prev->treenode = treenode;
  (*queue)->front = (*queue)->front->prev;
  (*queue)->count += 1;
}
void deque(Queue* queue) {
  Node* temp;
  switch(queue->count){
    case 0:
      break;
    case 1:
      temp = queue->front;
      queue->front = NULL;
      queue->rear = NULL;
      queue->count -= 1;
      free(temp);
      break;
    default:
      temp = (queue)->rear;
      (queue)->rear = (queue)->rear->prev;
      (queue)->rear->next = NULL;
      free(temp);
      (queue)->count -= 1;
      break;
  }
  return ;
}
int *largestValues(struct TreeNode *root, int *returnSize) {
  int *res = (int *)calloc(14, sizeof(int));
  *returnSize = 0;
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  enque(&queue, root);
  while (queue->count) {
    Queue *nextQue = (Queue *)malloc(sizeof(Queue));
    nextQue->count = 0;
    nextQue->front = NULL;
    nextQue->rear = NULL;
    int mx = queue->rear->treenode->val;
    while (queue->count) {
      enque(&nextQue, queue->rear->treenode->left);
      enque(&nextQue, queue->rear->treenode->right);
      mx = (queue->rear->treenode->val > mx) ? queue->rear->treenode->val : mx;
      deque(queue);
    }
    free(queue);
    queue = nextQue;
    res[*returnSize] = mx;
    *returnSize += 1;
  }
  while (queue->rear) {
    deque(queue);
  }
  return res;
}
TreeNode *creatTreeNode(TreeNode *left, TreeNode *right, int val) {
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root->left = left;
  root->right = right;
  root->val = val;
  return root;
}
int main() {
  // TreeNode *leftl = creatTreeNode(NULL, NULL, 5);
  // TreeNode *leftr = creatTreeNode(NULL, NULL, 3);
  // TreeNode *rightr = creatTreeNode(NULL, NULL, 4);
  TreeNode *left = creatTreeNode(NULL, NULL, 3);
  TreeNode *right = creatTreeNode(NULL, NULL, 2);
  TreeNode *root = creatTreeNode(left, right, 1);
  int returnSize;
  int *res = largestValues(root, &returnSize);
  for (int i = 0; i < returnSize; ++i) {
    printf("%d ", res[i]);
  }
  return 0;
}
