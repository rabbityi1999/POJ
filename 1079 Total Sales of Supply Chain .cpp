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
//Ҫ�� 
#define N 1000
double sum; 
/*�ѵ����ڣ�����˳�����ҵ�
��Ҫ��¼���level������ 
*/
//��Ӧ�ڵ�ţ�level 
map<int,int> level;
int fa[N] = {0};
//��Ӧ�����̺��룬�������ܶ�
map<int,int> sale;//��Ʒ���Բ�����

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
	//��ӣ���cin�������س�getlineȴ�Ὣ���е�һ�а����س������������� ���Լ���getline֮���ǲ���Ҫgetchar�ģ�����getline����cin����Ҫgetchar 
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


