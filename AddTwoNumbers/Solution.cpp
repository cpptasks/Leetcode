// "Add Two Numbers"

//https://t.me/cpptasks

//https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwo(l1, l2, 0);
    }

private:
    ListNode* addTwo(ListNode* l1, ListNode* l2, bool memory) {
        if (l1 && l2) {
            int answerDigit = memory + l1->val + l2->val;
            memory = answerDigit / 10;
            answerDigit = answerDigit % 10;
            return new ListNode(answerDigit, addTwo(l1->next, l2->next, memory));
        }
        else if (l1) {
            return addSingle(l1, memory);
        }
        else if (l2) {
            return addSingle(l2, memory);
        }
        else if (memory) {
            return new ListNode(1);
        }            
        else {
            return nullptr;
        }
    }
  
    ListNode* addSingle(ListNode* l, bool memory) {
        if (l) {
            int answerDigit = memory + l->val;
            memory = answerDigit / 10;
            answerDigit = answerDigit % 10;
            return new ListNode(answerDigit, addSingle(l->next, memory));
        }
        else if (memory) {
            return new ListNode(1);
        }
        else {
            return nullptr;
        }
    }
};
