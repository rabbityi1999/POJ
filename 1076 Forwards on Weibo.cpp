#include <bits/stdc++.h>
using namespace std;
#define N 100//change to 2000
int person_num=0;
int n,K;//number of phone and weight threthold
set<int> result;
bool inq[N];
struct node{
	int no;
	set<int> follow;
	int level;
};
struct node all[N];
//�����и�Ҫע��ĵط���������queue��ָ�룬�Ż����һ���㲻��ʱ�������ṹ��ܴ�ÿ�ζ�����һ��ǳ��˷�ʱ�䣡���� 
int BFS(int root){
	queue<node*> Q;
    node head;
	int deep=0;
	int effected=0;
	set<int> already;//�Ѿ�������� 
	all[root].level=0;
	Q.push(all + root);
	set<int>::iterator it;
	set<int> forpush;
	already.insert(root);
	inq[root]=true;
	while(!Q.empty()&&deep<K){
		head=*(Q.front());//��ͻȻ�����Լ����ű�����������ˣ�������stack��top����������queue��front��������������һ���ģ��� 
		Q.pop();
		for(it=head.follow.begin();it!=head.follow.end();it++){
			if(inq[*it]==false&&head.level<K){	//������˵� 
	            effected++;
				all[*it].level=head.level+1;
				Q.push(all + *it);
				inq[*it]=true;
			}
		}
		//����������⣬һ�ε�deep��ͳһ�ģ���Ӧ��ÿ�ζ��� 
		
	}
	return effected;
}

int main()
{
	cin>>n>>K;
	int i,j,k,num,now,times;
	int a_index,b_index;
	bool same = false;
	
	for(i=0;i<n;i++){
		cin>>num;
		all[i+1].no=i+1;
		for(j=0;j<num;j++){
			cin>>now;
			all[now].follow.insert(i+1);
		}
	}
	cin>>times;
	for(i=0;i<times;i++){
		cin>>now;
		memset(inq,false,sizeof(inq));
		if(find(result.begin(),result.end(),now)==result.end()){
			cout<<BFS(now)<<endl;
			result.insert(now);
		}
	}
	
    return 0;
}


