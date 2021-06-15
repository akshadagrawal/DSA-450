//Reverse Level Order

//print level order
#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left, *right;
        Node(){
            left= NULL;
            right= NULL;
        }
        Node(int x){
            data=x;
            left= NULL;
            right= NULL;
        }
};
class Tree {
    Node * root;
    void printTree(Node* );
    public: 
        Tree(){
            root = NULL;
        }
        void makeTree();
        Node* createTree();
        void printTree(); 
        void reverselevelOrder();       
};
Node* Tree::createTree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;
    Node* p= new Node(x);
    p->left= createTree();
    p->right= createTree();
    root= p;
    return root;
}
void Tree::printTree(){
    printTree(root);
}
void Tree:: printTree(Node* root){

    if(root==NULL) return;
    cout<<root->data;
    printTree(root->left);
    printTree(root->right);
}
void Tree::makeTree(){
    root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left = new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
}
void Tree::reverselevelOrder(){
    vector<int> h;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* p= q.front();
        q.pop();
        h.push_back(p->data);
        if(p->right) q.push(p->right);
        if(p->left) q.push(p->left);
    }
    reverse(h.begin(), h.end());
    for(auto x : h) cout<<x<<" ";
}
int main(){
    Tree t;
    /*
                1
            2       3
          4   5   6  
    */
    t.makeTree();
    //t.printTree();
    t.reverselevelOrder();
}