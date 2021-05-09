//find whether array is subset of another array

#include<bits/stdc++.h>
using namespace std;
string isSubset(int arr1[], int arr2[], int n, int m){
    map<int,int> mi;
    for(int i=0;i< n;i++) {
        mi[arr1[i]]++;
    }
    int count=0;
    for(int i=0 ;i<m; i++){
        if(mi.find(arr2[i]) != mi.end()) count++;
    }
    return ( count==m ? "Yes": "No");
}
int main(){

    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0;i< n;i++) cin>>arr1[i];
    for(int i=0;i< m ;i++) cin>>arr2[i];

    cout<<isSubset(arr1, arr2 , n, m);
}