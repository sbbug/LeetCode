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


        ListNode *res =new ListNode(-1);
        ListNode * temp = NULL;

        ListNode* a = res;

        int carry=0;

        while(l1!=NULL && l2!=NULL){

           temp =new ListNode(-1);

           if((l1->val+l2->val+carry)>=10){

               temp->val = (l1->val+l2->val+carry)%10;
               carry=1;

           }else{

               temp->val = (l1->val+l2->val+carry);
               carry=0;

           }

           if(a->val==-1){
               a->val = temp->val;
           } else{
                a->next = temp;
                a = a->next;
           }


           l1 = l1->next;
           l2 = l2->next;
        }

        while(l1){

            temp = new ListNode(-1);


            if((carry+l1->val)>=10){

                temp->val=(carry+l1->val)%10;

                carry=1;

            }else{
                temp->val=(carry+l1->val);

                carry=0;
            }

            a->next = temp;

            a  = a->next;

            l1 = l1->next;

        }

        while(l2){
            temp = new ListNode(-1);

            if((carry+l2->val)>=10){

                temp->val=(carry+l2->val)%10;

                carry=1;

            }else{
                temp->val=(carry+l2->val);

                carry=0;
            }

            a->next = temp;

            a  = a->next;

            l2 = l2->next;


        }


        if(carry==1){
            a->next = new ListNode(1);
        }


        return res;
    }
};