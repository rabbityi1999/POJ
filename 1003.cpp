#include <bits/stdc++.h>
using namespace std;
/*这是一道典型dijkstra问题

*/
#define INF 100000000
typedef long long LL;

LL n,m;
LL BEGIN,END;

LL value[600] = {0};//记录点权
LL dis[600] = {0};//记录最短距离
LL d[600][600]={INF};//两点之间距离
bool vis[600] = {false};

LL weight[600] = {0};//最大点权之和
LL num[600] = {0};//最短路径条数

void dij(LL start,LL END){//,LL &path_num,LL &max_v
    fill(dis,dis+600,INF);
    LL u,v,i,j,k,MIN,visted=0;
    visted=1;
    /*
    for(i=0;i<n;i++){
        dis[i]=d[i][start];
        if(i!=start&&dis[i]!=INF){
            num[i]=1;//初始的最短路径数
            weight[i]=value[i]+value[start];//初始的救援队
        }
    }*/

    dis[start] = 0;
    weight[start] = value[start];
    num[start] = 1;

    for(i=0;i<n;i++){
        u=-1;
        MIN=INF;
        for(j=0;j<n;j++){
            if(vis[j]==false && dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1) return ;
        vis[u] = true;
        /*
        if(u ==END){
            path_num =  num[u];
            max_v = weight[u];
            return ;
        }*/
        for(v=0;v<n;v++){
            if(vis[v]==false && d[u][v]!=INF){//这个条件很重要，两点之间距离本来不是INF+还没有被vis
                if(dis[u]+d[u][v]<dis[v]){
                    dis[v] = dis[u]+d[u][v];
                    weight[v] = weight[u] + value[v];//更新最大点权
                    num[v] = num[u];
                }else if(dis[u] + d[u][v] ==dis[v]){
                    if(value[v] + weight[u] >weight[v]){//寻找权值更大的
                        weight[v] = value[u] +weight[v];
                    }
                    num[v] +=num[u];//最短路径数目加由一条新的路径产生的
                }
            }
        }
    }
}
int main()
{
    LL i,a,b,path_num,max_v;
   cin>>n>>m>>BEGIN>>END;
   for(i=0;i<n;i++){//都是从0开始
        cin>>value[i];
   }
   for(i=0;i<600;i++){
    fill(d[i],d[i]+600,INF);
   }
   //fill(d,d+3600000,INF);
   for(i=0;i<m;i++){
        cin>>a>>b;
        cin>>d[a][b];
        d[b][a]=d[a][b];
   }

   dij(BEGIN,END);//,path_num,max_v
    cout<<num[END]<<" "<<weight[END]<<endl;

    return 0;
}
