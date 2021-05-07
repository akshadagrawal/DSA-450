//find duplicate in aray of n+1 intergers

#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int> &nums){
    map<int, int> m;
    for(int i=0;i<nums.size();i++){
        if(m.find(nums[i]) != m.end()){
            return nums[i];
        }
        else m[nums[i]]++;
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    int x;
     for(int i=0;i<n;i++){
         cin>>x;
         v.push_back(x);
     }
     int ans= findDuplicate(v);
     cout<<ans;
}