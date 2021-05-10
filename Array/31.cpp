// // smallest subarray with sm greater than given value

#include <iostream>
using namespace std;
int smallestSubWithSum(int arr[], int n, int x){
    int curr_sum = 0, min_len = n + 1;
    int start = 0, end = 0;
    while (end < n) {
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
        while (curr_sum > x && start < n) {
            if (end - start < min_len)
                min_len = end - start;
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
 
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
     for(int i=0;i<n;i++) cin>>arr[i];
     cout<<smallestSubWithSum(arr, n, x);
}