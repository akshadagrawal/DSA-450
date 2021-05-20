//move last element to first


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
    Node * reverse();
    Node* moveLastToFirst();
    Node* pushBegin(int x);
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
Node* SLL::moveLastToFirst(){
    Node * p= head;
    while(p->next->next !=NULL){
        p=p->next;
    }
    Node* q= p->next;
    p->next=NULL;
    pushBegin(q->data);
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
int main(){
    SLL ll;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(5);
    ll.print();
    ll.moveLastToFirst();
    ll.print();
} 