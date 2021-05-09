// C++ program to find maximum product subarray
#include <bits/stdc++.h>
using namespace std;
long long  maxProduct(int* arr, int n)
{
    int minVal = arr[0];
    int maxVal = arr[0];
    int maxProduct = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < 0)
            swap(maxVal, minVal);

        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);

        maxProduct = max(maxProduct, maxVal);
    }

    return maxProduct;
}

int main()
{
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    cout <<maxProduct(arr, n);

    return 0;
}
