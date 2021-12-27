// Take 1 list as a main. With start case when prev node == nullptr
// Compare values with current node from 1 list and from 2
// Relink nodes
// After main loop if some list 2 nodes left(that are bigger than max list 1 node) add them as a tail
// Return very first node

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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        
        ListNode* cur1 = list1;
        ListNode* prev1 = nullptr;
        ListNode* cur2 = list2;
        
        if(list2 == nullptr)
            return list1;
        
        while(cur1 != nullptr) {
            // cout << "cur1: " << cur1 << " "<< cur1->val << " cur2: " << cur2 << " " << cur2->val << endl;
            if(cur1->val >= cur2->val) {
                cout << ">=" << endl;
                if(prev1 != nullptr) {
                    prev1->next = cur2;
                    // cout << " prev1:       " << prev1 << endl;
                    // cout << " prev1->next: " << prev1->next << endl;

                    ListNode* next_cur2 = cur2->next;
                    cur2->next = cur1;
                    // cout << " cur2      :  " << cur2 << endl;
                    // cout << " cur2->next:  " << cur2->next << endl;

                    prev1 = cur2;
                    // cout << " prev1 new :  " << prev1 << endl;

                    cur2 = next_cur2;
                    if(cur2 == nullptr)
                        break;
                } else {
                    ListNode* next_cur2 = cur2->next;
                    
                    cur2->next = cur1;
                    prev1 = cur2;
                    list1 = prev1;
                    
                    cur2 = next_cur2;

                    if(cur2 == nullptr)
                        break;
                }
                
            } else {
                // cout << "<" << endl;
                prev1 = cur1;
                cur1 = cur1->next;
                // cout << " prev1:       " << prev1 << endl;
                // cout << " cur1:        " << cur1 << endl;
            }
        }
        
        cur1 = prev1;
        
        while(cur2 != nullptr) {
            cur1->next = cur2;
            cur1 = cur1->next;

            cur2 = cur2->next;
        }
        
        
        return list1;
    }
};
