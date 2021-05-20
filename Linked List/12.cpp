//intersecton point in y shaped linked list


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
    Node * reverse();
    void print();
    Node* findIntersection(SLL ll);

};
Node * SLL::findIntersection(SLL ll){
    Node *p= head, *q= ll.head;
    while(p!=q){
        p=p->next;
        q=q->next;

        if(p==q) return p;  
        if(p==NULL) p= ll.head;
        if(q== NULL) q=head;
    }
    return p;

}
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
int main(){
    SLL ll, ll1,ll2;
    ll.push(4);
    ll.push(1);
    ll.push(8);
    ll.push(4);
    ll.push(5);

    ll1.push(5);
    ll1.push(6);
    ll1.push(1);
    ll1.head->next->next->next= ll.head->next->next;

    ll.print();
    ll1.print();
    ll2.head=ll.findIntersection(ll1);
    ll2.print();
    
} 