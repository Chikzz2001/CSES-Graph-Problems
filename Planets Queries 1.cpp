//  Binary Lifting + Preprocessing  //


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


ll up[200005][31];

int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
        
         while(t--){
          
           ll n,q;
           cin>>n>>q;
           
           for(ll i=1;i<=n;i++){
               cin>>up[i][0];
           }
           
           // up[i][j] --> the node that can be reached by node i after (2^j) jumps in total.
           
           for(ll j=1;j<=30;j++){
               
               for(ll i=1;i<=n;i++){
                   
                   up[i][j]=up[up[i][j-1]][j-1]; // Kind of Recurrence.
                   
               }
               
           }
           
           
           ll x,k;
           
           while(q--){
               
               cin>>x>>k;
               
               for(ll i=0;i<=30;++i){
                   
                   if((k&(1LL<<i))){
                       
                       x=up[x][i];
                       
                   }
                   
               }
               
               printf("%lld\n",x);
               
           }
       
         }
      
    return 0;
    
}