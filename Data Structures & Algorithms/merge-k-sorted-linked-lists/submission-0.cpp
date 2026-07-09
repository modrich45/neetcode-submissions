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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* ans = new ListNode();
        ListNode* res = ans;
        priority_queue < pair<int, ListNode*>, vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>> pq;

        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        while (!pq.empty()) {
            ListNode* temp = pq.top().second;
            if (temp != NULL) {
                res->next = temp;
                res = res->next;
                temp = temp->next;
                if(temp!=NULL){
                    pq.push({temp->val,temp});
                }
                pq.pop();
            }
        }

        return ans->next;
    }
};
