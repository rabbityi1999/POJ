#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>

#define N 1000
//�����й�������Ŀ��һ��Ҫ�Լ���һ������ֻ�и��ڵ���������� 
using namespace std;
int n;
int m;
//Ҫ�� ������ 
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
	//level[1] = 1; ��ʼ��������ط������Լ�û��ȫ�ԣ�����
	//�����Լ�д��һ��ֻ�и��ڵ������de������bug�������й�������Ŀ��һ��Ҫ�Լ���һ������ֻ�и��ڵ���������� 
	 
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


