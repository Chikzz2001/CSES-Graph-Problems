// Floyd Warshall Algorithm //

// MultiSource Shortest Paths //

// It will work for directed edges and negative edge weights also //

// Relaxing through K-th Node //

// dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) //


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


int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
        
         while(t--){
          
           ll n,m,q;
           cin>>n>>m>>q;
           
           vector<vector<ll>>graph(n+1,vector<ll>(n+1,1e15));
           
           for(ll i=1;i<=n;i++){
               
               graph[i][i]=0LL;
               
           }
           
           for(ll i=1;i<=m;++i){
               
               ll u,v,w;
               cin>>u>>v>>w;
               
               graph[u][v]=min(graph[u][v],w);
               graph[v][u]=min(graph[v][u],w);
               
           }
           
           // Floyd Warshall Algorithm
           
           for(ll k=1;k<=n;k++){
               
               for(ll i=1;i<=n;i++){
                   
                   for(ll j=1;j<=n;j++){
                       
                       graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                       
                   }
                   
               }
               
           }
           
           while(q--){
               
               ll a,b;
               cin>>a>>b;
               
               ll dist=graph[a][b];
               
               if(dist>=1e15){
                   cout<<-1<<"\n";
               }else{
                   cout<<dist<<"\n";
               }
               
           }
          
         }
      
    return 0;
    
}