// Minimize the maximum difference between heights
#include<bits/stdc++.h>
using namespace std;
int findMinDiff(int arr[] ,int n, int k) {
    sort( arr, arr+ n);
    int ans= arr[n-1]- arr[0];
    int small = arr[0]+k, big;
    if(arr[ n-1] - k  >= 0) big= arr[n-1]-k;
    else big = arr[n-1] +k; 
    for(int i=0;i<n;i++){
        int sub;
        if(arr[i]- k >=0) sub=arr[i]- k;
        else sub= arr[i]+ k;
        int add= arr[i] +k;
        if(sub >= small || add <= big) continue; 
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0 ;i<n ;i++) cin>>arr[i];
    cout<<endl<<findMinDiff(arr, n, k);
}