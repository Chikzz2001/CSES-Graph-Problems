// Bi-Partite Graph using DFS //

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

bool flag;

vector<vector<int>>graph;

vector<int>color;

void dfs(int u,int col){
    
    color[u]=col;
    
    for(int v:graph[u]){
        
        if(color[v]==-1){
            
            color[v]=1-color[u];
            
            dfs(v,color[v]);
            
        }
        
        else if(color[v]==color[u]){
            
            flag=false;
            break;
            
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
           
           graph.resize(n+1);
           
           for(int i=1;i<=m;i++){
               
               int u,v;
               cin>>u>>v;
               
               graph[u].push_back(v);
               graph[v].push_back(u);
               
           }
           
           flag=true;
           
           color.resize(n+1,-1);
           
           for(int i=1;i<=n;i++){
               
               if(color[i]==-1){
                   
                   color[i]=0;
                   
                   dfs(i,0);
                   
               }
               
           }
           
           if(flag==false){
               
               cout<<"IMPOSSIBLE\n";
               
           }
           
           else{
               
               for(int i=1;i<=n;i++){
                   
                   cout<<color[i]+1<<" ";
                   
               }cout<<"\n";
               
           }
          
         }
      
    return 0;
    
}