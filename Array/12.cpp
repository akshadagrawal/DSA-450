//merge 2 arrays without using extra space

#include<bits/stdc++.h>
using namespace std;
void merge( int arr1[], int arr2[], int n, int m){
    int *arr= new int [n+m];
    int i=0, j=0, k=0;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            arr[k]= arr1[i];
            i++;
        }
        else{
            arr[k]= arr2[j];
            j++;
        }
        k++;
    }
    while(i < n) {
        arr[k]=arr1[i];
        i++;k++;
    }
    while(j < m){
        arr[k]=arr2[j];
        j++;k++;
    }
    for(int i=0;i <n;i++){
        arr1[i]= arr[i];
    }
    for(int i=0;i<m;i++){
        arr2[i]= arr[n+i];
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m]; 
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];

    merge(arr1, arr2, n, m);
    for(int i=0;i<n;i++) cout<<arr1[i]<<" ";
    cout<<endl;
    for(int i=0;i<m;i++) cout<<arr2[i]<<" ";

    
}