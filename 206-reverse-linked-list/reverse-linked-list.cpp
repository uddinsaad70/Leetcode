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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* pre = head;
        ListNode* post = pre -> next;
        pre->next = nullptr;
        while(post!=nullptr){
            ListNode* temp = post -> next;
            post -> next = pre;
            pre = post;
            post = temp;
        }

        return pre;
    }
};