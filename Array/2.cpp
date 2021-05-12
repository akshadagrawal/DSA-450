// find minimum and maximum in an array using divide and conquer

#include<bits/stdc++.h>
using namespace std;
pair<int, int> minmax(int arr[], int left, int right){
    int n=right- left+1;
    if(n==2){
        if(arr[left] > arr[ right]) return make_pair(arr[right], arr[left]);
        else return make_pair(arr[left], arr[right]);
    }
    if(n==1) {
         return make_pair(arr[left], arr[left]);
    }
    int mid= left+ (right-left)/2;
    pair<int,int> pleft, pright,pactual;
    pleft= minmax(arr, left ,mid);
    pright= minmax(arr, mid+1, right);

    if(pleft.first < pright.first) pactual.first= pleft.first;
    else pactual.first= pright.first;

    if(pleft.second > pright.second) pactual.second= pleft.second;
    else pactual.second= pright.second;

    return pactual;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    pair<int,int> p;
    p= minmax(arr,0, n-1);
    cout<<p.first << " "<<p.second;

}