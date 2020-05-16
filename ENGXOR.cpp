#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t,n,q,p;
    cin>>t;
    while(t--){
        cin>>n>>q;
        int a[n];
        int odd=0, even=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(__builtin_popcount(a[i])%2) odd++;
            else even++;
        }
        while(q--){
            cin>>p;
               if(__builtin_popcount(p)%2) cout<<odd<<' '<<even<<'\n'; 
               else cout<<even<<' '<<odd<<'\n';
        }
        
    }
    
}