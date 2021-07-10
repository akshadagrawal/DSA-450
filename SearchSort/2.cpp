#include<bits/stdc++.h>
using namespace std;
vector<int> fun(int arr[], int n) {
	vector<int> x;
	for(int i=0 ;i< n; i++) {
	    if(i+1==arr[i]) {x.push_back(arr[i]);
	    }
	}
	return x;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n ;i++) cin>>arr[i];
    vector<int> v= fun(arr,n);
    for(auto y: v) cout<<y<<" ";
}