// Cycle Detection in a graph using DFS //

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
vector<vector<int>>graph;

vector<int>parent;

vector<bool>visited;

int sv=-1,ev=-1;

bool found=false;

void dfs(int u,int p){
    
    if(found==true){
        
        return;
        
    }
    
    visited[u]=true;
    
    parent[u]=p;
    
    
    for(int v:graph[u]){
        
        if(v==p){
            continue;
        }
        
        if(visited[v]==true){
            
            sv=v;
            ev=u;
            found=true;
            
        }
        
        if(found==false){
            
           dfs(v,u);    
            
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
           
           parent.resize(n+1,-1);
           
           visited.resize(n+1,false);
           
           for(int i=1;i<=m;i++){
               
               int u,v;
               cin>>u>>v;
               
               graph[u].push_back(v);
               graph[v].push_back(u);
               
           }
           
          for(int i=1;i<=n;i++){
               
               if(found==true){
                   
                   break;
                   
               }
               
              if(visited[i]==false){
                   
                  dfs(i,-1);
                   
                   
              }
               
          }
           
        //   cout<<sv<<" "<<ev<<"\n";
        //   cout<<parent[sv]<<" "<<parent[ev]<<"\n";
          
        //   for(int i=1;i<=n;i++){
        //       cout<<parent[i]<<" ";
        //   }cout<<"\n";
           
           if(found==false){
               
               cout<<"IMPOSSIBLE\n";
               
           }
           
           else{
               
               vector<int>v;
           
           v.push_back(ev);
           
           int tv=sv;
           
          while(tv!=ev){
               
              v.push_back(tv);
               
              tv=parent[tv];
               
          }
           
          v.push_back(ev);
           
          cout<<v.size()<<"\n";
           
          for(int i=0;i<v.size();++i){
              cout<<v[i]<<" ";
          }cout<<"\n";    
               
           }
           
          
         }
      
    return 0;
    
}