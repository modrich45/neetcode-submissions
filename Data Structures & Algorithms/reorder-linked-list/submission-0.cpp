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
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            length++;
            s.push(temp);
            temp=temp->next;
        }
        int mid=0;
        if(length%2==0){
            mid=(length/2)-1;
            ListNode* curr=head;
            while(mid--){
                ListNode* temp=s.top();
                s.pop();
                temp->next=curr->next;
                curr->next=temp;
                curr=curr->next->next;
            }
            curr->next->next=NULL;
        }else{
            mid=(length/2);
            ListNode* curr=head;
            while(mid--){
                ListNode* temp=s.top();
                s.pop();
                temp->next=curr->next;
                curr->next=temp;
                curr=curr->next->next;
            }
            curr->next=NULL;
        }

        
    }
};
