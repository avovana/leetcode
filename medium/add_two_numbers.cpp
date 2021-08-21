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

void printList(ListNode *llist) {
    while(llist) {
        cout << llist->val << " ";
        llist = llist->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* lead = l1;
        ListNode* slave = l2;
        
        ListNode* result = new ListNode();
        ListNode* current = result;
        
        int remain = 0;
        
        while(true) {
            //take values from current pointers
            int val1 = lead->val;
            int val2 = slave != nullptr ? slave->val : 0;
            
            int sum = val1 + val2;
            int res = sum % 10 + remain;
            res = res != 10 ? res : 0;
            remain = (sum + remain) / 10;
            cout << "val1: " << val1 << " val2: " << val2 << " sum: " << sum << " res: " << res << " remain: " << remain << endl;
            
            //save result
            current->val = res;
            
            printList(result);

                        
            //increment pointers to a new state
            if(lead->next) {
                lead = lead->next;
                if(slave != nullptr && slave->next) {
                    slave = slave->next;
                
                    current->next = new ListNode();
                    current = current->next;
                }
                else {
                    slave = nullptr;
                    current->next = new ListNode();
                    current = current->next;
                }
            } else {
                if(slave != nullptr && slave->next) {
                    lead = slave->next;
                    slave = nullptr;
                    
                    current->next = new ListNode();
                    current = current->next;
                } else {
                    break;
                }
            }
        }
        
        if(remain)
            current->next = new ListNode(remain);
        
        cout << endl << endl;
        printList(result);
        
        return result;
    }
};