//  Modified Dijkstra's Algorithm  //


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
           
           for(ll i=0;i<m;i++){
               
               ll u,v;
               cin>>u>>v;
               
               graph[u].push_back({v,-1LL});
               
           }
           
           vector<ll>dist(n+1,1e15);
           
           vector<ll>parent(n+1,-1LL);
           
           dist[1]=0LL;
           
           priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
           
           pq.push({0LL,1LL});
          
           ll u=0,wt=0,v=0,weight=0;
          
           while(!pq.empty()){
               
               auto curr=pq.top();
               pq.pop();
               
                u=curr.second;
                wt=curr.first;
               
               if(dist[u]!=wt){
                   
                   continue;
                   
               }

               for(auto nbr:graph[u]){
                   
                   ll v=nbr.first;
                   ll weight=nbr.second;
                   
                   
                   if(dist[v] > dist[u] + weight){
                       
                       dist[v] = dist[u] + weight;
                       
                       parent[v] = u;
                       
                       pq.push({dist[v],v});
                       
                   }
                   
               }
               
           }
           
           if(dist[n]>=1e15){
               
               cout<<"IMPOSSIBLE\n";
               
           }
           
           else{
               
              // cout<<(1-dist[n])<<"\n";
               
               vector<ll>vec;
               
               ll node=n;
               
               while(node!=-1LL){
                   
                   vec.push_back(node);
                   
                   node=parent[node];
                   
               }
               
               reverse(vec.begin(),vec.end());
               
               cout<<vec.size()<<"\n";
               
               for(ll i=0;i<vec.size();++i){
                   cout<<vec[i]<<" ";
               }cout<<"\n";
               
           }
       
         }
      
    return 0;
    
}