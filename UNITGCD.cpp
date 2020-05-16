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
        if(n==1) {
        	cout<<1<<endl<<1<<' '<<1<<endl;
    		//return 0;
    	}
    	else{
    	int i=1;
    	cout<<n/2<<endl;
    	while(n-i>4){
    		cout<<3<<' '<<i<<' ';
    		cout<<++i<<' ';
    		cout<<++i<<endl;
    		cout<<1<<' '<<++i<<endl;
    		i++;
    	}
    	if(i<=n){
    		if((n-i)==3){
    			cout<<3<<' '<<i<<' ';
    			cout<<++i<<' ';
    			cout<<++i<<endl;
    			cout<<1<<' '<<++i;
    			i++;
    		}
    		else if((n-i)==4){
    			cout<<3<<' '<<i<<' ';
    			cout<<++i<<' ';
    			cout<<++i<<endl;
    			cout<<2<<' '<<++i<<' ';
    			cout<<++i;
    			i++;
    		}
    		else {cout<<n-i+1<<' ';
    			while(i!=(n+1)){
    				cout<<i++<<' ';
    			}
    		}
    		cout<<endl;
    	}
    	}
    }
    return 0;
} 