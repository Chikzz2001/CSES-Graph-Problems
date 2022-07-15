//  Basic Application of DSU  //


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

vector<ll>Parent;
vector<ll>Size;

ll find(ll x){
    
    if(Parent[x]==x){
        return x;
    }
    
    ll temp=find(Parent[x]);
    
    return Parent[x] = temp;
    
}

void Union(ll x,ll y){
    
   ll lx=find(x);
   ll ly=find(y);
   
   if(lx!=ly){
       
       if(Size[lx]>Size[ly]){
           
           Size[lx]+=Size[ly];
           Parent[ly]=lx;
           
       }
       
       else{
           
           Size[ly]+=Size[lx];
           Parent[lx]=ly;
           
       }
       
   }
    
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
           
           Parent.resize(n+1);
           Size.resize(n+1);
           
           for(ll i=1;i<=n;i++){
               
               Parent[i]=i;
               Size[i]=1LL;
               
           }
           
           ll num_of_comp=n;
           
           ll max_size_comp=1LL;
           
           for(ll i=1;i<=m;i++){
               
               ll u,v;
               cin>>u>>v;
               
               ll p1=find(u);
               ll p2=find(v);
               
               if(p1!=p2){
                   
                   num_of_comp--;
                   
                   max_size_comp=max(max_size_comp,Size[p1]+Size[p2]);
                   
                   Union(p1,p2);
                   
               }
               
               cout<<num_of_comp<<" "<<max_size_comp<<"\n";
               
           }
       
         }
      
    return 0;
    
}