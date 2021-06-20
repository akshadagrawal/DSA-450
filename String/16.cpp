//Parenthesis problem
#include<bits/stdc++.h>
using namespace std;
bool isBalanced(string x){
    char a= '[', A= ']' , b= '{' , B= '}' , c='(', C=')';
    int ax=0,bx=0,cx=0;
    for(int i=0 ;i < x.length(); i++){
        if(x[i] == a) ax++;
        else if( x[i] == b) bx++;
        else if( x[i] == c) cx++;
        else if(x[i] == A) ax--;
        else if(x[i]==B) bx--;
        else if(x[i] == C) cx--;
            
        if(ax <0 || bx <0 || cx <0) return false;
    }
        
    if(ax==0 && bx==0 && cx==0) return true;
    return false;
}
int main(){
    string s;
    cin>>s;
    cout<<isBalanced(s);
}