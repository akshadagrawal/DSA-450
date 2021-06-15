//height of a tree
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
    int lengthTree( Node* root);
    int lengthTreeRec( Node* root);

    public: 
        Tree(){
            root = NULL;
        }
        void makeTree();
        Node* createTree();
        void printTree();
        int lengthTree();       
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
int Tree::lengthTree(){
    // return lengthTree(root);
    return lengthTreeRec(root);
}
int Tree:: lengthTree(Node* root){
    int len=0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0;i <n;i++){
            Node* p= q.front();
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        len++;
    }
    return len;
}
int Tree:: lengthTreeRec(Node* root){
    if(root == NULL ) return 0;
    return 1+ max(lengthTreeRec(root->left), lengthTreeRec(root->right));
}
int main(){
    Tree t;
    /*
                1
            2       3
          4   5   6  
    */
    t.makeTree();
    //t.createTree();
    t.printTree();
    cout<<endl<<t.lengthTree();
}