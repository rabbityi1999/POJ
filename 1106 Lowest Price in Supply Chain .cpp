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
double price;
double r;
//要改 ！！！ 
int max_num = 0;
int min_level = 100000000;

struct node{
	int depth;
	vector<int> child;
};

struct node all[N];
int level[N] = {0};

void BFS(int rootnode){
	queue<int> Q;
	all[rootnode].depth = 0;
	Q.push(rootnode);
	struct node front;
	int j;
	while(!Q.empty()){
		front = all[Q.front()];
		Q.pop();
		if(front.child.size()==0){
			if(front.depth < min_level){
				min_level = front.depth;
				max_num = 1;
			}else if(front.depth == min_level){
				max_num++;
			}
		}else{
			for(j=0;j<front.child.size();j++){
				all[front.child[j]].depth = front.depth+1;
				Q.push(front.child[j]);
			}
		}
	}
}

int main(){
	cin>>n>>price>>r;
	double sum;
	int i,j,input,b,child,rootnode;
	for(i=0;i<n;i++){
		cin>> input;
		if(input!=0){
			for(j=0;j<input;j++){
				cin>>child;
				all[i].child.push_back(child);
			}
		}
	}
	
	BFS(0);
	sum = price*pow(r/100 + 1,min_level);
	printf("%.4f %d",sum,max_num);
	return 0;
}


