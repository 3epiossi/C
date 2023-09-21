/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize){
    typedef struct ListNode ListNode;
    ListNode** res = (ListNode**) malloc(k*sizeof(ListNode*));
    for(int i = 0; i < k; i += 1){
        res[i] = NULL;
    }
    *returnSize = k;
    ListNode* cur = head;
    int rest = 0;
    bool flag = false;
    while (true){
        flag = false;
        for(rest = 0; rest < k; rest += 1){
            if (!cur){
                flag = true;
                break;
            }
            cur = cur-> next;
        }
        for(int j = 0; j < rest; j += 1){
            if (res[j] == NULL){
                res[j] = head;
                for(int _ = 0; _ < j; _++)
                    res[j] = res[j]->next;
            }
            for(int l = j+1; l < k; l += 1){
                if (!res[l]) continue;
                res[l] = res[l]->next;
            }
        }
        if(flag == true) break;
    }
    ListNode* bridge = head;
    int count = 1;
    while(bridge){
        if (count < k && bridge->next == res[count] ){
            bridge->next = NULL;
            bridge = res[count];
            count += 1;
        }
        else{
            bridge = bridge->next;
        }
    }
    return res;
}