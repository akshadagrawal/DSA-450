//first and last occurence of x

#include<bits/stdc++.h>
using namespace std;
vector<int> fun(int arr[], int n, int x){
     int right= n-1,left=0, rindex=-1,lindex=-1;
    int i=0;
    while(left <= right) {
        int mid =(left+ right)/2;
        //cout<<arr[mid]<<" "<<arr[left]<<" "<<arr[right]<<endl;
        if( arr[mid] == x) {
            right= mid-1;
            lindex= mid;
        }
        else if( x < arr[mid]) {
            right = mid-1;
        }
        else {
            left= mid+1;
        }
    }
    left= 0; right=n-1;
    while(left <= right) {
        int mid =(left+ right)/2;
        //cout<<arr[mid]<<" "<<arr[left]<<" "<<arr[right]<<endl;
        if( arr[mid] == x) {
            left= mid+1;
            rindex= mid;
        }
        else if( x < arr[mid]) {
            right = mid-1;
        }
        else {
            left= mid+1;
        }
    }
    vector<int> xy= {lindex,rindex};
    return xy;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++) cin>>arr[i];
    int x;
    cin>>x;
    vector<int> v= fun(arr,n,x);
    for(auto y: v) cout<<y<<" ";
}