#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 103
/*�����Լ�����Сʱ

���������ǲ��� ��bugһ�ѡ������� 
����ճ��������һ�����ĸ�Դ������ 

 	r = new node
	����ָ������Ĵ���1����ֵǰ���ǿ��ٿռ䣡
    struct node* lkid 
    ����ָ������Ĵ���2������ʱ���ǳ�ʼ��Ϊ��ָ�룡 
    1�����ڵ�ɲ�����ֱ���ýṹ�����ָ���ʾ�أ����� 
    ��Ϊ��������ڴ汬����ÿ����������һ��node�����滹��node������һ���һ�㣬һ���������ڴ�ľ���
	ָ���鷳�ĵط����������Ϳ����ڴ�ռ���룬������Ҳ��ָ������ĵط��� 
*/
int n,m,want; 
struct node{
	int root;
	int data;
	struct node* lkid =NULL;//���ĸ�Դ2������ʱ��δ��ʼ��NULL 
	struct node* rkid = NULL ;
};

//�����и������״�ĵط�
/*
ע�⣬ͨ��ָ�����������������Ҫ��->����. 
*/ 
void insert(node* &r,int data){
	if(r == NULL){
		r = new node;//��ѽ���������Ĺؼ�����䣬û���˾͸����޷�����data����Ϊָ��Ϊ��ʱ����ַ�޷����� 
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

