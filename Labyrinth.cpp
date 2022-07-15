// Shortest Path using BFS in a 2-D grid //

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
           
           
           int a1=-1,a2=-1,b1=-1,b2=-1;
           
           for(int i=0;i<m;i++){
               for(int j=0;j<n;j++){
                   if(grid[i][j]=='A'){
                       a1=i,a2=j;
                   }else if(grid[i][j]=='B'){
                       b1=i,b2=j;
                   }
               }
           }
           
           queue<pair<int,int>>q;
           
           q.push({a1,a2});
           
           vector<vector<bool>>visited(m,vector<bool>(n,false));
           
           vector<vector<int>>dist(m,vector<int>(n,1e9));
           
           bool found=false;
           
           
           int dx[4]={0,0,1,-1};
           
           int dy[4]={1,-1,0,0};
           
           char DIR[4]={'L','R','U','D'};
           
           
           dist[a1][a2]=0;
           
           
           while(!q.empty()){
               
               int sz=q.size();
               
               while(sz--){
                   
                   auto curr=q.front();
                   q.pop();
                   
                   int i=curr.first;
                   int j=curr.second;
                   
                   if(visited[i][j]==true){
                       continue;
                   }
                   
                   if(i==b1 && j==b2){
                       found=true;
                       break;
                   }
                   
                   visited[i][j]=true;
                   
                   for(int dir=0;dir<4;dir++){
                       
                       int ni=i+dx[dir];
                       int nj=j+dy[dir];
                       
                       if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]!='#' && visited[ni][nj]==false){
                           
                           if(dist[ni][nj]>1+dist[i][j]){
                               
                               dist[ni][nj]=1+dist[i][j];
                               q.push({ni,nj});
                               
                           }
                           
                       }
                       
                   }
                   
               }
               
               if(found){
                   break;
               }
               
           }
           
           if(found==false){
               
               cout<<"NO\n";
               
           }
           
           else{
               
               cout<<"YES\n";
               
               cout<<dist[b1][b2]<<"\n";
               
            //   for(int i=0;i<m;i++){
            //       for(int j=0;j<n;j++){
            //           cout<<dist[i][j]<<" ";
            //       }cout<<"\n";
            //   }
               
               string res="";
               
               int i=b1,j=b2;
               
               while(dist[i][j]!=0){
                   
                   for(int dir=0;dir<4;dir++){
                       
                       int ni=i+dx[dir];
                       int nj=j+dy[dir];
                       
                       if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]!='#' && dist[ni][nj]==dist[i][j]-1){
                           
                           res+=DIR[dir];
                           
                          // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
                           
                           i=ni;
                           j=nj;
                           
                        //   cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
                           
                           break;
                           
                       }
                       
                   }
                   
               }
               
               reverse(res.begin(),res.end());
               
               cout<<res<<"\n";
               
           }
          
         }
      
    return 0;
    
}