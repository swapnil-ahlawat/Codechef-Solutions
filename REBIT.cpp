// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mod 998244353
struct opr{
  long long int num[4];
  long long int den;

  void start(){
    den=4;
    for(int i=0; i<4; i++) num[i]=1;
  }
};

long long int power(long long int den, long long int p){
  if(p==0) return 1;
  long long int temp= (power(den, p/2)%mod);
  temp=(temp*temp)%mod;
  if(p%2==1) return (temp*(den%mod))%mod;
  else return temp%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        
        string s;
        cin>>s;
        stack<opr> rando;
        stack<char> rator;
        opr op1, op2, temp;
        char oper;
        for(int i=0; i<s.length(); i++){
          if(s[i]=='(') continue;
          else if(s[i]=='#'){
            op1.start();
            rando.push(op1);
          }
          else if(s[i]==')'){
            op1=rando.top();
            rando.pop();
            oper=rator.top();
            rator.pop();
            op2=rando.top();
            rando.pop();
            temp.start();
            if(oper=='|'){
              temp.num[0]= (op1.num[0]*op2.num[0])%mod;
              temp.num[1]= ((op1.num[1]*(op2.num[0]+op2.num[1]+op2.num[2]+op2.num[3]))%mod+ (op1.num[0]*op2.num[1])%mod+(op1.num[2]*(op2.num[1]+op2.num[3]))%mod+(op1.num[3]*(op2.num[1]+op2.num[2]))%mod)%mod;
              temp.num[2]= ((op1.num[0]*op2.num[2])%mod + (op1.num[2]*(op2.num[0]+op2.num[2]))%mod)%mod;
              temp.num[3]= ((op1.num[0]*op2.num[3])%mod + (op1.num[3]*(op2.num[0]+op2.num[3]))%mod)%mod;

              temp.den=(op1.den*op2.den)%mod;
              rando.push(temp);
            }
            else if(oper=='&'){
              temp.num[1]= (op1.num[1]*op2.num[1])%mod;
              temp.num[0]= ((op1.num[0]*(op2.num[0]+op2.num[1]+op2.num[2]+op2.num[3]))%mod+ (op1.num[1]*op2.num[0])%mod+(op1.num[2]*(op2.num[0]+op2.num[3]))%mod+(op1.num[3]*(op2.num[0]+op2.num[2]))%mod)%mod;
              temp.num[2]= ((op1.num[1]*op2.num[2])%mod + (op1.num[2]*(op2.num[1]+op2.num[2]))%mod)%mod;
              temp.num[3]= ((op1.num[1]*op2.num[3])%mod + (op1.num[3]*(op2.num[1]+op2.num[3]))%mod)%mod;

              temp.den=(op1.den*op2.den)%mod;
              rando.push(temp);
            }
            else{
              temp.num[0]= ((op1.num[0]*op2.num[0])%mod+(op1.num[1]*op2.num[1])%mod+(op1.num[2]*op2.num[2])%mod+(op1.num[3]*op2.num[3])%mod)%mod;
              temp.num[1]= ((op1.num[0]*op2.num[1])%mod+(op1.num[1]*op2.num[0])%mod+(op1.num[2]*op2.num[3])%mod+(op1.num[3]*op2.num[2])%mod)%mod;
              temp.num[2]= ((op1.num[0]*op2.num[2])%mod+(op1.num[1]*op2.num[3])%mod+(op1.num[2]*op2.num[0])%mod+(op1.num[3]*op2.num[1])%mod)%mod;
              temp.num[3]= ((op1.num[0]*op2.num[3])%mod+(op1.num[1]*op2.num[2])%mod+(op1.num[2]*op2.num[1])%mod+(op1.num[3]*op2.num[0])%mod)%mod;

              temp.den=(op1.den*op2.den)%mod;
              rando.push(temp);
            }
          }
          else{
            rator.push(s[i]);
          } 
        }
        temp=rando.top();
        rando.pop();

        long long int ans= power(temp.den, mod-2);

        cout<<(temp.num[0]*ans)%mod<<' ';
        cout<<(temp.num[1]*ans)%mod<<' ';
        cout<<(temp.num[2]*ans)%mod<<' ';
        cout<<(temp.num[3]*ans)%mod<<endl;
    }    
    return 0;
} 