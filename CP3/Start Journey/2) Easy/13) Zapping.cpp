#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    while(cin>>a>>b && a!=-1){
        int x = 100-(abs(b-a));
        int y = abs(b-a);
        int target = (x<y)? x : y;
        cout<<target<<endl;
    }
    return 0;
}
