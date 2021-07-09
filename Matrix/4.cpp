//find maximum number of 1's in row wise sorted matrix

#include<bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int> > arr) {
	int min =arr[0].size(), minrow=-1;
	for(int i=0; i< arr.size(); i++) {
	    int j;
	    for(j=0; j<arr[0].size(); j++){
	        if(arr[i][j]==1) break;
	    }
	    if(j < min){
	        min = j;
	        minrow= i;
	    } 
	    //cout<<minrow<<endl;
	}
	return minrow;
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
    cout<<rowWithMax1s(matrix);
}