//find pairs with sum=k

#include<bits/stdc++.h>
using namespace std;
int getCount(int arr[], int n ,int k){
    unordered_map<int , int> m;
    unordered_map<int , int> :: iterator itr;

    int count=0;
    for(int i=0;i<n;i++){
        itr= m.find(k-arr[i]);
        if(itr != m.end()) count+= itr->second;
        m[arr[i]]++;
        
    }
    return count;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i< n;i++) cin>>arr[i];
    cout<<getCount(arr, n, k);
}