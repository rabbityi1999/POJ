#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>
using namespace std;
int n,k,p;
//nowK��ǰ��ѡ���ĸ��� 
 // sumP��ǰ��pƽ����
 // sumf��ǰ������ƽ����
 // s����ǰ��ѡ���� 
 //��ǰ���ڴ���ĵ�index����
vector<int> ans;  
vector<int> num;
int sum_ans=-1;
bool cmp(int& x,int& y){
	return x>y;
}
void DFS(int index,int nowK, int sumP,int sumf,vector<int> s){
	
	if(nowK == k && sumP==n ){
		if(sumf>sum_ans){
			sum_ans=sumf;
			ans=s;
		}
//		else if(sumf==sum_ans){
////        	 sort(s.begin(),s.end(),cmp);	
//			 if(s>ans){
//			 	ans=s;
//			 }		
//		}
	}
	
	if(index>=num.size() || nowK>k ||sumP>n){
		return;
	}
	//ѡ�µ�index����,����index���ظ� 
	s.push_back(num[index]);
	if(nowK+1<=k &&  sumP+pow(num[index],p)<=n){
		DFS(index,nowK+1,sumP+pow(num[index],p),sumf+num[index],s); 
	}
	s.pop_back();
	//��ѡ�µ�index����
//	s.erase(find(s.begin(),s.end(),index));
	if(index+1<num.size()){
		DFS(index+1,nowK,sumP,sumf,s);
	}
	 
}
void chose(int n,int p){
	int i,j;
	for(i=n;i>=1;i--){
		if(pow(i,p)<=n){
			num.push_back(i);
		}
	}
}
int main(){
	cin>> n;
	
	return 0;
}

