#include <bits/stdc++.h>
using namespace std;
/*这道题暗藏坑点！！！！ 系数为0的项是不需要输出的！！！ 要作个判断！！！*/
typedef long long LL;

int main()
{
    map <LL,double ,greater<LL> > Map;
    LL i,j,num_a,num_b,exp;
    double coef,toadd;
    cin>>num_a;
    for(i=0;i<num_a;i++){
        cin>>exp>>coef;
        if(coef!=0){
               Map.insert(make_pair(exp,coef));
        }
    }
    cin>>num_b;
    for(i=0;i<num_b;i++){
        cin>>exp>>coef;
        if(Map.find(exp)!=Map.end()){
            toadd=Map[exp];
            coef =toadd+coef;
            Map.erase(exp);
            if(coef!=0){
               Map.insert(make_pair(exp,coef));
            }
        }
        else{
            if(coef!=0){
                Map.insert(make_pair(exp,coef));
            }
        }
    }
    map <LL,double >:: iterator it;
    cout<<Map.size();
    for(it = Map.begin();it!=Map.end();it++){
        cout<<" "<<it->first<<" "<<fixed<<setprecision(1)<<it->second;
    }
    return 0;
}
