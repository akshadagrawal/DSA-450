//check palindrome 
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;int temp=1;
    cin>>s;
    int i=0, j=s.length()-1;
    while(i<j){
       if(s[i]!=s[j]) {
        temp=0;
        break;
       }
       i++;j--; 
    }
    temp ? cout<<"YES" : cout<<"NO";

}