#include <bits/stdc++.h>
using namespace std;

#define INF 100000000
typedef long long LL;
/* 
����һ��������Ĺ��ɣ�������г���:there must be no extra space at the end of each line.
���Ͳ�Ҫ��endl������
�������������һ��ĵ� 
*/
int main()
{
    LL i,j,fa,child_num,child_id;
    int d[150][150]={0};//�����0��˵��Ϊ��
    int level;
    int level_num[150]={0};
    int n,m;
   cin>>n;
   if(n==0)return 0;
   cin>>m;
   priority_queue<int> Q;
   for(i=0;i<m;i++){//���Ǵ�0��ʼ
        cin>>fa>>child_num;
        for(j=0;j<child_num;j++){
            cin>>child_id;
            d[fa][child_id]=1;//˵��fa ��һ��idΪchild_id ���ӽڵ�
        }
   }

   //��ʼBFS������ֻ��һ�����������еĽ�����ض��������һ�ν�����һ��,����Ҫvis������

   level = 0;//��0��
   Q.push(1);//��������
   int vis = 0;
   set<int>::iterator it;
   int head;
   set<int> CHILD;
   //�����������һ���㶼���ʹ�����һ����ſ������
   while(vis<n){
    CHILD.clear();
    while(!Q.empty()){//���ǵ�level���
        head = Q.top();
        Q.pop();
        vis++;//ֻ��ÿ���㴦�����vis��++
        //��ʼ����head�������Щ���ӽ�㣬�ֱ����
        if(count(d[head],d[head]+150,1)==0){
            level_num[level]++;//û�к��ӵĽ��+1
        }else{
            for(i=1;i<=n;i++){
                if(d[head][i]){
                    CHILD.insert(i);//�����к��ӷ��뼯����
                }
            }
        }
    }
   //��level�������֮�󣬲�ͳһ�����ӽ��ȫ�����������
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

