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
    int lengthLL(ListNode *A)
    {
        int l=0;
        while(A!=nullptr)
        {
            A=A->next;
            l++;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=lengthLL(headA);
        int l2=lengthLL(headB);
        
        ListNode *biggerList=l1>l2 ? headA:headB;
        ListNode *smallerList=l1>l2 ? headB:headA;
        
        int diff=max(l1,l2)-min(l1,l2);
         while(diff-- > 0)
         {
             biggerList=biggerList->next;
         }
        
        while(biggerList!=smallerList){
             biggerList=biggerList->next;
             smallerList=smallerList->next;
        }
        return biggerList;
    }
};
