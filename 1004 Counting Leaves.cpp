#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
typedef long long LL;
/* 
发现一个很神奇的规律：如果文中出现:there must be no extra space at the end of each line.
最后就不要加endl换行了
靠着这个拯救了一半的点 
*/
int main()
{
    LL i,j,fa,child_num,child_id;
    int d[150][150]={0};//如果是0，说明为空
    int level;
    int level_num[150]={0};
    int n,m;
   cin>>n;
   if(n==0)return 0;
   cin>>m;
   priority_queue<int> Q;
   for(i=0;i<m;i++){//都是从0开始
        cin>>fa>>child_num;
        for(j=0;j<child_num;j++){
            cin>>child_id;
            d[fa][child_id]=1;//说明fa 有一个id为child_id 的子节点
        }
   }

   //开始BFS，这里只有一个树，故所有的结点最后必定都会入队一次近仅且一次,不需要vis数组标记

   level = 0;//第0层
   Q.push(1);//根结点入队
   int vis = 0;
   set<int>::iterator it;
   int head;
   set<int> CHILD;
   //必须待所有上一层结点都访问过后，下一层结点才可以入队
   while(vis<n){
    CHILD.clear();
    while(!Q.empty()){//这是第level层的
        head = Q.top();
        Q.pop();
        vis++;//只有每个点处理过后vis才++
        //开始数，head结点有哪些孩子结点，分别入队
        if(count(d[head],d[head]+150,1)==0){
            level_num[level]++;//没有孩子的结点+1
        }else{
            for(i=1;i<=n;i++){
                if(d[head][i]){
                    CHILD.insert(i);//将所有孩子放入集和中
                }
            }
        }
    }
   //第level层遍历完之后，才统一将孩子结点全部放入队列中
        level++;
        for(it = CHILD.begin();it!=CHILD.end();it++){
            Q.push(*it);
        }
   }
   cout<<level_num[0];
    for(i=1;i<level;i++){
        cout<<" "<<level_num[i];
    }
    return 0;
}

