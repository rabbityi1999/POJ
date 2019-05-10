#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 1000
int n;
int save[N]={0};
vector<int> result;
int no=0;
struct node{
	int data;
	int lkid;
	int rkid;
	
};
struct node all[N];
/*用时一个小时。本来可以更快的，
但是开始的时候设计算法设计错了，
后来最后多加了空格*/
/*
你会发现几乎所有关于树的题目，无非是四种遍历中选几个+DFS/BFS
之后，就要看个人的算法逻辑性与代码严谨性了！ 
*/ 
 
void pre(int root){
	if(all[root].lkid!=-1){
					 pre(all[root].lkid);	
	}
	all[root].data = save[no];
	no++;
	if(all[root].rkid!=-1){
		pre(all[root].rkid);
	}
}
void level(){
	queue<int> Q;
	int head;
	Q.push(0);
	while(!Q.empty()){
		head=Q.front();
		Q.pop();
		result.push_back(all[head].data);
		if(all[head].lkid!=-1){
			Q.push(all[head].lkid);
		}
		if(all[head].rkid!=-1){
							   Q.push(all[head].rkid);
		}
	}
}
int main()
{
	cin>> n;
	int i;
	for(i=0;i<n;i++){
		cin>>all[i].lkid>>all[i].rkid;
	}
	for(i=0;i<n;i++){
		cin>>save[i];
	}
	sort(save,save+n);
	
  	pre(0);
  	level();
  	for(i=0;i<n;i++){
  		cout<<result[i];
		if(i!=n-1)  cout<<" ";//这里评测机报错是格式错误，不是所有的bug都可以通过测试而避免的。关键还是设计算法的逻辑性证明思维，和写代码时候的思考，模拟流程 
		
	}
	cout<<endl;
    return 0;
}

