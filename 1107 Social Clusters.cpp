#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 1000
int n;
int save[N]={0};
int result[N]={0};
int no=0;
map<int,int >htob;//���õ���Ķ�Ӧ 
map<int,int>bton;//���������Ķ�Ӧ 

int blockno = 0;

void insert(int no, int sum){
	int j,i,input,find;
	vector <int>save;
	for(find=-1,j=0;j<sum;j++){
		cin>>input;
		save.push_back(input);
		//����ҵ��� 
		if(htob.find(input)!=htob.end()){
			find = htob[input];//find is the block having the hobby
		}
	}
	if(find != -1){
		bton[find] =bton[find]+1;
		for(j=0;j<sum;j++){
			htob[save[j]]=find;
		}
	}else{//�Լ���Ϊһ���� 
		bton[blockno] =  1;
		for(j=0;j<save.size();j++){
			htob[save[j]]=blockno;
		}
		blockno++;
	}
} 

int main()
{
	cin>> n;
	int i,j,input,sum;
	for(i=0;i<n;i++){
		scanf("%d:",&sum);//������������ʣ���������ʲô����:�Ͳ������ˣ������� 
	    insert(i,sum);
	}
	for(i=0;i<blockno;i++){
		result[i]=bton[i];
	}
	sort(result,result+blockno);
	cout<<blockno<<endl;
	for(i=blockno-1;i>=0;i--){
		cout<<result[i];
		if(i!=0){
			cout<<" ";
		}
	}
	
    return 0;
}

