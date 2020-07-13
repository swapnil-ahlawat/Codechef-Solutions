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
    cin>>t;
    while(t--){
        int n;
        char temp;
        cin>>n;
        vector <int> freq[26];
        unordered_map<int, bool> target[26];
        int a[n], b[n];
        int arr[26] = {0};
        for(int i=0; i<n; i++){
            cin>>temp;
            a[i]= (int)(temp-'a');
        }
        for(int i=0; i<n; i++){
            cin>>temp;
            b[i]= (int)(temp-'a');
            target[(int)(temp -'a')][i]=true;
            freq[a[i]].push_back(i);
            arr[b[i]]++;
        }
        bool np=false;
        
        for(int i=0; i<n; i++)
        {
          if( freq[b[i]].size() == 0 || b[i] > a[i])
          {
            cout << -1 << endl;
            np=true;
            break;
          }
        }
        if(np) continue;

        int count = 0, scount=0;
        vector<vector<int>> ans;
        for(int i=25; i>=0; i--){
            vector<int> res;
            scount = 0;
            count = 0;
            if (arr[i])
            {
              for(int j=0;j<n; j++)
              {
                if(a[j]==i)
                {
                  count++;
                  res.push_back(j);
                }

                if (a[j]> i && b[j]==i )
                { scount++;
                  count++;
                  res.push_back(j);
                }
              }
                if (scount == 0) continue;
                ans.push_back(res);
            }
        }

            cout<<ans.size()<<endl;
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i].size()<<' ';
                for(int j=0; j<ans[i].size(); j++){
                    cout<<ans[i][j]<<' ';
                }
                cout<<endl;
            }
        
        
     } 
    
    return 0;
} 