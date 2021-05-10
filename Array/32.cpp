//3 way partitio aroud given value

#include<bits/stdc++.h>
using namespace std;
int findLessThan(vector<int> & arr, int left, int right, int value ){
    int j=left;
    for(int i=left; i<=right;i++){
        if(arr[i] <value){
            swap(arr[j], arr[i]);
            j++;
        }
    }
    for(int i=left; i<=right;i++){
        if(arr[i] ==value){
            swap(arr[j], arr[i]);
            j++;
        }
    }
    return j;
}
void findArray(vector<int>& arr, int n, int a, int b){
    int partition= findLessThan(arr, 0, n-1, a);
    findLessThan(arr, partition, n-1, b);
}
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> arr;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    findArray(arr, n, a, b);
    for(int i=0; i<n;i++) cout<<arr[i]<<" ";

    
}