//find common elements in 3 sorted arrays

#include<bits/stdc++.h>
using namespace std;
vector<int> commonElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){
    map<int, int> m;
    vector<int> v;
    unordered_set<int> s1,s2,s3;
    for(int i=0 ;i< n1;i++) s1.insert(arr1[i]);
    for(int i=0 ;i< n2;i++) s2.insert(arr2[i]);
    for(int i=0 ;i< n3;i++) s3.insert(arr3[i]);

    for( auto x: s1) m[x]++;
    for( auto x: s2) m[x]++;
    for( auto x: s3) m[x]++;

    for(auto x: m) if(x.second==3) v.push_back(x.first);

    return v;


}
int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int arr1[n1], arr2[n2], arr3[n3];
    for(int i=0;i< n1; i++) cin>>arr1[i];
    for(int i=0;i< n1; i++) cin>>arr2[i];
    for(int i=0;i< n1; i++) cin>>arr3[i];
    vector<int> ans;
    ans= commonElements(arr1, arr2, arr3, n1, n2, n3);

    for(int i=0;i < ans.size();i++) cout<<ans[i]<<" ";

}