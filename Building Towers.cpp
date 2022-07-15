// Number of Connected Components using DFS //

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

ll fact[200005];

ll mod(ll a){
    return ((a%M)+M)%M;
}

ll mul(ll a,ll b){
    return mod(mod(a)*mod(b));
}

ll add(ll a,ll b){
    return mod(mod(a)+mod(b));
}

ll modPow(ll a,ll b){
    
    if(b==0){
        return 1LL;
    }
    
    else if(b==1){
        return a;
    }
    
    ll res=1LL;
    
    while(b){
        
        if(b%2==1){
            res=mul(res,a);
        }
        
        b/=2;
        a=mul(a,a);
        
    }
    
    return res;
    
}

void dfs(int i,vector<vector<int>>&graph,vector<bool>&visited){
    
    if(visited[i]==true){
        return;
    }
    
    visited[i]=true;
    
    for(auto j:graph[i]){
        
        if(visited[j]==false){
            
            dfs(j,graph,visited);
            
        }
        
    }
    
}

int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
        
         while(t--){
          
           int n,m;
           cin>>n>>m;
           
           vector<vector<int>>graph(n+1);
           
           for(int i=1;i<=m;i++){
               
               int u,v;
               cin>>u>>v;
               
               graph[u].push_back(v);
               graph[v].push_back(u);
               
           }
           
           vector<bool>visited(n+1,false);
           
           vector<int>v;
           
           for(int i=1;i<=n;i++){
               
               if(visited[i]==false){
                   
                   v.push_back(i);
                   
                   dfs(i,graph,visited);
                   
               }
               
           }
           
           int sz=v.size();
           
           if(sz==1){
               
               cout<<0<<"\n";
               
           }
           
           else{
               
               cout<<sz-1<<"\n";
               
               for(int i=1;i<sz;++i){
                   
                   cout<<v[0]<<" "<<v[i]<<"\n";
                  
               }
               
           }
          
         }
      
    return 0;
    
}