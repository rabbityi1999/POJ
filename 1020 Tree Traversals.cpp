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
���Ե�ʱ������visual 2012���Ǿ�û����dev c++
��visual 2012 ��  auto p = 1���﷨�ǳ����������Լ�ѡ����C++11��׼C0X���������û��ͨ��.....
���������ѡ��һ���Եı��뻷���ж�ô��Ҫ����ö���dev C++����Դ��������ϰ����Ҫ������Ŀ�.....;

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
