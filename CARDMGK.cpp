#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int count=0;
		for(int i=0; i<n-1; i++){
			if(a[i]>a[i+1]){
				count++;
				if(count>1) break;
			}
		}
		if(count==0) cout<<"YES"<<'\n';
		else if(count>1 || a[0]<a[n-1]) cout<<"NO"<<'\n';
		else cout<<"YES"<<'\n';

	}
	return 0;
}