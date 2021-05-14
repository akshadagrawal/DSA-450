//Remove duplicates from ll sorted
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
    void removeDuplicates();
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

void SLL:: removeDuplicates(){
    Node *p= head,*r=head;
    int x= p->data;
    p=p->next;
    while(p!=NULL ){
        
        if(x==p->data){
            struct Node *q=p->next;
            r->next= q;
            p= r->next;
            
        }else{
            x=p->data;
            r=r->next;
            p=p->next;
        }     
    }
}
int main(){
    SLL ll;
    ll.push(20);
    ll.push(30);
    ll.push(19);
    ll.push(5);
    ll.push(5);
    ll.print();
    ll.removeDuplicates();
    ll.print();
} 