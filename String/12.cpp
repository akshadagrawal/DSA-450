//split binry into substring with equal 0 and 1
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int count0=0, count1=0,count=0;
    for(int i=0 ;i< s.length(); i++){
        if(s[i]-'0'== 0)  count0++;
        if(s[i] - '0' == 1) count1++;
        if(count0==count1){
            // cout<<i<<" "<<count0<<" "<<count1<<endl;
            count++;
            count0=0;
            count1=0;
        }
        else continue;
    }
    if(count) cout<<count<<endl;
    else cout<<-1<<endl;

}