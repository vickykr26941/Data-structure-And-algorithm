    // Lc divide and conquer section 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // brute force approach time 
class Solution {
public:
    ListNode *merge(ListNode *l1,ListNode *l2){
        if(!l1) return l2;
        else if(!l2) return l1;
        if(l1->val<=l2->val){
            l1->next = merge(l1->next,l2);
            return l1;
        }else{
            l2->next = merge(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) 
            return nullptr;
        
        ListNode *l1 = lists[0];
        for(int i=1; i<lists.size(); i++){
           l1 = merge(l1,lists[i]);
        }
        return l1;
    }
};
