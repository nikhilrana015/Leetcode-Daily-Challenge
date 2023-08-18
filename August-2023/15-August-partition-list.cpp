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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);

        ListNode *curr1 = dummy1;
        ListNode *curr2 = dummy2;

        while(head!=nullptr)
        {
            if(head->val<x) {
                curr1->next = head;
                curr1 = curr1->next;
            }
                
            
            else {
                curr2->next = head;
                curr2 = curr2->next;
            }

            head = head->next;
        }

        curr1->next = nullptr;
        curr2->next = nullptr;

        curr1->next = dummy2->next;

        return dummy1->next;

    }
};
