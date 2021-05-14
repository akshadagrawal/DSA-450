//Remove duplicates from ll unsorted
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
    Node *p= head,*r=head, *q;
    int x= p->data;
    map<int,int> m;
    m[head->data]++;
    p=p->next;
    while(p!=NULL ){
        if(m.find(p->data) != m.end()){
            q=p->next;
            r->next=q;
            p=r->next;
        }
        else {
            m[p->data]++;
            p=p->next;
            r=r->next;
        }
         
    }
}
int main(){
    SLL ll;
    ll.push(5);
    ll.push(2);
    ll.push(2);
    ll.push(4);
    ll.print();
    ll.removeDuplicates();
    ll.print();
} 