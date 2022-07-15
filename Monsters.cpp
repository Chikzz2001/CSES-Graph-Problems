// MultiSource BFS //


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

struct cell{
  
  int x;
  int y;
  int timer;
    
};

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
           
           vector<vector<bool>>visited(m,vector<bool>(n,false));
           
           vector<vector<pair<int,int>>>prev(m,vector<pair<int,int>>(n));
           
           queue<pair<int,int>>q;
           
           vector<vector<int>>dist(m,vector<int>(n,1e9));
           
           // Here Monsters are acting like Multisource BFS 
           
           // dist[i][j] --> stores the minimum amount of time required to reach the cell (i,j) by any monster.
           
           for(int i=0;i<m;i++){
               
               for(int j=0;j<n;j++){
                   
                   if(grid[i][j]=='M'){
                       
                       dist[i][j]=0;
                       
                       q.push({i,j});
                       
                   }
                   
               }
               
           }
           
           int dx[4]={0,0,1,-1};
           int dy[4]={1,-1,0,0};
           
           while(!q.empty()){
               
               auto curr=q.front();
               q.pop();
               
               int x=curr.first;
               int y=curr.second;
               
               for(int d=0;d<4;d++){
                   
                   int x1=x+dx[d];
                   int y1=y+dy[d];
                   
                   if(x1>=0 && x1<m && y1>=0 && y1<n && grid[x1][y1]!='#'){
                       
                       if(dist[x1][y1] > dist[x][y] + 1){
                           
                           dist[x1][y1]=1+dist[x][y];
                           
                           q.push({x1,y1});
                           
                       }
                       
                   }
                   
               }
               
           }
           
        //   for(int i=0;i<m;++i){
               
        //       for(int j=0;j<n;++j){
                   
        //           cout<<dist[i][j]<<" ";
                   
        //       }cout<<"\n";
               
        //   }
        
           
            while(!q.empty()){
                
                q.pop();
                
            }
            
            queue<cell>hero;
            
            int starta=-1,startb=-1;
            
            for(int i=0;i<m;i++){
                
                for(int j=0;j<n;j++){
                    
                    if(grid[i][j]=='A'){
                        
                        hero.push({i,j,0});
                        
                        starta=i;
                        startb=j;
                        
                        break;
                        
                    }
                    
                }
                
            }
            
            for(int i=0;i<m;i++){
                
                for(int j=0;j<n;j++){
                    
                    prev[i][j]={-1,-1};
                    
                }
                
            }
            
            int enda=-1,endb=-1;
            
            while(!hero.empty()){
                
                auto curr=hero.front();
                hero.pop();
                
                int x=curr.x;
                int y=curr.y;
                int timer=curr.timer;
                
                if(timer>=dist[x][y]){
                    
                    continue;
                    
                }
                
                if(visited[x][y]==true){
                    
                    continue;
                    
                }
                
                if(x==0 || y==0 || x==m-1 || y==n-1){
                    
                    enda=x;
                    endb=y;
                    break;
                    
                }
                
                visited[x][y]=true;
                
                for(int dir=0;dir<4;dir++){
                    
                    int nx=x+dx[dir];
                    int ny=y+dy[dir];
                    
                    if(nx>=0 && ny>=0 && nx<m && ny<n && visited[nx][ny]==false && grid[nx][ny]!='#' && dist[nx][ny]>timer+1){
                        
                        hero.push({nx,ny,timer+1});
                        
                        prev[nx][ny]={x,y};
                        
                    }
                    
                }
                
            }
            
          //  cout<<starta<<" "<<startb<<"\n";
            
          //  cout<<enda<<" "<<endb<<"\n";
            
            int i=enda,j=endb;
            
            if(enda==-1 || endb==-1){
                
                cout<<"NO\n";
                
            }
            
            else{
                
                cout<<"YES\n";
                
                string str="";
                
                
                while(i!=starta || j!=startb){
                    
                    int ni=prev[i][j].first;
                    int nj=prev[i][j].second;
                    
                   // cout<<i<<" "<<j<<"-->"<<ni<<" "<<nj<<endl;
                    
                        if(ni==i && nj==j-1){
                            
                            str+="R";
                            
                        }
                        
                        if(ni==i && nj==j+1){
                            
                            str+="L";
                            
                        }
                        
                        if(ni==i+1 && nj==j){
                            
                            str+="U";
                            
                        }
                        
                        if(ni==i-1 && nj==j){
                            
                            str+="D";
                            
                        }
                    
                    i=ni;
                    j=nj;
                    
                }
                
                reverse(str.begin(),str.end());
                
                cout<<str.length()<<"\n";
                
                cout<<str<<"\n";
                
            }
            
          
         }
      
    return 0;
    
}