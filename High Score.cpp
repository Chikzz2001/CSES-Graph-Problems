// Modified Bellman Ford Algorithm (Negative Cycle Present) //


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

const ll NINF = -1e14;

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

struct comp{
  
  bool operator()(const pair<ll,ll>&x,const pair<ll,ll>&y){
      
      return x.second > y.second;
      
  }  
    
};

int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
        
         while(t--){
          
           ll n,m;
           cin>>n>>m;
           
           vector<vector<ll>>graph(m,vector<ll>(3));
           
           for(ll i=0;i<m;i++){
               cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
               graph[i][2]*=-1LL;
           }
           
           vector<ll>dist(n+1,1e14);
           
           dist[1]=0LL;
           
           for(ll loop=1;loop<n;loop++){
               
               for(ll i=0;i<m;++i){
                   
                   ll u=graph[i][0];
                   ll v=graph[i][1];
                   ll d=graph[i][2];
                   
                   if(dist[u]==1e14){
                       continue;
                   }
                   
                   dist[v]=min(dist[v],dist[u]+d);
                   dist[v]=max(dist[v],NINF);
                   
                //   if(dist[graph[i][1]] > dist[graph[i][0]] + graph[i][2]){
                       
                //       dist[graph[i][1]] = dist[graph[i][0]] + graph[i][2];
                       
                //   }
                   
               }
               
           }
           
        //   for(ll i=1;i<=n;i++){
               
        //       cout<<dist[i]<<" ";
               
        //   }cout<<"\n";
           
           for(ll loop=1;loop<n;loop++){
               
               for(ll i=0;i<m;++i){
                   
                   ll u=graph[i][0];
                   ll v=graph[i][1];
                   ll d=graph[i][2];
                   
                   if(dist[u]==1e14){
                       continue;
                   }
                   
                   if(dist[u]+d<dist[v]){
                       
                       dist[v]=NINF;
                       
                   }
                   
               }
               
           }
           
           if(dist[n]<=NINF){
               
              cout<<-1<<"\n";
               
           }
           
           else{
               
               cout<<-dist[n]<<"\n";
               
           }
           
       
         }
      
    return 0;
    
}