//minimun number of jumps to reach end of array

#include<bits/stdc++.h>
using namespace std;
#define intt long long 



int minJumps(int arr[], int n , int&count){
   if(n<=1)  return count  ;
    if(arr[0]==0) return -1;
    int i, temp=0;
    for(i=0; i< n; i++){
        if(arr[i] >= n-i-1 && arr[i]!=0 && i!= n-1){
            temp=1;
            break;
        }
    }
    if(!temp || i==n) return -1;
    count++;
    return minJumps(arr,i+1, count );
}
int main(){
    int t=100;
    while(t--){
       
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int count=0;
        count= minJumps(arr, n, count);
        cout<<count<<endl;


    }
    
}


