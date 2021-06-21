//Balancing the brackets
#include<bits/stdc++.h>
using namespace std;
int countRev(string str){
    int len = str.length();
    if (len%2)
        return -1;
    stack<char> s;
    for (int i=0; i<len; i++){
        if (str[i]=='}' && !s.empty()){
            if (s.top()=='{')
                s.pop();
            else
                s.push(str[i]);
        }
        else
            s.push(str[i]);
    }
    int red_len = s.size();
    int n = 0;
    while (!s.empty() && s.top() == '{'){
        s.pop();
        n++;
    }
    return (red_len/2 + n%2);   
}
int main(){
    string s;
    cin>>s;
    cout<<countRev(s);

}