#include <bits/stdc++.h>
using namespace std;
#define N 100//change to 2000
typedef long long LL;

int vex[N][N] = {-1};
map<string,int> nametonum;
map<int,string> numtoname;
int person_num=0;
int n,K;//number of phone and weight threthold
int weight[N]={0};
bool vis[N] = {false};
int blockid = 0;
int head_no = 0;
int head_weight = 0;
int sum_man = 0;
int sum_weight = 0;
vector<string> result_name;
vector<int> result_num;

struct node{
	string name;
	int no;
	int sum = 0;
	int sum_man =0;
	vector<int> connect;
	map<int,int> weight;//node ——weight 
};
struct node all[N];

//算法有问题，如果成环 ，最后一条环边就无法访问了（如果边数比点数多很多） 
//vis标志位为true仅仅为DFS继续的标志不是决定是否将边权加入的标志
//易错点！！！标志点是否需要加入和标志边是否需要加入不是同步的！！需要注意边数比点数多非常多的情形！！ 
  
//void DFS(int i){
//	int j,temp;
//	for(j=0;j<all[i].connect.size();j++){
//		temp = all[i].connect[j];
//		if(vis[temp]==false){
//			vis[temp]=true;
//			sum_man++;
//			sum_weight  = sum_weight +all[i].weight[temp];
//			if(all[temp].sum>head_weight){
//				head_weight = all[temp].sum;
//				head_no = temp;
//			}
//			DFS(temp);
//		}
//	}
//}

void DFS(int i){
	int j,temp;
	vis[i]=true;
	
	for(j=0;j<all[i].connect.size();j++){
		temp = all[i].connect[j];
		if(all[i].weight[temp]!=-1){//说明这条边未被加上去过 
			sum_weight  = sum_weight +all[i].weight[temp];
			all[i].weight[temp]=-1;//加上了边之后立马删掉边——防止环的干扰 
			all[temp].weight[i]=-1;//注意！！两边都要删掉 
		}
		if(vis[temp]==false){
			sum_man++;
			if(all[temp].sum>head_weight){
				head_weight = all[temp].sum;
				head_no = temp;
			}
			DFS(temp);
		}
	}
}

bool cmp(const node& x ,const node& y){
	return x.name<y.name;
}
int main()
{
	cin>>n>>K;
	int i,j,k;
	string a,b;
	int a_index,b_index;
	bool same = false;
	for(i=0;i<n*2;i++){
		fill(vex[i],vex[i]+ n*2,-1);
	}
	
	for(i=0;i<n;i++){
		cin>>a>>b>>k;
		if(nametonum.find(a)!=nametonum.end()){
			a_index = nametonum[a];
		}else{
			a_index = person_num++;
			nametonum[a] = a_index;
			all[a_index].name = a;
		}
		
		if(nametonum.find(b)!=nametonum.end()){
			b_index = nametonum[b];
		}else{
			b_index = person_num++;
			nametonum[b] = b_index;
			all[b_index].name = b;
		}
		
		if(all[a_index].weight.find(b_index)==all[a_index].weight.end()){
			all[a_index].connect.push_back(b_index);
			all[a_index].weight[b_index]=k;
			all[b_index].connect.push_back(a_index);
			all[b_index].weight[a_index]=k;
		}
		else{
			all[a_index].weight[b_index]=k+all[a_index].weight[b_index];
			all[b_index].weight[a_index]=k+all[b_index].weight[a_index];
		}
		all[a_index].sum = all[a_index].sum+k;
		all[b_index].sum = all[b_index].sum+k;
	}
	
	for(i=0;i<person_num;i++){
		if(vis[i]==false){
			vis[i]=true;
			head_no = i;
			head_weight = all[i].sum;
			sum_weight = 0;//weight of edge
			sum_man = 1;
			DFS(i);

			if(sum_man>2 ){
				if(sum_weight>K){
					result_name.push_back(all[head_no].name);
					all[head_no].sum_man = sum_man;
				}
			}
		}
	}
	
	cout<<result_name.size()<<endl;
	sort(result_name.begin(),result_name.end()); 
	for(i=0;i<result_name.size();i++){
		cout<<result_name[i]<<" "<<all[nametonum[result_name[i]]].sum_man<<endl;
	}
    return 0;
}


