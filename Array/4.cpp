#include<bits/stdc++.h>
using namespace std;
int sortarray(int arr[], int left, int right,  int val){
    int n= right-left+1;
    int j=left;
    while(arr[j] == val) j++;
    for(int i=j+1;i<= right;i++){
        if(arr[i] == val){
             swap(arr[i], arr[j]);
             j++;
        }
    }
    return j;
}
void sortArray(int arr[], int n){
    int pos= sortarray(arr, 0, n-1, 0 );
    pos=sortarray(arr,pos, n-1,1 );   
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sortArray(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}