#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 1000
int n;
int save[N]={0};
vector<int> result;
int no=0;
struct node{
	int data;
	int lkid;
	int rkid;
	
};
struct node all[N];
/*��ʱһ��Сʱ���������Ը���ģ�
���ǿ�ʼ��ʱ������㷨��ƴ��ˣ�
����������˿ո�*/
/*
��ᷢ�ּ������й���������Ŀ���޷������ֱ�����ѡ����+DFS/BFS
֮�󣬾�Ҫ�����˵��㷨�߼���������Ͻ����ˣ� 
*/ 
 
void pre(int root){
	if(all[root].lkid!=-1){
					 pre(all[root].lkid);	
	}
	all[root].data = save[no];
	no++;
	if(all[root].rkid!=-1){
		pre(all[root].rkid);
	}
}
void level(){
	queue<int> Q;
	int head;
	Q.push(0);
	while(!Q.empty()){
		head=Q.front();
		Q.pop();
		result.push_back(all[head].data);
		if(all[head].lkid!=-1){
			Q.push(all[head].lkid);
		}
		if(all[head].rkid!=-1){
							   Q.push(all[head].rkid);
		}
	}
}
int main()
{
	cin>> n;
	int i;
	for(i=0;i<n;i++){
		cin>>all[i].lkid>>all[i].rkid;
	}
	for(i=0;i<n;i++){
		cin>>save[i];
	}
	sort(save,save+n);
	
  	pre(0);
  	level();
  	for(i=0;i<n;i++){
  		cout<<result[i];
		if(i!=n-1)  cout<<" ";//��������������Ǹ�ʽ���󣬲������е�bug������ͨ�����Զ�����ġ��ؼ���������㷨���߼���֤��˼ά����д����ʱ���˼����ģ������ 
		
	}
	cout<<endl;
    return 0;
}

