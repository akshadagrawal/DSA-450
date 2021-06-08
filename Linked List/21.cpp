//find pair sum in given sorted DLL

#include<bits/stdc++.h>
using namespace std;
class Node{ 
    public: 
        int data;
        Node *next;
        Node *prev;
        Node(){
            next=NULL;
            prev=NULL;
        }
};
class DLL{
    Node *head;
    public:
        DLL(){
            head= NULL;
        }
        Node *push(int x);
        void print();
        void findSum(int sum);
};
Node* DLL::push(int x){
    if(head == NULL){
        head= new Node();
        head->data= x;
    }
    else {
        Node *p= head;
        while(p->next != NULL) p=p->next;
        Node *q= new Node();
        q->data = x;
        q->prev= p;
        p->next=q ;
    }
    return head;
}
void DLL:: print(){
    Node *p = head;
    while(p!=NULL){
        cout<<p->data<<"<->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
void DLL:: findSum(int sum){
    Node *p=head;
    while(p->next!=NULL)  p=p->next;

    Node *left= head, *right=p;
    while(left->data <= right->data){
        if(sum > left-> data+ right->data) left=left->next;
        else if(sum <  left-> data+ right->data) right= right-> prev;
        else{
             cout<<"("<<left->data<<","<<right->data<<")";
             left= left->next;
             right=right->prev;
        }
    }
}
int main(){
    DLL ll;
    ll.push(1);
    ll.push(2);
    ll.push(4);
    ll.push(5);
    ll.push(6);
    ll.push(8);
    ll.push(9);
    
    ll.print();

    cout<<"Enter pair sum: ";
    int sum;
    cin>>sum;
    ll.findSum(sum);


}