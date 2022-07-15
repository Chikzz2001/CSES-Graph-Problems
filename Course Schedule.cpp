//  Topological Sorting + Kahn's Algorithm  //


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
           
           vector<ll>indegree(n+1,0LL);
           
           vector<vector<ll>>graph(n+1);
           
           for(ll i=0;i<m;i++){
               
               ll u,v;
               cin>>u>>v;
               
               indegree[v]++;
               
               graph[u].push_back(v);
               
           }
           
           queue<ll>q;
           
           vector<ll>ans;
           
           for(ll i=1;i<=n;i++){
               
               if(indegree[i]==0){
                   q.push(i);
               }
               
           }
           
           
           while(!q.empty()){
               
               ll node=q.front();
               q.pop();
               
               ans.push_back(node);
               
               for(ll v:graph[node]){
                   
                   indegree[v]--;
                   
                   if(indegree[v]==0){
                       
                       q.push(v);
                       
                   }
                   
               }
               
           }
           
           if(ans.size()==n){
               
               for(ll i=0;i<n;++i){
                   cout<<ans[i]<<" ";
               }cout<<"\n";
               
           }
           
           else{
               
               cout<<"IMPOSSIBLE\n";
               
           }
       
         }
      
    return 0;
    
}