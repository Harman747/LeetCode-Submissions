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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1 , -1};

        if(!head || !head -> next) return ans;

        ListNode * temp = head -> next;

        if(!temp -> next) return ans;
        
        int first = -1 , current_min_diff = INT_MAX , prev_point = -1 , last = -1;

        int prev_val = head -> val;
        int next_val = temp -> next -> val;
        int ind = 2;

        while(temp && temp -> next){
            if((temp -> val > prev_val && temp -> val > next_val) || (temp -> val < prev_val && temp -> val < next_val)){
                if(first == -1){
                    first = ind;
                    prev_point = ind;
                }
                else{
                    current_min_diff = min(current_min_diff , ind - prev_point);
                    prev_point = ind;
                }
                last = ind;
            }

            prev_val = temp -> val;
            temp = temp -> next;
            if(!temp -> next) break;
            next_val = temp -> next -> val;
            ind++;
        }

        if((first == -1) || (last == first)){
            return ans;
        }

        ans[0] = current_min_diff;
        ans[1] = last - first;

        return ans;
    }
};