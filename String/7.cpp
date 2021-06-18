//Count and say problem
#include<bits/stdc++.h>
using namespace std;
string countandsay(int n){
if(n==1) return "1"; 
    string res,tmp = countandsay(n-1); 
    char c= tmp[0];
    int count=1;
    for(int i=1;i<tmp.size();i++)
        if(tmp[i]==c)
            count++;
        else{
            res+=to_string(count);
            res.push_back(c);
            c=tmp[i];
            count=1;
        }
    res+=to_string(count);
    res.push_back(c);
    return res;    
}
int main(){
    int s;
    cin>>s;
    cout<<countandsay(s);
}