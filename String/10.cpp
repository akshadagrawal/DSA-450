//print all subsequneces


// #include<bits/stdc++.h>
// using namespace std;
// void subseq(string s1, string s2){
//     if(s1 =="") {
//         cout<<s2<<endl;
//         return ;
//     }
//     subseq(s1.substr(1), s2+ s1[0]);
//     subseq(s1.substr(1), s2);
// }
// int main(){
//     string s, s1="";
//     cin>>s;
//     subseq(s,s1);
// }

#include<bits/stdc++.h>
using namespace std;
set<string> str;

void subseq(string s){
    str.insert(s);
    for(int i=0; i< s.length(); i++){
            for(int j=1; j< s.length(); j++){
                string  x=s;
                x.erase(i,j);
                str.insert(x);
                subseq(x);
            }               
    }

}
int main(){
    string s, s1="";
    cin>>s;
    subseq(s);
    for(auto x : str){
        cout<<x<<" ";
    }
    cout<<str.size();
}