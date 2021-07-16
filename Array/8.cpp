//max sum contiguos array (kadanes algorithm)

#include<bits/stdc++.h>
using namespace std;
int findMaxSum(int arr[], int n){
    int maxSum= INT_MIN;
    int maxSumModifier= 0;
     for(int i=0;i < n;i ++){
         maxSumModifier += arr[i];
         maxSum= max( maxSum, maxSumModifier);
         if( maxSumModifier <0) maxSumModifier= 0; 
     }
     return maxSum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<findMaxSum(arr,n);
}