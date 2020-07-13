// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    ll x, y, l ,r, z;
    cin>>t;
    while(t--){
        cin>>x>>y>>l>>r;
        z=x|y;
        if(x==0 || y==0){
            cout<<l<<endl;
            continue;
        }
        ll mask=1LL;
        while(mask<=r){
            mask<<=1;
        }
        mask-=1;
        int len= __builtin_popcountll(mask);
        z&=mask;
        set<ll> s;
        if((x&z)==0 || (y&z)==0){
            cout<<l<<endl;
            continue; 
        }

        if(z<=r && z>=l){    
            cout<<z<<endl;
            continue;
        }
        ll max_res=0, res, max_z=0, temp;
        for(int i=len-1; i>=0; i--){
            ll m= 1LL<<i;
            if((m&r) && (m&z)){
                temp= z&(~m);
                if(temp<=r){
                    s.insert(temp);
                }
            }
            else if(!(m&r)){
                z=z&(~m);
            }
            if(z<=r){
               s.insert(z);
            }
        }
        for(auto it=s.begin(); it!=s.end(); it++){
            z=*it;
            //cout<<z<<endl;
            for(int i=len-1; i>=0; i--){
                ll m= 1LL<<i;
                if(!(m&l) && !(m&z)){
                    temp= z|m;
                    if(temp>=l && temp<=r){
                        res= (x&temp)*(y&temp);
                        if((res>max_res)||((res==max_res)&&(temp<max_z))){
                            max_res=res;
                            max_z=temp;
                        }
                    }
                }
                else if(m&l){
                    z=z|m;
                }
                if(z<=r && z>=l){
                    res= (x&z)*(y&z);
                    if((res>max_res)||((res==max_res)&&(z<max_z))){
                        max_res=res;
                        max_z=z;
                    }
                }
            }
        }
        if((x&max_z)==0 || (y&max_z)==0 || max_z<l || max_z>r){
            cout<<l<<endl;
            continue; 
        }
        cout<<max_z<<endl;        
    } 
    
    return 0;
} 