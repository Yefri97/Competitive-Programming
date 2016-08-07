#include<bits/stdc++.h>
using namespace std;

int next_int(){
    string s;
    getline(cin, s);
    return atoi(s.c_str());
}

int main(){
    vector<int> v(110);
    int t=next_int();
    while(t--){
        int n=next_int();
        int cont=0;
        for(int i=1; i<=n; i++){
            string s;
            getline(cin, s);
            if(s=="LEFT"){
                v[i]=-1;
            }else if(s=="RIGHT"){
                v[i]=1;
            }else{
                int c=atoi(s.substr(8, s.size()-8).c_str());
                v[i]=v[c];
            }
            cont += v[i];
        }
        cout<<cont<<endl;
    }
}
/*
2
16
LEFT
SAME AS 1
SAME AS 2
SAME AS 3
SAME AS 4
SAME AS 5
SAME AS 6
SAME AS 7
SAME AS 8
SAME AS 9
SAME AS 10
SAME AS 11
SAME AS 12
SAME AS 13
SAME AS 14
SAME AS 15
19
RIGHT
SAME AS 1
SAME AS 2
SAME AS 3
SAME AS 4
SAME AS 5
SAME AS 6
SAME AS 7
SAME AS 8
SAME AS 9
SAME AS 10
SAME AS 11
SAME AS 12
SAME AS 13
SAME AS 14
SAME AS 15
SAME AS 16
SAME AS 17
SAME AS 18
*/
