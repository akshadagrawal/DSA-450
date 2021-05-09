#include<bits/stdc++.h>
using namespace std;
vector<int> findCount(int arr[], int n, int k){
    int x= n/k;
    vector<int> v;
    unordered_map<int, int> m;
    for(int i=0;i<n ;i++) m[arr[i]]++;
    for(auto y : m){
        if(y.second > x) v.push_back(y.first);
    }
    return v;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> v;
    v= findCount(arr, n, k);
}