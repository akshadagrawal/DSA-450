//code to non recursively traverse the tree

#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left, *right;
        Node(int x){
            data= x;
            left=right=NULL;
        }
};

void inorder(Node* root){
   if(root ==NULL) return;
   Node* p =root;
   stack<Node*> s;
   while(p!=NULL || !s.empty()){
       while(p!=NULL){
           s.push(p);
           p=p->left;
       }

       p=s.top();
       s.pop();
       cout<<p->data <<" ";
       p=p->right;
   }
}
void inorderRec(Node* root){
    if(root == NULL) return ;
    inorderRec(root->left);
    cout<<root->data<<" ";
    inorderRec(root->right);
}
int main(){
    /*
                1
            12      9
        5       6
    */
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);

    cout<<endl;
    inorderRec(root);
     cout<<endl;
    inorder(root);
   
}
