#include <bits/stdc++.h>
using namespace std;
#define N 100//change to 2000
#define INF 1111111 
int N2,M,S,D;//number of phone and weight threthold

int dis[N][N];
int cost[N][N];
bool vis[N];
int pre[N];
int sumdis[N];
int sumcost[N];
vector<int> result;
//struct node{
//	int pre;
//	int sumdis;
//	
//}; 
//这里有个要注意的地方，必须是queue用指针，才会最后一个点不超时！！！结构体很大，每次都复制一遍非常浪费时间！！！ 
void dijkstra(int s){
	int u,v,i,j,k,min,find=-1;
	u = s;
	sumdis[s]=0;
	sumcost[s]=0; 
	while(1){
		find=-1;
		//找到最小权值
		min=INF;
		for(i=0;i<M;i++){
			if(vis[i]==false&&sumdis[i]<min){
				min=sumdis[i];
				find=i;
			}
		}
//		if(min==INF||find==-1||min==D){    太生气了，这里发现多写一个 min==D就错了，因为 上面min=sumdis[i];代表最小值，可能最小值跟终点是巧合一致的 
					if(min==INF||find==-1||find==D){
			break;
		}else{
			u=find;
			vis[u]=true;
		}
		for(i=0;i<M;i++){
			if(vis[i]==false&&dis[i][u]!=INF){
				if(sumdis[u]+dis[i][u]<sumdis[i]){
					pre[i]=u;
					sumdis[i]=sumdis[u]+dis[i][u];
					sumcost[i]=sumcost[u]+cost[i][u];
				}else if(sumdis[u]+dis[i][u]==sumdis[i]){
					if(sumcost[u]+cost[i][u]<sumcost[i]){
						pre[i]=u;
						sumcost[i]=sumcost[u]+cost[i][u];
					}
				}
			}
		} 
	}
}

int main()
{
 	cin>>M>>N2>>S>>D;
 	int i,j,k,begin,end,a,b;
 	fill(vis,vis+M,false);
 	fill(pre,pre+M,-1);
 	fill(sumdis,sumdis+M,INF);
 	fill(sumcost,sumcost+M,INF);
 	
    for(i=0;i<M;i++){
 		fill(dis[i],dis[i]+M,INF);
 		fill(cost)
	}
    for(i=0;i<N2;i++){
    	cin>>begin>>end>>a>>b;
        dis[begin][end]=a;
        dis[end][begin]=a;
        cost[begin][end]=b;
        cost[end][begin]=b;
	}
	dijkstra(S);
	for(i=D;pre[i]!=-1;i=pre[i]){
		result.push_back(i);
	}
	result.push_back(i);
	for(i=result.size()-1;i>=0;i--){
		cout<<result[i]<<" ";
	}
	cout<<sumdis[D]<<" "<<sumcost[D];
    return 0;
}


