//find kth max and min element of  an array

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,x,k;
//     cin>>n>>k;
//     set<int> s;
//     set<int> :: iterator itr;
//     for(int i=0;i<n;i++){
//         cin>>x;
//         s.insert(x);
//     }
//     //print min
//     cout<<*next(s.begin(),k-1);

//     //print max
//     itr=s.end();
//      while(k){
//          itr--;
//          k--;
//      }
//      cout<<*itr;
  
// }


//solution in expcted time compleaxivity

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],  int l, int r){
    int pivot= arr[r];
    int i=l;
    for(int j=l; j<r;j++){
        if(arr[j]<=pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int randomPartition(int arr[], int l, int r){
    int pivot= rand()%(r-l+1);
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l,r);
}
int kthSmallest(int arr[], int l,int r, int k){
    if( k>0 && k<= r-l+1){
        int pos = randomPartition(arr,l, r);

        if(pos-l == k-1 ) return arr[k];
        else if(pos-l > k-1)  return kthSmallest(arr, l, pos-1, k);
        else return kthSmallest(arr, pos+1, r, k+l -(pos+1) )   ; 
    }
    return INT_MAX;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=  kthSmallest(arr, 0, n-1, k);
    cout<<ans;
}