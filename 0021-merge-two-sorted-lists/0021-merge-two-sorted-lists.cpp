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
        ListNode* start = new ListNode(0);
        ListNode* end = start;

        while (list1 != nullptr && list2 != nullptr){
            if(list1-> val <= list2->val){
                end->next = list1;
                list1 = list1 -> next;
            }else{
                end -> next = list2;
                list2 = list2 -> next;
            }
            end = end->next;
        }
        if (list1 != nullptr){
            end ->next =list1;
        }else {
            end ->next =list2;
        }
        return start->next;
    }
};