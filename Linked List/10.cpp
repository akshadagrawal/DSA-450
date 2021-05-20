//Adding 2 linked lists

#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node *next;
        Node(){
            next=NULL;
        }
};
class SLL{
    
    public: 
    Node *head;
    SLL(){
        head = NULL;
    }
    Node* push(int val);
    Node * reverseList();
    Node*  pushBegin(int x);
    Node* add(SLL ll);
    void print();

};
Node *SLL:: push(int val){
    if(head==NULL){
         head= new Node();
         head->data= val;
    }
    else {
        Node *p=head;
        while(p->next!=NULL) p= p->next;
        Node *q;
        q= new Node();
        q->data= val;
        p-> next= q;  
    }
    return head;
    
}
void SLL:: print(){
    Node *p=head;
    while(p!=NULL) {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
Node * SLL:: reverseList(){
   Node *prev= NULL,*next=NULL, *current= head;
   while(current!=NULL){
       next= current->next;
       current->next= prev;
       prev=current;
       current=next;
   }
   head= prev;
   return head;  
}
Node *SLL:: pushBegin(int x){
    if(head==NULL) push(x);
    Node*p =new Node();
    p->data=x;
    p->next= head;
    head=p;
    return head;
}
Node* SLL:: add(SLL ll){
        SLL ll3;
        reverseList();
        ll.reverseList();
        Node* p =head, *q=ll.head;
        int carry=0;
        while(p!=NULL && q!=NULL){
            int num1= p->data, num2=q->data;
            int num3= (num1+num2+carry)%10;
            carry= (num1+num2+carry)/10;
            ll3.push(num3);
            p=p->next;
            q=q->next;
        }
        while(p!=NULL){
            int num1= p->data;
            int num2= (num1+carry)%10;
            carry= (num1+carry)/10;
            ll3.push(num2);
            p=p->next;
        }
         while(q!=NULL){
            int num1= q->data;
            int num2= (num1+carry)%10;
            carry= (num1+carry)/10;
            ll3.push(num2);
            q=q->next;
        }
        ll.reverseList();
        reverseList();
        ll3.reverseList();
        if(carry) ll3.pushBegin(carry);
    
        return ll3.head;
    
}
int main(){
    SLL ll1, ll2, ll3;
    ll1.push(5);
    ll1.push(0);
    ll1.push(0);
    ll2.push(5);
    ll2.push(0);
    ll2.push(0);
    //ll.push(5);
    ll1.print();
    ll2.print();

    ll3.head=ll1.add(ll2);
    ll3.print();
    

} 