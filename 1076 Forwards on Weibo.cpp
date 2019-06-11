#include <bits/stdc++.h>
using namespace std;
#define N 100//change to 2000
int person_num=0;
int n,K;//number of phone and weight threthold
set<int> result;
bool inq[N];
struct node{
	int no;
	set<int> follow;
	int level;
};
struct node all[N];
//这里有个要注意的地方，必须是queue用指针，才会最后一个点不超时！！！结构体很大，每次都复制一遍非常浪费时间！！！ 
int BFS(int root){
	queue<node*> Q;
    node head;
	int deep=0;
	int effected=0;
	set<int> already;//已经计算过的 
	all[root].level=0;
	Q.push(all + root);
	set<int>::iterator it;
	set<int> forpush;
	already.insert(root);
	inq[root]=true;
	while(!Q.empty()&&deep<K){
		head=*(Q.front());//我突然明白自己蓝桥杯哪里出问题了！！！！stack是top函数，但是queue是front函数！！！！不一样的！！ 
		Q.pop();
		for(it=head.follow.begin();it!=head.follow.end();it++){
			if(inq[*it]==false&&head.level<K){	//计算过了的 
	            effected++;
				all[*it].level=head.level+1;
				Q.push(all + *it);
				inq[*it]=true;
			}
		}
		//这里出了问题，一次的deep是统一的，不应该每次都加 
		
	}
	return effected;
}

int main()
{
	cin>>n>>K;
	int i,j,k,num,now,times;
	int a_index,b_index;
	bool same = false;
	
	for(i=0;i<n;i++){
		cin>>num;
		all[i+1].no=i+1;
		for(j=0;j<num;j++){
			cin>>now;
			all[now].follow.insert(i+1);
		}
	}
	cin>>times;
	for(i=0;i<times;i++){
		cin>>now;
		memset(inq,false,sizeof(inq));
		if(find(result.begin(),result.end(),now)==result.end()){
			cout<<BFS(now)<<endl;
			result.insert(now);
		}
	}
	
    return 0;
}


