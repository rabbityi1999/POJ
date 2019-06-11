#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define N 1000
int n;
int save[N]={0};
int result[N]={0};
int no=0;
map<int,int >htob;//爱好到块的对应 
map<int,int>bton;//块与人数的对应 

int blockno = 0;

void insert(int no, int sum){
	int j,i,input,find;
	vector <int>save;
	for(find=-1,j=0;j<sum;j++){
		cin>>input;
		save.push_back(input);
		//如果找到了 
		if(htob.find(input)!=htob.end()){
			find = htob[input];//find is the block having the hobby
		}
	}
	if(find != -1){
		bton[find] =bton[find]+1;
		for(j=0;j<sum;j++){
			htob[save[j]]=find;
		}
	}else{//自己成为一个块 
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
		scanf("%d:",&sum);//关于输入的疑问？？？？问什么不加:就不可以了？？？？ 
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

