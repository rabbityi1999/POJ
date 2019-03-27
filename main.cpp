#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL a,b,c;
    LL i;
    string result="",out="";
    cin>>a>>b;
    c = a + b;
    result = to_string(c);

    if(result[0]=='-'){
        result=result.substr(1,result.length()-1);
        for(i=result.length()-1;i>=3;i=i-3){

            out=result.substr(result.length()-3,3)+out;
            out = ","+out ;
            result=result.substr(0,result.length()-3);
        }
        out=result+out;
        out="-"+out;
    }
    else{
        for(i=result.length()-1;i>=3;i=i-3){

            out = result.substr(result.length()-3,3)+out;
            out = ","+out ;
            result=result.substr(0,result.length()-3);
        }
        out=result+out;
    }

    cout<< out << endl;
    return 0;
}
