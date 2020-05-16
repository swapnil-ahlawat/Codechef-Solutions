#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    long long int k;
	    cin>>n>>k;
	    long long int temp, sum=0;
	    for(int i=0; i<n; i++){
	        cin>>temp;
	        sum+=temp;
	    }
	    cout<<sum%k<<endl;
	}
	// your code goes here
	return 0;
}
