#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=0; t<T; t++){
        int n, maxV=0;
        cin>>n;
        while(n--){
            int num;
            cin>>num;
            if(num>maxV){
                maxV=num;
            }
        }
        cout<<"Case "<<t+1<<": "<<maxV<<endl;
    }
    return 0;
}
