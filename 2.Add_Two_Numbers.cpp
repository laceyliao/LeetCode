/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp1=l1;
        ListNode *tmp2=l2;
        ListNode *head=new ListNode(0),*res=head;
        int tmp=0;
        while(tmp1!=NULL || tmp2!=NULL) {
        	int x= (tmp1!=NULL) ? tmp1->val : 0;
        	int y= (tmp2!=NULL) ? tmp2->val : 0;
            tmp+=x+y;
            res->next= new ListNode(tmp%10) ;
            tmp/=10;
            if(tmp1!=NULL) tmp1=tmp1->next;
            if(tmp2!=NULL) tmp2=tmp2->next;
            res = res->next;
        }
        if(tmp>0) res->next = new ListNode(tmp);
        return head->next;
    }
};
