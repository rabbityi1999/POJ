#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 1000
int n;
int save[N]={0};
vector<int> result;
int no=0;
struct node{
	int v;
	int height;
	node* lchild;
	node* rchild;
};
node* newNode(int v){
	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
int getHeight(node* root){
	if(root==NULL){
		return 0;//这里很容易忘掉！！！ 
	}
	return root->height;
}
void updateHeight(node* root){
	root->height = max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
int getBalanceFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}

void L(node* &root){
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);//别忘记了更新告诉 
	updateHeight(temp);
	root = temp;//最后才更新root 
}

void R(node* &root){
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root= temp;
}

void insert(node* &root,int v){
	if(root ==NULL){
		root =  newNode(v);
		return;
	}
	if(v< root->v){
		insert(root->lchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){//LL型 
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1)//LR型 
			{
				L(root->lchild);
				R(root);
			} 
		}
	}else{
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				L(root);	
			}else if(getBalanceFactor(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
}

int main()
{
	cin>> n;
	int i,input;
	node* root=NULL;//建立时候一定要初始化为NULL 
	for(i=0;i<n;i++){
		cin>>input;
		insert(root,input);
	}
	cout<<root->v;
    return 0;
}

