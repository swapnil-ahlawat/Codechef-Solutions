#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t){
		int n;
		cin>>n;
		bitset<10> s1;
		while(n){
		    string s2;
		    cin>>s2;
		    s1=s1^bitset<10>(s2);
		
		    n--;
		}
	    cout<<s1.count()<<"\n";
	t--;
	}
}
