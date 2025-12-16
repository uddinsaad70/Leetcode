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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        ListNode* cur = head;
        while(cur){
            while(!st.empty() && st.top()<cur->val){
                st.pop();
            }
            st.push(cur->val);
            cur = cur -> next;
        }
        ListNode* ans = nullptr;
        while(!st.empty()){
            ListNode* temp = new ListNode(st.top());
            st.pop();
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
};