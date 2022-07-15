// Connected Components using DFS //

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

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

void dfs(int i,int j,int m,int n,vector<vector<char>>&grid){
    
     if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='#'){
         
         return;
         
     }
    
     grid[i][j]='#';
     
     dfs(i+1,j,m,n,grid);
     dfs(i-1,j,m,n,grid);
     dfs(i,j+1,m,n,grid);
     dfs(i,j-1,m,n,grid);
     
}

int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
        
         while(t--){
          
           int m,n;
           cin>>m>>n;
           
           vector<vector<char>>grid(m,vector<char>(n));
           
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   cin>>grid[i][j];
               }
           }
           
           
           int room=0;
           
           for(int i=0;i<m;i++){
               
               for(int j=0;j<n;j++){
                   
                   if(grid[i][j]=='#'){
                       continue;
                   }
                   
                   room++;
                   
                   dfs(i,j,m,n,grid);
                   
               }
               
           }
           
           cout<<room<<"\n";
          
         }
      
    return 0;
    
}