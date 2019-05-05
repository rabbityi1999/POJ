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
需要记录这个level，但是 
*/
//对应节点号，level 
map<int,int> level;
int fa[N] = {0};
//对应零售商号码，和销售总额
map<int,int> sale;//商品可以拆开卖吗

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
double POW(double x,int y,double z){
	int i;
	double mul=1;
	for(i=0;i<y;i++){
		mul=x*mul;
	} 
	return mul*z;
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


