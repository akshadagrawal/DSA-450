//find if there is subarray with sum= 0;

#include<bits/stdc++.h>
using namespace std;
bool isSumZero(int arr[], int n){
    unordered_set<int> s;
    int sum=0;
    for(int i=0;i <n;i++){
        sum+=arr[i];
        if(sum==0) return true;
        s.insert(sum);
    }
     return ( s.size()== n ? false : true);
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i <n;i++) cin>>arr[i];
    cout<<isSumZero(arr, n);
}