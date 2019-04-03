#include <bits/stdc++.h>
using namespace std;
/*����һ������dijkstra����

*/
#define INF 100000000
typedef long long LL;

LL n,m;
LL BEGIN,END;

LL value[600] = {0};//��¼��Ȩ
LL dis[600] = {0};//��¼��̾���
LL d[600][600]={INF};//����֮�����
bool vis[600] = {false};

LL weight[600] = {0};//����Ȩ֮��
LL num[600] = {0};//���·������

void dij(LL start,LL END){//,LL &path_num,LL &max_v
    fill(dis,dis+600,INF);
    LL u,v,i,j,k,MIN,visted=0;
    visted=1;
    /*
    for(i=0;i<n;i++){
        dis[i]=d[i][start];
        if(i!=start&&dis[i]!=INF){
            num[i]=1;//��ʼ�����·����
            weight[i]=value[i]+value[start];//��ʼ�ľ�Ԯ��
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
            if(vis[v]==false && d[u][v]!=INF){//�����������Ҫ������֮����뱾������INF+��û�б�vis
                if(dis[u]+d[u][v]<dis[v]){
                    dis[v] = dis[u]+d[u][v];
                    weight[v] = weight[u] + value[v];//��������Ȩ
                    num[v] = num[u];
                }else if(dis[u] + d[u][v] ==dis[v]){
                    if(value[v] + weight[u] >weight[v]){//Ѱ��Ȩֵ�����
                        weight[v] = value[u] +weight[v];
                    }
                    num[v] +=num[u];//���·����Ŀ����һ���µ�·��������
                }
            }
        }
    }
}
int main()
{
    LL i,a,b,path_num,max_v;
   cin>>n>>m>>BEGIN>>END;
   for(i=0;i<n;i++){//���Ǵ�0��ʼ
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
