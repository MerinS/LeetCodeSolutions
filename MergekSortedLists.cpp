/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * backup = NULL;
        ListNode * start = NULL;
        ListNode * node  = NULL;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                node = new ListNode(l1->val);
                l1 = l1->next;
            }
            else{
                node = new ListNode(l2->val);
                l2 = l2->next;
            }
            if(backup == NULL){
                start = node;
            }
            else{
                backup->next = node;
            }
            backup = node;   
        }
        
        
        if(l1 != NULL){
            while(l1!=NULL){
                if(backup == NULL){
                    start = l1;
                    break;
                }
                backup->next = l1;
                backup = l1;
                l1 = l1->next;
            }
        }
        
        if(l2 != NULL){
            while(l2!=NULL){
                if(backup == NULL){
                    start = l2;
                    break;
                }
                backup->next = l2;
                backup = l2;
                l2 = l2->next;
            }
        }
        return start;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        int iter;
        ListNode* node;
        vector<ListNode*> lists_backup;
        while(lists.size()>1){
            lists_backup.clear();
            iter = lists.size()/2;

            for(int i= 0; i<iter; ++i){
                node = mergeTwoLists(lists[2*i],lists[(2*i)+1]);
                lists_backup.push_back(node);
            }
            
            if(lists.size()%2 == 1){
                lists_backup.push_back(lists[lists.size()-1]);
            }
            lists = lists_backup;
        }
        return lists[0];   
    }
};
