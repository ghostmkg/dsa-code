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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* dummyNode=new ListNode(-1);
        ListNode* sumlist;
        sumlist=dummyNode;
       int carry=0;
      while(l1!=nullptr || l2!=nullptr)  
      {
        // aise integer 
        int x=(l1!=nullptr) ? l1->val:0;
        int y=(l2!=nullptr) ? l2->val:0;
       int sum=carry;
        if(l1!=nullptr)
        {
            sum=carry+x;
        }
        if(l2!=nullptr)
        {
            sum=carry+y;
        }
        sum=x+y+carry;
         carry=sum/10;
       sumlist->next =new ListNode(sum%10);
        // carry=sum/10;
        sumlist=sumlist->next;//3000
        if(l1)
        l1=l1->next;
        if(l2)
        l2=l2->next; 
      }

    if(carry>0)
    {
       sumlist->next=new ListNode(carry);
    }
    return dummyNode->next;
    }
};