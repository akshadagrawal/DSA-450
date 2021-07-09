//Sort a matrix

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> sortedMatrix(int n, vector<vector<int>> &mat) {
    vector<int> m;
    for(int i=0 ;i< n; i++) {
        for(int j=0 ;j< n; j++) {
            m.push_back(mat[i][j]);
        }
    }
    sort(m.begin(), m.end());
    mat.clear();
    for(int i=0 ;i< n;i ++){
        vector<int> x;
        for(int j=0 ;j< n;j++) x.push_back(m[i*n + j]);
        mat.push_back(x);
    }
    return mat;
}
int main(){
    vector<vector<int> > matrix;
    int  n;
    cin>>n;
    for(int i=0;i <n;i ++){
        vector<int> v;
        for(int j=0; j< n; j++ ){
            int x;
            cin>>x;

            v.push_back(x) ;
        }
        matrix.push_back(v);
    }   
    sortedMatrix(n,matrix);
    for(int i=0;i <n;i ++){
        for(int j=0; j< n; j++ ){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    } 
    

}