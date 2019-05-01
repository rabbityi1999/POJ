#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>
using namespace std;
int n;
/*��ʱ��1h+25min*/
 
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
	
	for(j=I_left;j<=I_right;j++){/*�����и�bug��������д��<�����ǵ��ں�*/ 
		if(in[j]==post[P_right]){
			root_pos=j;
		}
	}
	int length,lengthR;
	length = root_pos-I_left;
	lengthR = I_right - root_pos;
	
	//������һ�ζ�����д�ķϻ���ϸ˼���ֵ��ǣ���һ�α����ǳ����� 
	//�ܹ���������Ķ������;�������� 
//	
//	//ע������Ҳ���������
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
void level_traverse(node* n){
	queue<node> Q;
	Q.push(*n);
	node front;
	while(!Q.empty()){
		front = Q.front();
		Q.pop();
		out.push_back(front.data);
		if(front.left!=NULL)
		{
			Q.push(*front.left); 
		} 
		if(front.right!=NULL){
			Q.push(*front.right);
		}
	}
}
int main(){
	cin>> n;
	int i,j;
	int now;
	for(i=0;i<n;i++){
		cin>>now;
		post.push_back(now);
	} 
	for(i=0;i<n;i++){
		cin>>now;
		in.push_back(now);
	}
 	node* root = FIND(0,n-1,0,n-1);
 	level_traverse(root);
 	for(i=0;i<n;i++){
 		if(i!=0){
 			cout<<" ";
		}
		cout<<out[i];	 
	}
	return 0;
}


