#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 103
/*做了自己两个小时

关于链表还是不熟 ，bug一堆。。。。 
复制粘贴代码是一切罪恶的根源！！！ 

 	r = new node
	关于指针最常见的错误1，赋值前忘记开辟空间！
    struct node* lkid 
    关于指针最常见的错误2，定义时忘记初始化为空指针！ 
    1、根节点可不可以直接用结构体而非指针表示呢？—— 
    因为这样会把内存爆掉，每个孩子域都是一个node，里面还有node，这样一层接一层，一旦声明把内存耗尽的
	指针麻烦的地方在于声明和开辟内存空间分离，但是这也是指针奇妙的地方。 
*/
int n,m,want; 
struct node{
	int root;
	int data;
	struct node* lkid =NULL;//罪恶的根源2：定义时候未初始化NULL 
	struct node* rkid = NULL ;
};

//这里有个很容易错的地方
/*
注意，通过指针访问它的数据域需要用->而非. 
*/ 
void insert(node* &r,int data){
	if(r == NULL){
		r = new node;//妈呀这是致命的关键性语句，没有了就根本无法访问data，因为指针为空时，地址无法访问 
		r ->data = data;
//		r->lkid = r->rkid =NULL;
	}else{
		if((r->data)>data){
			insert(r->lkid,data);
		}else{
			insert(r->rkid,data);
		}
	}
}

void verinsert(node* &r,int data){
	if(r == NULL){
		r = new node;
		r->data = data;
//	    r->lkid = r->rkid =NULL;
	}else{
		if((r->data)<=data){
			verinsert(r->lkid,data);
		}else{
			verinsert(r->rkid,data);
		}
	}
}

vector<int> input;
vector<int> savepre;
vector<int> savepost; 
void pre(node* r){
	if(r!=NULL){
		savepre.push_back(r->data);
  		pre(r->lkid);    
		pre(r->rkid);
	}
}
void post(node* r){
	if(r!=NULL){
        post(r->lkid);
		post(r->rkid);
		savepost.push_back(r->data);
	}
}
void isyes(node* r){
	post(r);
	cout<<"YES"<<endl;
	int i;
	for(i=0;i<savepost.size();i++){
		cout<<savepost[i];
		if(i!=savepost.size()-1){
		    cout<<" ";
		}
	}
} 
int main()
{
node* root = NULL;
node* verroot = NULL;
	cin>> n;
	bool equal = false;
    int i,j,fa,child_num,child_id;
    for(i=0;i<n;i++){
    	cin >>j;
    	input.push_back(j);
		insert(root,j);
		verinsert(verroot,j);
	}
  	savepre.clear();
//  	savepost.clear();
  	pre(root);
  	if(input.size()==savepre.size()){
  		for(equal =true,i=0;i<input.size();i++){
  			if(input[i]!=savepre[i]){
  				equal = false;
  				break;
		    }
  		}
    }
    
  	if(equal==false){
  		savepre.clear();
  		pre(verroot);
  		if(input.size()==savepre.size()){
	  		for(equal =true,i=0;i<input.size();i++){
	  			if(input[i]!=savepre[i]){
	  				equal = false;
	  				break;
			    }
	  		}
    	}
    	if(equal==true){
    		isyes(verroot);
		}else{
			cout<<"NO";
		}
    }else{
    	isyes(root);
	}

    return 0;
}

