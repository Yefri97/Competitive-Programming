#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> s(n), song;
    song.push_back("Happy");
    song.push_back("birthday");
    song.push_back("to");
    song.push_back("you");
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int a=0, cont=0, i=0; a<(ceil(double(n)/16)*16); a++, i=(i+1)%n, cont=(cont+1)%4){
        cout<<s[i]<<": ";
        if((a-11)%16)
            cout<<song[cont];
        else
            cout<<"Rujia";
        cout<<endl;
    }
    return 0;
}
/*
17
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
*/

