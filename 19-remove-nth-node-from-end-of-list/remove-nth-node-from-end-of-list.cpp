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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<int>st;
        int t = 0;
        ListNode* tail = head;
        while(tail != nullptr){
            st.push(tail->val);
            tail = tail->next;
            t++;
        }
        ListNode* ans = nullptr;
        for(int i = 1; i <= t; i++){
            if(i != n){
                ListNode* temp = new ListNode(st.top());
                temp -> next = ans;
                ans = temp;
            }
            st.pop();
        }
        return ans;
    }
};