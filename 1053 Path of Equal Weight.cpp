#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 103
/*
�㷨�ܽ᣺
�����ĿҲ������DFS�����ô��ǲ���Ҫ��ʹ�����ȶ����ˡ�������Լ���C����дӦ�û�����д��
ֻ��Ҫ���� vector<int> child;������������ͺá�
����BFS��������ɻ�������⡣
 
*/ 
typedef long long LL;
int n,m,want; 
struct node{
	int root;
	int id;
	vector<int> child;
	int weight;
	int path_w;
};
struct node all[N]; 
//vector<vector<int> > path;
priority_queue<vector<int>  > path;
vector<int> find_path(int leaf){
	vector<int> a,b;
	int j=leaf,i; 
	while(j!=0){
	   a.push_back(all[j].weight);
	   j = all[j].root;
	}
	a.push_back(all[0].weight);
	for(i=a.size()-1;i>=0;i--){
		b.push_back(a[i]);
	}
	return b;
}
void BFS(){
	queue<int> Q;
	int front,j;
	all[0].path_w = all[0].weight;
	Q.push(0);
	while(!Q.empty()){
		front = Q.front();
		Q.pop();
		if(all[front].id!=0){
			all[front].path_w = all[all[front].root].path_w + all[front].weight; 
		}
		if(all[front].path_w == want){
			if(all[front].child.size()==0){
				path.push(find_path(front));
			}
		}
		else if(all[front].path_w < want){//�����Լ������һ��������ʹ�ø����Ż� 
	        if(all[front].child.size()>0){
	        	for(j=0;j<all[front].child[j];j++){
	        		Q.push(all[front].child[j]);
				}
			}	
		}
	} 
}
int main()
{
	cin>> n>> m >> want;
    LL i,j,fa,child_num,child_id;
    for(i=0;i<n;i++){
    	cin >> all[i].weight;
    	all[i].id = i;
	}
  	for(i=0;i<m;i++){
  		cin>>fa>>child_num;
		for(j=0;j<child_num;j++){
			cin>>child_id;
			all[fa].child.push_back(child_id);
			all[child_id].root = fa;
		}	
	}
	BFS();
	vector<int> tra;
	
while(!path.empty()){
		tra = path.top();
    	path.pop();
    	for(j=0;j<tra.size();j++){
    		cout<< tra[j];
			if(j!=tra.size()-1){
				cout<<" ";
			} 
		}
		cout<<endl;
}
/* 
�����Լ��������д�����ǳ�����֪���ǲ�����Ϊpriority_queue�����ԣ�
     
*/
//    for(i=0;i<path.size();i++){     
//	    cout<< path.size() <<"path.size() ";                        
//    	tra = path.top();
//    	path.pop();
//    	for(j=0;j<tra.size();j++){
//    		cout<< tra[j] <<" ";
//		}
//		cout<<endl;
//	}
    return 0;
}

