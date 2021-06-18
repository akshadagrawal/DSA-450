//A Program to check if strings are rotations of each other or not

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length() != s2.length()) {cout<<"NO"; return 0;}
    string s3=s1+s1;
    if(s3.find(s2) != string::npos) cout<<"YES";
    else cout<<"NO";

}