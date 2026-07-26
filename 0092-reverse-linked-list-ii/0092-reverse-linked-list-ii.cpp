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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;

        ListNode * cur = head;
        while(cur){
            v.push_back(cur -> val);
            cur = cur -> next;
        }

        reverse(v.begin() + left - 1 , v.begin() + right);
        cur = head;
        int ind = 0;

        while(cur){
            cur -> val = v[ind++];
            cur = cur -> next;
        }

        return head;
    }
};