//find triplets in given Sorted DLL

#include<bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* prev;
        Node *next;
        Node(){
            prev= NULL;
            next=NULL;
        }
};
class DLL{
    Node *head;
    public: 
        DLL(){
            head= NULL;
        }
        Node* push(int x);
        void print();
        int findTriplet(int );
};
Node* DLL:: push(int x){
    if(head==NULL) {
        head =new Node();
        head->data= x;
    }
    else {
        Node *p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        Node *q= new Node();
        q->data= x;
        p->next=q;
        q->prev=p;
    }
    return head;
}
void DLL:: print(){
    Node* p = head;
    while(p!= NULL ){
           cout<<p->data<<"->";
            p=p->next;
    }
    // while(p!=NULL){
    //     cout<<p->data<<"->";
    //     p=p->prev;
    // }
    cout<<"NULL"<<endl;
}
int DLL:: findTriplet(int x){
    Node *p= head;
    int count=0;
    while(p!=NULL){
        int n= x - p->data;
        Node* m= head;
        Node *q=head;
        while(q->next!=NULL) q=q->next;
        while(m->data < q->data){
            if(m->data + q->data ==n) {
                count++;
                break;
            }
            else if(m->data + q->data > n) q=q->prev;
            else m=m->next;
        }
        p=p->next;

    }   
    return count/3;
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
    int x;
    cout<<"Enetr sum:" ;
    cin>>x;
    cout<<ll.findTriplet(x);

}
