#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int a[n];
        unordered_map <int,int> b;
        for(int i=0 ;i<n; i++) cin>>a[i];
        int temp;
        for(int i=0; i<n; i++){
            cin>>temp;
            b[a[i]]+=temp;
        }
        int mini=b[a[0]];
        for(auto x:b) {
            mini=min(mini, x.second);
        }
        cout<<mini<<'\n';
    }
}