// Shortest Path using BFS //

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
           
           vector<int>dist(n+1,1e9);
           
           vector<bool>visited(n+1,false);
           
           dist[1]=0;
           
           vector<int>prev(n+1,-1);
           
           queue<int>q;
           
           q.push(1);
           
           bool found=false;
           
           
           while(!q.empty()){
               
               int sz=q.size();
               
               while(sz--){
                   
                   int node=q.front();
                   q.pop();
                   
                   if(visited[node]){
                       
                       continue;
                       
                   }
                   
                   if(node==n){
                       
                       found=true;
                       break;
                       
                   }
                   
                   visited[node]=true;
                   
                   for(int j:graph[node]){
                       
                       if(visited[j]==false){
                           
                           if(dist[j] > dist[node] + 1){
                               
                               q.push(j);
                               
                               dist[j]=dist[node]+1;
                               
                               prev[j]=node;
                               
                           }
                           
                       }
                       
                   }
                   
               }
               
               if(found){
                   break;
               }
               
           }
           
           if(found==false){
               
               cout<<"IMPOSSIBLE\n";
               
           }
           
           else{
               
               cout<<dist[n]+1<<"\n";
               
               vector<int>v;
               
               int i=n;
               
               while(prev[i]!=-1){
                   
                   v.push_back(i);
                   
                   i=prev[i];
                   
               }
               
               v.push_back(1);
               
               reverse(v.begin(),v.end());
               
               for(int i=0;i<v.size();++i){
                   cout<<v[i]<<" ";
               }cout<<"\n";
               
           }
          
         }
      
    return 0;
    
}