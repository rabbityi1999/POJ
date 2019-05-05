#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>
using namespace std;
int n;
/*耗时：1h+25min*/
 
vector<int> post;
vector<int> in;
struct node{
	   int data;
	   node* left;
	   node* right;
};

node* FIND(int P_left,int P_right,int I_left,int I_right){
	node* NEW_left = new node;
	node* NEW_right = new node;
	node* root = new node;
	root->data = post[P_right];
	int root_pos;
	int j;
	
	if(P_left>P_right||I_left>I_right){
		return NULL;
	}
	
	for(j=I_left;j<=I_right;j++){/*这里有个bug，很容易写成<而忘记等于号*/ 
		if(in[j]==post[P_right]){
			root_pos=j;
		}
	}
	int length,lengthR;
	length = root_pos-I_left;
	lengthR = I_right - root_pos;
	
	//以下这一段都是我写的废话，细思极恐的是，这一段本来非常精妙 
	//能够推算出来的东西，就尽量代码简化 
//	
//	//注意存在找不到的问题
//	 int k,isin=false;
//	for(j=P_left;j<P_right;j++){
//		isin=false;
//		for(k=I_left,isin=false;k<root_pos;k++){
//			if(in[j]==in[k]){
//				isin=true;
//				break;
//			}
//		}
//		if(isin==false){
//			break;
//		}
//	}
//	
	
	NEW_left = FIND(P_left,P_left+length-1,I_left,root_pos-1);
	NEW_right = FIND(P_right-lengthR,P_right-1,root_pos+1,I_right);
	
	root->left = NEW_left;
	root->right = NEW_right;
	return root;
}
vector<int> out;
vector<int> out1;

int change(string s){
	if(s=="-"){
		return -1;
	
	}
	else{
		istringstream in(s);
		int num;
		in>>num;
		return num;
	}
}
int left_a[50]={-1};
int right_a[50]={-1};

void level_traverse(int  n){
	queue<int> Q;
	Q.push(n);
	int front;
	while(!Q.empty()){
		front = Q.front();
		Q.pop();
		out.push_back(front);
		if(right_a[front]!=-1)
		{
			Q.push(right_a[front]); 
		} 
		if(left_a[front]!=-1){
			Q.push(left_a[front]);
		}
	}
}
bool vis[50]={false};
void in_traverse(int front){
	
	if(right_a[front]!=-1){
		in_traverse(right_a[front]);
	}
	
	out1.push_back(front);
	
	if(left_a[front]!=-1){
		in_traverse(left_a[front]);
	}
}

int main(){
	cin>> n;
	string L,R;
	set<int> exist;
	fill(left_a,left_a+n,-1);
	fill(right_a,right_a+n,-1);
	int i,j;
	int now;
	for(i=0;i<n;i++){
		cin>>L>>R;
		left_a[i]=change(L);
		right_a[i]=change(R);
		exist.insert(left_a[i]);
		exist.insert(right_a[i]);
	} 
	for(i=0;i<n;i++){
		if(exist.find(i)==exist.end()){
			break;
		}
	}
	in_traverse(i);
	level_traverse(i);
	for(i=0;i<n;i++){
		if(i!=0){
			cout<<" ";
		}
		cout<<out[i];
	}
	cout<<endl;
	for(i=0;i<n;i++){
		if(i!=0){
			cout<<" ";
		}
		cout<<out1[i];
	}
	
	return 0;
}


