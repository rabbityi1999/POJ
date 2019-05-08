#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>

#define N 1000
//建议有关树的题目，一定要自己测一测这样只有根节点的特殊数据 
using namespace std;
int n;
int m;
//要改 ！！！ 
int max_num = 0;
int max_level = -1;

struct node{
	int depth;
	vector<int> child;
};

struct node all[N];
int level[N] = {0};

void BFS(int rootnode){
	queue<int> Q;
	all[rootnode].depth = 1;
	Q.push(rootnode);
	struct node front;
	//level[1] = 1; 开始就是这个地方，让自己没有全对！！！
	//但是自己写了一个只有根节点的数据de出来了bug，建议有关树的题目，一定要自己测一测这样只有根节点的特殊数据 
	 
	int j;
	
	while(!Q.empty()){
		front = all[Q.front()];
		Q.pop();
		level[front.depth]++;
		if(level[front.depth]>max_num){
			max_num = level[front.depth];
			max_level = front.depth;
		}
		for(j=0;j<front.child.size();j++){
			all[front.child[j]].depth = front.depth+1;
			Q.push(front.child[j]);
		}
	}
	
}

int main(){
	cin>>n>>m;
	int i,j,input,b,child,rootnode;
	for(i=0;i<m;i++){
		cin>> input>>b;
		for(j=0;j<b;j++){
			cin>>child;
			all[input].child.push_back(child);
		}
	}
	
	BFS(1);
	cout<<max_num<<" "<<max_level;
	return 0;
}


