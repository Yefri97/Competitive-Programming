#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int N, Target, x;
    cin>>N;
    while(N--){
        cin>>x;
        Target = abs(((((x*567/9 + 7492)*235/47) - 498)%100)/10);
        cout<<Target<<endl;
    }
    return 0;
}
