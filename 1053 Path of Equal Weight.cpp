#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 103
/*
算法总结：
这道题目也可以用DFS做，好处是不需要再使用优先队列了。（如果自己用C语言写应该会这样写）
只需要对于 vector<int> child;做个排序输入就好。
但是BFS用这个技巧会出现问题。
 
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
		else if(all[front].path_w < want){//这里自己添加了一个条件，使得更加优化 
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
这里自己用下面的写法总是出错，不知道是不是因为priority_queue的特性？
     
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

