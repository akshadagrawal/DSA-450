// count inversion

#include<bits/stdc++.h>
using namespace std;
int returnCount(int arr[], int n){
    int arr1[n];
    int count=0;
    int count1[n]={0};
    if(is_sorted(arr, arr+n)) return 0;
    for(int i=0;i<n;i++) arr1[i]= arr[i];
    sort(arr1, arr1+n);

    for(int i= n-1; i>=0; i--){
        for(int j=0 ;j< i; j++){
            //cout<<"Hi";
            if(arr1[i]== arr[j] && count1[j]==0){
                count1[j]=1;
                count+= i-j;
                break;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<returnCount(arr,n);
}