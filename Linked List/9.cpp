//add 1 to ll

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
    Node *head;
    public: 
    SLL(){
        head = NULL;
    }
    Node* push(int val);
    Node * reverseList();
    Node*  pushBegin(int x);
    Node* addOne();
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
Node* SLL:: addOne(){
    
    reverseList();
        Node* p =head;
        int carry=0;
        carry=(head->data+1)/10;
        //cout<<carry;
        head->data = (head->data+ 1)%10;
        //cout<<head->data;
        p=p->next;
        while(p!=NULL){
            int num= p->data;
            p->data =(num+ carry)%10;
            carry= (num+carry)/10;
            p=p->next;
        }
       
        reverseList();
         if(carry) pushBegin(carry);
    
        return head;
    
}
int main(){
    SLL ll;
    ll.push(9);
    ll.push(9);
    ll.push(9);
    //ll.push(5);
    ll.print();
    ll.addOne();
        ll.print();

} 