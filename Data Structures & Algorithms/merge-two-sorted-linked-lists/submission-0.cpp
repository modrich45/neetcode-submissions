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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* curr = res;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                ListNode* temp = list1;
                list1 = list1->next;
                temp->next = NULL;
                curr->next = temp;
            } else {
                ListNode* temp = list2;
                list2 = list2->next;
                temp->next = NULL;
                curr->next = temp;
            }
            curr=curr->next;
        }

        while (list1 != NULL) {
            ListNode* temp = list1;
            list1 = list1->next;
            temp->next = NULL;
            curr->next = temp;
            curr=curr->next;
        }

        while (list2 != NULL) {
            ListNode* temp = list2;
            list2 = list2->next;
            temp->next = NULL;
            curr->next = temp;
            curr=curr->next;
        }

        return res->next;
    }
};
