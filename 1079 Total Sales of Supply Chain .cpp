#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
int n;
double price;
double r;
//要改 
#define N 1000
double sum; 
/*难点在于，结点的顺序是乱的
需要记录这个level
*/

/*这里自己最后一个点运行超时了，自己的实现方法和官方的操作方法区别在于，
他们使用了DFS，DFS跟动态规划的思路比较像，在通常的情况下是可以节省时间的
自己对于每一个叶子结点都需要从底到根的遍历，非常消耗时间。
DFS则可以重用，所以，尽管自己的代码算法思考起来比较简单，但是还是建议采用DFS的方式实现 
*/

/*
自己总是容易把注意力放在高端的STL操作上，而非算法上而浪费太多时间。
比如这里的instringstream开始自己的读入方法，非常的复杂，还因为getchar 的问题而失分了。
一开始，一定要把注意力放在算法上！！！如何降低时间复杂度。
STL难度太大，容易使得debug出现困难。能用巧妙的算法解决的，绝对不要上乱七八糟的骚操作。充分挖掘题目信息！ 
*/ 

int fa[N] = {0};
//对应零售商号码，和销售总额
map<int,int> sale;

void input_copy(int no){
	string input;
	int a;
//	getline(cin,input);
//	
//	istringstream in(input);
//	int num;
	int i;
//	int save[N];
//	int j=0;
//	while(in>>num){
//		save[j]=num;
//		j++;
//		
//	}
cin>>a;
//	if(save[0]!=0){
//		for(i=1;i<j;i++){
//			fa[save[i]]=no;
//		}
//	}else{
//		  sale[no]=save[1];
//	}
int b;
	if(a!=0){
		for(i=0;i<a;i++){
			cin>>b;
			fa[b]=no;
		}
	}else{
		cin>>b;
		sale[no]=b; 
	}
}

int main(){
	int now;
	int i,j,count;
	level[0]=0;
	sum=0;
	//神坑！！cin不会读入回车getline却会将所有的一行包括回车都读掉！！！ 所以几个getline之间是不需要getchar的，但是getline跟在cin后面要getchar 
	double oneh =100;
	
	cin>> n>>price>>r;
	double beishu = r/100 +1.0;
//	getchar();
	for(i=0;i<n;i++){
		input_copy(i);
	}
	
	map<int,int>::iterator it;
	for(it=sale.begin();it!=sale.end();it++){
		count=0;
		j=it->first;
		
		do{
			if(j!=0){
				count++; 
			}
			j=fa[j];
		}while(j!=0);

		sum=sum+((double)(it->second))*pow(beishu,count)*price;
	}
	printf("%.1f",sum);
	return 0;
}

