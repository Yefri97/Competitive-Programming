#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin>>N;
    for(int n=0; n<N; n++){
        vector<string> vs(20);
        vector<int> v(20);
        for(int i=0; i<10; i++){
            cin>>vs[i];
            cin>>v[i];
        }
        int target=0;
        for(int i=0; i<10; i++){
            target = (v[i]>target)? v[i] : target;
        }
        cout<<"Case #"<<n+1<<":"<<endl;
        for(int i=0; i<10; i++){
            if(v[i]==target){
                cout<<vs[i]<<endl;
            }
        }
    }
    return 0;
}
