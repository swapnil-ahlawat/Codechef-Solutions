// Created by swapnil_a01
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int n, current;    
string str1, str2;
int output[260005];
int v[10005];
int connect[260005][27];
int fix[260005];
string s[10005];
int g[260005][27];
 
void form_Trie()
{
  
    for(int j=0; j<26; j++) g[0][j] = -1;
    
    //for(int j=0; j<26; j++) cout<<g[0][j]<<endl;
    
    output[0] = 0;
 
    current = 1;
    for(int i=0; i<n; i++)
    {
        string temp = s[i];
        int cur = 0;
     
        for(int j=0; j<temp.length(); j++)
        {
            int c = temp[j]-'a';
 
            if ( g[cur][c] == -1)
            { 
                output[current] = 0;
                for(int k=0; k<26; k++)
                { 
                    g[current][k] = -1;
                    connect[current][k] = -1;
                }
                g[cur][c] = current;
                connect[cur][c] = current++;
            }
 
        cur = g[cur][c];
        }
        output[cur] += v[i];
  
    }
 
    for(int i=0; i<26; i++)
    {
        if(g[0][i] == -1) g[0][i] = 0,connect[0][i] = 0;
    }
}
 
int next(int v,int c)
{
   if ( connect[v][c] == -1)
   {
      if (g[v][c] != -1 )
        connect[v][c] = g[v][c];
      else
        connect[v][c] = (v==0)?0:next(fix[v],c);
   }
   return connect[v][c];
}
 
void failed()
{
    queue <int> q;
 
    for(int c=0; c<26; c++)
    {
        if ( g[0][c] != 0) q.push(g[0][c]);
        fix[g[0][c]] = 0;
    }
 
    while (!q.empty())
    { 
        int cur = q.front();
        q.pop();
        int f;
        for(int c=0; c<26; c++)
        {
            if ( g[cur][c] != -1)
            {
                f = fix[cur];
 
            while ( g[f][c] == -1)
            { 
                f = fix[f];
            }
          
            f = g[f][c];
            fix[g[cur][c]] = f;
            output[g[cur][c]] += output[f];
 
            q.push(g[cur][c]);
            }
        
        connect[cur][c] = next(cur,c);
        }
    }
}
 
 
ll calculate(string str_txt)
{ 
    int cur = 0;
    ll res = 0;
    int c;
    for(int i=0; i<str_txt.length(); i++)
    { 
        c = str_txt[i]-'a';
        cur = connect[cur][c];
        res += output[cur];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        cin >> str1 >> str2;
        cin >> n;
        int m = 0;
        int mini = 27;
        for(int i=0; i<n; i++)
        { 
            cin >> s[i] >> v[i];
            m = max(m,(int)s[i].length());
            mini = min(mini,(int)s[i].length());
        }
        //cout<<mini<<endl;
        form_Trie();
        failed();
    
        ll res = 0;   
        int l1 = str1.length();
        int l2 = str2.length();
 
        ll left1[l1];
        ll right1[l2];
        ll left2[l1];
        ll right2[l2];
            
        for(int i=0; i<l1; i++)
        {
            left2[i] = calculate(str1.substr(0,i+1));
            if ( i < m-2)
                left1[i] = left2[i];
            else
                left1[i] = calculate(str1.substr(max(0,i-(m-2)),min(m-1,i+1)));
        }
        
        // for(int i=0; i<l1; i++) 
        //     cout<<left1[i]<<' '<<left2[i]<<endl;
        
        for(int i=0; i<l2; i++)
        {
            right2[i] = calculate(str2.substr(i,l2-i));
            if ( i > (l2-m+1))
                right1[i] = right2[i];
            else
                right1[i] = calculate(str2.substr(i,min(m-1,l2-i)));
        }

        // for(int i=0; i<l2; i++) 
        //     cout<<right1[i]<<' '<<right2[i]<<endl;
    
        for(int i=0; i<l1; i++)
        { 
            for(int j=0; j<l2; j++)
            { 
                if ( (i+1+l2-j) < mini)
                    continue;
                res = max(res,left2[i] + right2[j]+calculate(str1.substr(max(0,i-(m-2)),min(m-1,i+1)) + str2.substr(j,min(m-1,l2-j)))- (left1[i]+ right1[j]));
            }
        }
        cout<<res<<endl;

    } 
    
    return 0;
} 