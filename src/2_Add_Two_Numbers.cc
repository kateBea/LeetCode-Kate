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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *retVal{nullptr};
        ListNode *aux{nullptr};
        bool carry{false};

        retVal = aux = new ListNode((l1->val + l2->val) % 10);
        carry = (l1->val + l2->val) >= 10;

        l1 = l1->next;
        l2 = l2->next;
        
        while (l1 and l2)
        {
            if (carry)
                aux->next = new ListNode((l1->val + l2->val + 1) % 10);
            else
                aux->next = new ListNode((l1->val + l2->val) % 10);

            carry = (l1->val + l2->val + (carry ? 1 : 0)) >= 10;

            aux = aux->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            if (carry)
                aux->next = new ListNode((l1->val + 1) % 10);
            else
                aux->next = new ListNode((l1->val) % 10);

            carry = (l1->val + (carry ? 1 : 0)) >= 10;
            l1 = l1->next;
            aux = aux->next;
        }

        while (l2)
        {
            if (carry)
                aux->next = new ListNode((l2->val + 1) % 10);
            else
                aux->next = new ListNode((l2->val) % 10);

            carry = (l2->val + (carry ? 1 : 0)) >= 10;
            l2 = l2->next;
            aux = aux->next;
        }

        if (carry)
            aux->next = new ListNode(1);

        return retVal;
    }
};