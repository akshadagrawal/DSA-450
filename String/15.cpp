//find next number greater than given number
#include<bits/stdc++.h>
using namespace std;
string nextPermutation(string arr){
    int i, j, k;
    for(i=arr.size()-1; i>0; i--){
        if(arr[i] > arr[i-1]) break;
    }
    if(i==0){
        sort(arr.begin(), arr.end());
        return arr;
    } 
        
    int x= arr[ i-1];
    k=i;
    for(j= i+1; j< arr.size(); j++){
        if (arr[j] > x && arr[j] < arr[i]) k=j;
    }
    swap(arr[i-1], arr[k]);
    sort(arr.begin() + i, arr.end());
    return arr;
}
int main(){
    string s;
    cin>>s;
    s= nextPermutation(s);
    //next_permutation(s);
    cout<<s;
}