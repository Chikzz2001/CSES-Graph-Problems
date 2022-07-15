//  Modified  Bellman-Ford Algorithm  //

// Retrieve Negative weight cycle in a directed graph //


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
           
           vector<vector<ll>>graph(m+1,vector<ll>(3));
           
           for(ll i=1;i<=m;i++){
               
               cin>>graph[i][0]>>graph[i][1]>>graph[i][2];
               
           }
           
           // Assume a dummy node i.e ( 0 ) and initialize all the nodes [1....N] as 0 , as we are in search of negative weight cycles only. //
           
           vector<ll>dist(n+1,0LL);
           
           vector<ll>relaxant(n+1,-1LL);
           
           // Like Bellman-Ford Algo , we have to go for N iterations , and if we don't found any relaxation at N-th iteration , then there is no (-) weight cycle.
           
           // Otherwise there are two possibilities --> (a) The last relaxed node itself a member of the cycle , (b) it is relaxed by some member of the cycle.
           
           
           ll x; // Last relaxed Node .
           
           for(ll i=1;i<=n;i++){ // N iterations
               
               x=-1LL;
               
               for(ll j=1;j<=m;j++){
                   
                   ll u=graph[j][0];
                   ll v=graph[j][1];
                   ll wt=graph[j][2];
                   
                   if(dist[v] > dist[u] + wt){
                       
                       dist[v] = dist[u] + wt;
                       
                       relaxant[v] = u;
                       
                       x = v;
                       
                   }
                   
               }
               
           }
           
           
           if(x==-1){
               
               cout<<"NO\n";
               
           }
           
           else{
               
               cout<<"YES\n";
               
               // Make sure we are currently at a node which is a part of the negative weight cycle.
               
               // For these we have to expand the nodes through their relaxants.
               
               for(ll i=1;i<=n;i++){
                   
                   x=relaxant[x];
                   
               }
               
               // Time to retrieve the cycle.
               
               vector<ll>cycle;
               
               ll temp=x;
               
               while(true){
                   
                   cycle.push_back(x);
                   
                   x=relaxant[x];
                   
                   if(x==temp){
                       break;
                   }
                   
               }
               
               cycle.push_back(x);
               
               reverse(cycle.begin(),cycle.end());
               
               for(ll i=0;i<cycle.size();++i){
                   cout<<cycle[i]<<" ";
               }cout<<"\n";
               
           }
       
         }
      
    return 0;
    
}