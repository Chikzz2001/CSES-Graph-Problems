// Retrieve Cycle in a Directed graph using DFS  //


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

vector<bool>visited;

vector<bool>rsflag;

stack<ll>S;

vector<vector<ll>>graph;

bool dfs(ll u){
    
    visited[u]=true;
    
    rsflag[u]=true;
    
    S.push(u);
    
    for(ll v:graph[u]){
        
        if(visited[v]==false){
            
            if(dfs(v)==true){
                
                return true;
                
            }
            
        }
        
        if(rsflag[v]==true){
            
            S.push(v);
            
            return true;
            
        }
        
    }
    
    rsflag[u]=false;
    S.pop();
    
    return false;
    
}

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
           
           visited.resize(n+1,false);
           
           rsflag.resize(n+1,false);
           
           for(ll i=1;i<=m;i++){
               
               ll u,v;
               cin>>u>>v;
               
               graph[u].push_back(v);
               //graph[v].push_back(u);
               
           }
           
           
           bool found=false;
           
           for(ll i=1;i<=n;i++){
               
               if(visited[i]==false){
                   
                   if(dfs(i)==true){
                       
                       found=true;
                       break;
                       
                   }
                   
               }
               
           }
           
           if(found==false){
               
               cout<<"IMPOSSIBLE\n";
           
               
           }
           
           else{
               
               ll temp=S.top();
               S.pop();
               
               vector<ll>ans;
               
               ans.push_back(temp);
               
               while(!S.empty()){
                   
                   ll curr=S.top();
                   S.pop();
                   
                   ans.push_back(curr);
                   
                   if(curr==temp){
                       break;
                   }
                   
               }
               
               reverse(ans.begin(),ans.end());
               
               cout<<ans.size()<<"\n";
               
               for(ll i=0;i<ans.size();++i){
                   cout<<ans[i]<<" ";
               }cout<<"\n";
               
           }
       
         }
      
    return 0;
    
}