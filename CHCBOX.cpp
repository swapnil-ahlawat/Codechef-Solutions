// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int w[n];
        cin>>w[0];
        int maxi=w[0];
        vector<int> v;
        v.push_back(0);
        bool same=false;
        for(int i=1; i<n; i++) {
        	cin>>w[i];
        	if(maxi!=w[i]) same=true;
        	maxi=max(maxi, w[i]);

        }
        int l, r;
        bool flag=false;
        for(int i=0; i<n; i++) {
        	if(w[i]==maxi){
        		if(flag) r=i;
        		else{
        			l=i;
        			r=i;
        			flag=true;
        		}
        		v.push_back(i);
        	}
        }
        int min_moves= max(0, (n/2)-l);
        int max_moves= n-1-r;
		int moves;        
        if(min_moves>max_moves) moves=0;
        else{
        	moves=max_moves-min_moves+1;
        }
        for(int i=1; i<v.size(); i++){
        	int diff=v[i]-v[i-1]-1;
        	if(diff<n/2) continue;
        	else{
        		moves+=diff-(n/2)+1;
        	}
        }
        if(same) cout<<moves<<endl;
     	else cout<<n-1<<endl;
     } 
    
    return 0;
} 