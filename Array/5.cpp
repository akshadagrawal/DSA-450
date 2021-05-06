//Move negative elements to left and positive to right

#include<bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n){
    list<int> l;
    for(int i=0;i<n;i++){
        if(arr[i]< 0) l.push_front(arr[i]);
        else l.push_back(arr[i]);
    }
    int i=0;
    for(auto x: l){
        arr[i]= x;
        i++;
    }
   
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];    
    rearrange(arr, n);
     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

