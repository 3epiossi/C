#include <stdio.h>
#include <stdlib.h>

int* append(int val, int* array, int* returnSize){
  if (array != NULL){
     int* temp = (int*) malloc( (*returnSize)*(sizeof(int)) );
     int i = 0;
     for(; i < *returnSize-1; i += 1){
       temp[i] = array[i];
     }
     free(array);
     temp[i] = val;
     return temp;
  }
  else{
    array = (int*) malloc(sizeof(int));
    array[0] = val;
    *returnSize = 1;
    return array;
  }
}
int* dfs(struct TreeNode* cur, int* array, int* returnSize){
  if (cur != NULL){
    array = dfs(cur->left, array, returnSize);
    *returnSize += 1;
    array = append(cur->val, array, returnSize);
    
    array =  dfs(cur->right, array, returnSize);
  }
  return array;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
  int* array = (int*) malloc(sizeof(int));
  *returnSize = 0;
  return dfs(root, array, returnSize);
}
