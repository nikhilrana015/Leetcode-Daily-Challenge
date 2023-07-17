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

    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr)
            return head;

        ListNode *curr = head;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;

        while(curr!=nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *newL1 = reverse(l1);
        ListNode *newL2 = reverse(l2);
        int carry = 0;
        int flag = 0;

        l1 = newL1;
        l2 = newL2;

        ListNode *prev1, *prev2;
        prev1 = prev2 = nullptr;


        while(newL1!=nullptr or newL2!=nullptr)
        {
            if(newL1!=nullptr and newL2!=nullptr)
            {
                int sum = newL1->val +newL2->val + carry;
                carry = sum/10;
                sum = sum%10;

                newL1->val = sum;
                newL2->val = sum;

                prev1 = newL1;
                prev2 = newL2;

                newL1 = newL1->next;
                newL2 = newL2->next;
                flag = 1;
            }

            else if(newL1!=nullptr and newL2==nullptr)
            {
                int sum = newL1->val + carry;
                carry = sum/10;
                sum = sum%10;

                newL1->val = sum;
                prev1 = newL1;
                newL1 = newL1->next;
                flag = 2;
            }

            else if(newL1==nullptr and newL2!=nullptr)
            {
                int sum = newL2->val + carry;
                carry = sum/10;
                sum = sum%10;

                newL2->val = sum;
                prev2 = newL2;
                newL2 = newL2->next;
                flag = 3;
            }
        }

        if(carry>0)
        {   
            ListNode *currNode = new ListNode(carry);

            if(flag==1 or flag==2){
                prev1->next = currNode;
                prev2->next = currNode;
            }

            else if(flag==2)
                prev1->next = currNode;

            else
                prev2->next = currNode;    
        }

        if(flag==1 or flag==2) {
            return reverse(l1);
        }

        return reverse(l2);
    }
};