// C++ program to find median of a matrix sorted row wise

#include<bits/stdc++.h>
using namespace std;
void fun(vector<vector <int>> & matrix, int r, int c){
    int mini = INT_MAX, maxi= INT_MIN;

    for(int i=0; i< r; i++) {
        for(int j=0; j <c; j++) {
            if( mini > matrix[i][j]) mini= matrix[i][j];
            if ( maxi < matrix[i][j]) maxi= matrix[i][j];
        }
    }

    int pos= ( r* c + 1) / 2;
    while( mini < maxi) {
        int mid= (mini + maxi)/2;
        
        vector<int> :: iterator itr;
        int place=0;
        for(int i=0 ;i < r; i++) {
            itr= upper_bound ( matrix[i].begin(), matrix[i].begin() + c, mid);
            place += itr - matrix[i].begin();
        }
        if(place  < pos)  mini= mid+1;
        else maxi = mid;
    }

    cout<<"Median is : " <<maxi;
}
int main(){
    vector<vector<int> > matrix;
    int m, n;
    cin>>m>>n;
    for(int i=0;i <m;i ++){
        vector<int> v;
        for(int j=0; j< n; j++ ){
            int x;
            cin>>x;

            v.push_back(x) ;
        }
        matrix.push_back(v);
    }   

    fun(matrix, m, n);

}