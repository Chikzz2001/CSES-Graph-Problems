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


struct edge{
  
  ll u;
  ll v;
  ll w;
    
};

struct comp{
  
  bool operator()(const pair<ll,ll>&x,const pair<ll,ll>&y){
      
      return x.second > y.second;
      
  }  
    
};

vector<vector<pair<ll,ll>>>graph;

vector<vector<pair<ll,ll>>>rgraph;


int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
        
         while(t--){
          
           ll n,m;
           cin>>n>>m;
           
           graph.resize(n+1);
           
           rgraph.resize(n+1);
           
           
           vector<edge>edges(m);
           
           
           for(ll i=0;i<m;i++){
               
               ll u,v,w;
               cin>>u>>v>>w;
               
               edges[i]={u,v,w};
               
               graph[u].push_back({v,w});
               
               rgraph[v].push_back({u,w});
               
           }
           
           
           vector<ll>dist1(n+1,1e15);
           
           vector<ll>dist2(n+1,1e15);
           
           dist1[1]=0LL;
           
           priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,comp>pq;
           
           pq.push({1LL,0LL});
           
           vector<bool>visited(n+1,false);
           
           
           while(!pq.empty()){
               
               auto curr=pq.top();
               pq.pop();
               
               ll node=curr.first;
               ll wt=curr.second;
               
               if(visited[node]==true){
                   continue;
               }
               
               visited[node]=true;
               
               dist1[node]=wt;
               
               
               for(auto nbr:graph[node]){
                   
                   ll v=nbr.first;
                   ll weight=nbr.second;
                   
                   if(dist1[v] > dist1[node] + weight){
                       
                       dist1[v] = dist1[node] + weight;
                       
                       pq.push({v,dist1[v]});
                       
                   }
                   
               }
               
           }
           
           
           
           
           for(ll i=0;i<=n;i++){
               
               visited[i]=false;
               
           }
           
           while(!pq.empty()){
               
               pq.pop();
               
           }
           
           
           pq.push({n,0LL});
           
           dist2[n]=0LL;
           
           
            while(!pq.empty()){
               
               auto curr=pq.top();
               pq.pop();
               
               ll node=curr.first;
               ll wt=curr.second;
               
               if(visited[node]==true){
                   continue;
               }
               
               visited[node]=true;
               
               dist2[node]=wt;
               
               
               for(auto nbr:rgraph[node]){
                   
                   ll v=nbr.first;
                   ll weight=nbr.second;
                   
                   if(dist2[v] > dist2[node] + weight){
                       
                       dist2[v] = dist2[node] + weight;
                       
                       pq.push({v,dist2[v]});
                       
                   }
                   
               }
               
           }
           
           
           ll ans=1e18;
           
        //   for(ll i=1;i<=n;i++){
               
        //       cout<<dist1[i]<<" ";
               
        //   }cout<<"\n";
        
           
        //   for(ll i=1;i<=n;i++){
               
        //       cout<<dist2[i]<<" ";
               
        //   }cout<<"\n";
        
        
            for(ll i=0;i<m;i++){
                
                ll curr=(edges[i].w)/2LL;
                
                ans=min(ans,dist1[edges[i].u] + dist2[edges[i].v] + curr);
                
            }
                
            cout<<ans<<"\n";
       
         }
      
    return 0;
    
}