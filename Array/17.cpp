//best time to buy and sell stock

#include<bits/stdc++.h>
using namespace std;
int maxProfit (vector<int> &prices ){
    int n= prices.size();
    if(is_sorted(prices.begin(),prices.end(), greater<int>())) return 0;
    else {
        int maxi=0;
        int assume= prices[n-1];
        
        for(int i= n-1; i>=0; i--){
            maxi= max( maxi, assume- prices[i]);
            assume=max( assume, prices[i]);
        }
        return maxi;       
    }
}
int main(){
    int n,x;
    cin>>n;
    vector<int> prices;
    for(int i=0;i<n;i++) {
        cin>>x;
        prices.push_back(x);
    }
    int ans= maxProfit(prices);
    cout<<ans;
}