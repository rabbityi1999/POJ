#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <queue>

/*
考试的时候发现有visual 2012于是就没有用dev c++
在visual 2012 上  auto p = 1的语法是成立的于是自己选择了C++11标准C0X，结果编译没有通过.....
这告诉我们选对一个对的编译环境有多么重要，最好多用dev C++这个自带的软件练习，不要吃软件的亏.....;

*/
typedef long long LL;
using namespace std;
#define N 1000//change

LL RS[N][N] = {0};
struct block{
	int number;
	string data;
	LL x,y;
};
queue<string> save[N];
bool vis[N] = {false};
vector <string > now[N];
bool canbreak(LL n){
	if(count(vis,vis+n,false)==0){
		return false;
	}
	LL i;
	for(i=0;i<n;i++){
        if(!save[i].empty()){
        	return true;
		}
	}
	return false;
}

int main(){
    LL T,n;
    cin>>T>>n;
	getchar();
	LL i,j,k,x,y;
	string s,temp,command;

	for(i=0;i<T;i++){
		fill(vis,vis+n,false);
		for(x=0;x<n;x++){
			while(!save[x].empty())
			save[x].pop();
		}
		for(j=0;j<n;j++){
			getline(cin,s);
			istringstream in(s);
			while(in>>temp){
				save[j].push(temp);
			}
		}
		x=0;

		while(canbreak(n)){
			if(vis[x]==false){
				if(save[x].empty()){
					x++;
					continue;
				}
				command = save[x].front();
				save[x].pop();
				if(now[(command[1]-'0')].size()!=0){
					if(now[(command[1]-'0')][0][1]==x+'0')
  					    if(now[(command[1]-'0')][0][0]!=command[0]){
  					    	now[(command[1]-'0')].clear();
			  				now[x].clear();
			  				vis[(command[1]-'0')]=false;
			  				continue;
				        }
				}
				now[x].push_back(command);
				vis[x]=true;
			}
			else{
				x++;
				x=x%n;
			}
		}
		if(count(vis,vis+n,true)==0)
		   cout<<"0"<<endl;
        else
           cout<<"1"<<endl;
	}
    return 0;
}
