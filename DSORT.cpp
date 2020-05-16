#include <bits/stdc++.h>
using namespace std;

bool stringcomp(string s1, string s2){
	if(s1.length()>s2.length()) return true;
	else if(s1.length()<s2.length()) return false;
	else{
	    int i=0;
	    for(i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
	        if(s1[i]>s2[i]) return true;
	         else if(s1[i]<s2[i]) return false;
	    }
	    return true;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0; i<n; i++){
			cin>>s[i];
		}
		sort(s.begin(), s.end(), stringcomp);
		
		for(int i=0; i<n; i++){
			cout<<s[i]<<' ';
		}
		cout<<endl;

	}
	return  0;
}