#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> *arr = new vector<int> ;
    for(int i=0; i< matrix.size(); i++) {
        for(int j=0; j< matrix[0].size(); j++) arr->push_back(matrix[i][j]);
    }
    return binary_search(arr->begin(), arr->end(), target);
    }
int main(){
    vector<vector<int> > matrix;
    int m, n;
    cin>>m>>n;
    for(int i=0;i <m;i ++){
        vector<int> v;
        for(int j=0; j< n; j++ ) {
            int x;
            cin>>x;

            v.push_back(x) ;
        }
        matrix.push_back(v);
    }   
    int x;
    cin>>x;
    cout<<searchMatrix(matrix,x);
}