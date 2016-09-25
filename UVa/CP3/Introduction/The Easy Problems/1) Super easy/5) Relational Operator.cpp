#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int N;
    long long int a, b;
    char Target;
    cin>>N;
    for(int n=0; n<N; n++){
        cin>>a>>b;
        if(a == b)
            Target='=';
        else if(a > b)
            Target='>';
        else
            Target='<';
        cout<<Target<<endl;
    }
    return 0;
}
