#include<bits/stdc++.h>
using namespace std;

long long  findMinDiff(vector<long long > &a, long long  n, long long  m){
    sort(a.begin(), a.end());
    long long  mini= INT_MAX;
    for(long long  i=0;i<n;i++){
        if(m+i-1 < n)
            mini= min(a[m+i-1]-a[i], mini);
        else break;
    }
    return mini;
}
int main(){
    long long  n,m,x;
    cin>>n>>m;
    vector<long long > a;
    for(long long  i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    } 
    long long  ans= findMinDiff(a, n, m);
    cout<<ans;
}