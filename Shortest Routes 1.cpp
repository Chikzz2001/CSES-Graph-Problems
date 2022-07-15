#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

const ll INF = 1e14;

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
           
           vector<vector<pair<ll,ll>>>graph(n+1);
           
           for(ll i=1;i<=m;i++){
               
               ll u,v,w;
               cin>>u>>v>>w;
               
               graph[u].push_back({v,w});
               
           }
           
           priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,comp>pq;
           
           vector<ll>dist(n+1,1e15);
           
           dist[1]=0LL;
           
           pq.push({1LL,0LL});
           
           while(!pq.empty()){
               
               auto curr=pq.top();
               pq.pop();
               
               ll u=curr.first;
               ll weight=curr.second;
               
               if(dist[u] < weight){
                   
                   continue;
                   
               }
               
               for(auto nbr:graph[u]){
                   
                   ll v=nbr.first;
                   ll wt=nbr.second;
                   
                   if(dist[v] > dist[u] + wt){
                       
                       dist[v] = dist[u] + wt;
                       
                       pq.push({v,dist[v]});
                       
                   }
                   
               }
               
           }
           
           
           for(ll i=1;i<=n;i++){
               cout<<dist[i]<<" ";
           }cout<<"\n";
       
         }
      
    return 0;
    
}