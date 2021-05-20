//deletion from a cll

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node (){
            next= NULL;
        }
};
class SLL{
    public:
        Node *head;
        SLL(){
            head= NULL;
        }
        Node *push(int x);
        void print();
        int length();
        Node* deleteAtPos(int pos);

};
Node* SLL:: push(int x){
    if(head== NULL){
        head= new Node();
        head->data=x;
    }
    else {
        Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        Node *q= new Node();
        q->data= x;
        p->next= q;
    }
    return head;
}
void SLL:: print(){
    Node *p =head;
    do{
        cout<<p->data<<"->";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}
int SLL:: length(){
    Node* p=head;
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);

    return len;
}
Node* SLL:: deleteAtPos(int pos){
    if(pos< 0 || head==NULL) return NULL;
    if((pos% length())==1){ 
        Node* p= head;
        p=p->next;
        while(p->next!= head) p=p->next;
        Node *q= head;
        p->next= q->next;
        head= head->next;  
        delete(q); 
    }
    else {
        Node *p = head;
        for(int i=1;i < (pos-1)%length(); i++){
            p=p->next;
        } 
        Node *q= p->next;
        p->next= q->next;
        delete q;
    }
    return head;
}
int main(){
    SLL ll;
    ll.push(2);
    ll.push(3);
    ll.push(1);
    ll.push(3);
    ll.push(2);
    ll.head->next->next->next->next->next= ll.head;
    ll.deleteAtPos(6);
    ll.print();
}
