//Spiral traversal of matrix
#include<bits/stdc++.h>
using namespace std;
vector<int> spiral(vector<vector<int>> matrix, int r, int c){
    vector<int> arr;
    int k=0, l=0;
    while( k< r && l < c){
        for(int i = l; i<c; i++) arr.push_back(matrix[k][i]);
        k++;
        for(int i=k; i< r; i++) arr.push_back(matrix[i][c-1]);
        c--;
        if(k < r) {
            for(int i= c-1; i>=l; i--) arr.push_back(matrix[r-1][i]);
            r--;
        }
        if(l < c) {
            for(int i= r-1; i>=k; i--) arr.push_back(matrix[i][l]);
            l++;
        }
    }
    return arr;
}
int main() {
    int r,c;
    cin>>r>>c;
    vector<vector<int> > matrix(r); 

    for(int i=0; i<r; i++){
        matrix[i].assign(c, 0);
        for( int j=0; j<c; j++){
                cin>>matrix[i][j];
        }
    }
    vector<int> ans= spiral(matrix, r, c);
    for( auto x : ans) cout<<x<<" ";
}
  
