//word break
#include<bits/stdc++.h>
using namespace std;
int wordBreak(string s, vector<string> &arr) {
    sort(arr.begin(), arr.end());
    string x="";
    for(int i=0; i<s.length(); i++){
        x+=s[i];
        if(binary_search(arr.begin(), arr.end(), x)) x="";
    }
    if(x != "") return 0;
    return 1;
}
int main(){
    string s="ilike";
    vector<string> arr={ "i", "like", "sam", "sung", "samsung", "mobile","ice","cream", "icecream", "man", "go", "mango" };
    cout<<wordBreak(s, arr);
}