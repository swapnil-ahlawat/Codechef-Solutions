// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

vector <int> v;

bool divCount(int n, int k) 
{
    int total = 0, count=0;
    for(int i=0; i<v.size() && v[i]*v[i]<=n; i++){
    	if(n%v[i]==0){
    		 count=0;
    		 while(n%v[i]==0){
    		 	n=n/v[i];
    		 	count++;
    		 }
    		 total+=count;
    		 if(total>=k) break;
    	}
    }
    if(n!=1) total++;
    return total>=k;
 }
bool isPrime(int n){
	for(int i=0; i<v.size() && v[i]*v[i]<=n; i++){
		if(n%v[i]==0) return false;
	}
return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    v.push_back(2);
    for (int p = 3; p < 1e5; p+=2) 
        if(isPrime(p)) v.push_back(p);
  	
  	//for(int i=0; i<v.size(); i++) cout<<v[i]<<endl;
    int t;
    cin>>t;
    while(t--){
        
        int x,k;
        cin>>x>>k;
        if(divCount(x,k)) cout<<1<<endl;
        else cout<<0<<endl;
        
     } 
    
    
    return 0;
} 