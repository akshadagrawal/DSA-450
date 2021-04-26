//Reverse an array

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n/2;i++){
        swap(v[i], v[n-i-1]);
    }
   for(int i=0;i<n;i++){
        cout<<v[i];
    }
}