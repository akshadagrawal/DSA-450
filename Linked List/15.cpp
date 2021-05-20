//find middle of linked list

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
    Node* findMiddle();
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
Node* SLL:: findMiddle(){
    Node* p= head;
    int length=0;
     while(p!= NULL){
         p=p->next;
         length++;
     }
     length= length/2 +1;
     p=head;
     for(int i=1; i<length;i++){
         p=p->next;
     }
    return p;
}
void SLL:: print(){
    Node *p=head;
    while(p!=NULL) {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    SLL ll, ll1;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(5);
    ll.push(5);

    ll.print();
    ll1.head=ll.findMiddle();
    ll.print();
    ll1.print();
} 