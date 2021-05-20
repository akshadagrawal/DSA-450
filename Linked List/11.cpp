//intersection of two sorted linked lists

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
    void print();
    Node* findIntersection(SLL ll );

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
Node * SLL:: findIntersection(SLL ll){
    SLL ll1;
    Node *p =head;
    Node *q= ll.head;
    while(p!=NULL && q!=NULL){
        if(p->data  == q->data){
            ll1.push(p->data);
            p= p->next;
            q= q->next;
        }
        else if(p->data < q->data){
            p= p->next;
        }
        else {
            q= q->next;
        }
    }
    return ll1.head;
}
int main(){
    SLL ll1, ll2, ll3;
    ll1.push(1);
    ll1.push(2);
    ll1.push(3);
    ll1.push(4);
    ll1.push(5);
    ll1.push(6);


    ll2.push(2);
    ll2.push(4);
    ll2.push(6);
    ll2.push(8);
    

    ll1.print();
    ll2.print();
    ll3.head= ll1.findIntersection(ll2);
    ll3.print();
} 