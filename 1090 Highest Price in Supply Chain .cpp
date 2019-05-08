#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>

#define N 1000
using namespace std;
int n;
double price;
double r;
//Òª¸Ä £¡£¡£¡ 
int number = 0;
double final_p;
int max_depth=-1;
struct node{
	int root;
	int depth;
	vector<int> child;
}; 
struct node all[N];


void BFS(int rootnode){
	queue<int> Q;
	Q.push(rootnode);
	struct node front;
	all[rootnode].depth = 0;
	int j;
	
	while(!Q.empty()){
		front = all[Q.front()];
		Q.pop();
		if(front.child.size()==0){
			if(front.depth > max_depth){
				max_depth = front.depth;
				number = 1;
			}else if(front.depth=max_depth){
				number++;
			}
		}
		else{
			for(j = 0;j<front.child.size();j++){
				all[front.child[j]].depth = front.depth+1;
				Q.push(front.child[j]);
			}
		}
	}
	
}

int main(){
	cin>>n>>price>>r;
	int i,input,rootnode;
	for(i=0;i<n;i++){
		cin>> input;
		if(input== -1){
			rootnode = i;
		}else{
			all[input].child.push_back(i);
		}
	}
	
	BFS(rootnode);
	final_p = price*pow(r/100 + 1,max_depth);
	printf("%.2f %d",final_p,number);
	return 0;
}


