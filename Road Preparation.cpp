//  Prims Minimum Spanning Tree Algorithm  //


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
               
               ll u,v,w;
               cin>>u>>v>>w;
               
               graph[u].push_back({v,w});
               graph[v].push_back({u,w});
               
           }
           
           ll cost=0LL;
           
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
               cost+=wt;
               
               for(auto nbr:graph[node]){
                   
                   ll v=nbr.first;
                   ll weight=nbr.second;
                   
                   if(visited[v]==false){
                       
                       pq.push({v,weight});
                       
                   }
                   
               }
               
           }
           
           bool pos=true;
           
           for(ll i=1;i<=n;i++){
               if(visited[i]==false){
                   pos=false;
                   break;
               }
           }
           
           
           if(pos){
               cout<<cost<<"\n";
           }else{
               cout<<"IMPOSSIBLE\n";
           }
           
       
         }
      
    return 0;
    
}