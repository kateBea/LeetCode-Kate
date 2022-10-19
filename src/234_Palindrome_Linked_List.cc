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

#include <vector>
#include <cstdint>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> str{};
        
        while (head) {
            str.push_back(head->val);
            
            head = head->next;
        }
        
        const size_t limit = (str.size() / 2ul);
        for (size_t index{}; index < limit; ++index)
            if (str[index] != str[(str.size() - 1) - index])
                return false;
        
        return true;
    }
};