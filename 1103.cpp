#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set> 
#include <queue>
#include <vector>
using namespace std;
int n,k,p;
//nowK当前已选数的个数 
 // sumP当前的p平方和
 // sumf当前的因子平方和
 // s，当前所选的数 
 //当前正在处理的第index个数
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
	//选新的index遍历,这里index可重复 
	s.push_back(num[index]);
	if(nowK+1<=k &&  sumP+pow(num[index],p)<=n){
		DFS(index,nowK+1,sumP+pow(num[index],p),sumf+num[index],s); 
	}
	s.pop_back();
	//不选新的index遍历
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
	vector<int> s;
//	s.push_back(1);
	cin>>n>>k>>p;
	chose(n,p);
	DFS(0,0,0,0,s);
	if(sum_ans==-1)
 	    cout<<"Impossible";
 	else{
 		vector<int>::iterator it;
 		cout<<n;
		for(it=ans.begin();it<ans.end();it++){
			if(it==ans.begin()){
				cout<<" = ";
			}
			else{
				cout<<" + ";
			}
			cout<<*it<<"^"<<p;
		} 
	 }
 	cout<<endl; 
	return 0;
}


