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
        
        vector<int> points;

        int prev_val = head -> val;
        int next_val = temp -> next -> val;
        int ind = 2;

        while(temp && temp -> next){
            if((temp -> val > prev_val && temp -> val > next_val) || (temp -> val < prev_val && temp -> val < next_val)){
                points.push_back(ind);
            }
            ind++;
            prev_val = temp -> val;
            temp = temp -> next;

            if(!temp -> next) break;
            next_val = temp -> next -> val;
        }

        if(points.size() <= 1) return ans;

        int mini = INT_MAX , maxi = INT_MIN;
        sort(points.begin() , points.end());

        maxi = points[points.size() - 1] - points[0];

        for(int i = 1 ; i < points.size() ; i++){
            int diff = points[i] - points[i-1];
            mini = min(mini , diff);
        }

        ans[0] = mini;
        ans[1] = maxi;

        return ans;
    }
};