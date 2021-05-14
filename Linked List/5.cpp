//Remove loops from linked list
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void loopHere(Node* head, Node* tail, int position){
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}
bool isLoop(Node* head){
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    while( fast != slow){
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}
int length(Node* head){
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}
class Solution{
    public:
    int findLoopStart(Node* head)
    {
        unordered_map<Node * ,int> m;
        Node *p =head;
        int pos=0;
        m[head]++;
        while(p!=NULL){
            pos++;
            if(m.find(p->next) != m.end() ){
                return (p->next->data);
            }
              m[p->next]++;
              p=p->next;
            }
            return 0;
    }
    
    
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, num;
        cin>>n;
        
        struct Node *head, *tail,*p;
        cin>> num;
        head =new Node(num);
        tail = head;
        
        for(int i=0 ; i<n-1 ; i++){
            cin>> num;
            p= new Node(num);
            tail->next =p;
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        cout<<ob.findLoopStart(head);
        
    
    }
	return 0;
}
