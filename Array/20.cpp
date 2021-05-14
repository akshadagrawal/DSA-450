//alternate negative and positie elements

#include<bits/stdc++.h>
using namespace std;
#define space " "

void alternate(int arr[],int n){
    int negCount= 0;
    int posCount=0;
    for(int i=0;i <n;i ++) {
        if(arr[i] >=0 ) posCount ++;
        else negCount++;
    }

    sort(arr, arr+n);

    if(negCount <= posCount){
        if(negCount%2==1){
            for(int i=1;i <negCount; i+=2){
                swap(arr[i], arr[negCount+i]);
            }
        }
        else {
             for(int i=1;i <=negCount; i+=2){
                swap(arr[i], arr[negCount+i-1]);
            }
        }
    }
    else {
        reverse(arr, arr+n);
        if(posCount%2==1){
            for(int i=1; i< posCount; i+=2){
                swap(arr[i], arr[i+posCount]);
            }
        }
        else {
            for(int i=1; i<=posCount; i+=2){
                swap(arr[i], arr[i+posCount-1]);
            }
        }
    }


}
int main(){
    int n;
     cin>>n;
    int arr[n];
    for(int i=0;i <n;i++) cin>>arr[i];

    alternate(arr, n);
    for(int i=0;i <n;i++) cout<<arr[i]<<space;



}