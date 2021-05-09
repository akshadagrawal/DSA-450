// find factorial of a large number

#include<bits/stdc++.h>
using namespace std;
void multiply(vector<int> &res, int x, int &size){
    int carry=0;
    for(int i=0;i<size; i++){
        int product= res[i] * x + carry;

        res[i]= product % 10;
        carry= product / 10;
    }

    while(carry){
        res.push_back(carry%10);
        carry /=10;
        size++;
    }
}
vector<int> factorial(int n){
    vector<int> res;
    int size= 1;
    res.push_back(1);

    for(int i=2; i<=n;i++){
        multiply (res, i, size);
    }
     return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> ans;
    ans= factorial(n);
    for( int i= ans.size()-1; i>=0; i--){
        cout<<ans[i];
    }
}