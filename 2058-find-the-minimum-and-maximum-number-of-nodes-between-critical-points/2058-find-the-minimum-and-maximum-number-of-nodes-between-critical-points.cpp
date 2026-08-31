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
        
        int least_first = -1 , least_second = -1 , last = -1 , mini = INT_MAX; 

        int prev_val = head -> val;
        int next_val = temp -> next -> val;
        int ind = 2;

        while(temp && temp -> next){
            if((temp -> val > prev_val && temp -> val > next_val) || (temp -> val < prev_val && temp -> val < next_val)){
                if(least_first == -1){
                    least_first = ind;
                }

                else if(least_second == -1){
                    least_second = ind;
                    mini = ind - last;
                }

                else{
                    mini = min(mini , ind - last);
                }

                last = max(last , ind);

            }
            ind++;
            prev_val = temp -> val;
            temp = temp -> next;

            if(!temp -> next) break;
            next_val = temp -> next -> val;
        }

        if(least_first == -1 || least_second == -1 || last == -1){
            return ans;
        }

        ans[0] = mini;
        ans[1] = last - least_first;

        return ans;
    }
};