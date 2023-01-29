#include<bits/stdc++.h>
using namespace std;

int karat(int a,int b){
    string as=to_string(a);
    string bs=to_string(b);
    int alen=as.length();
    int blen=bs.length();
    if(alen==1 && blen==1){
        return a*b;
    }
    else{
        int n=alen>blen?alen:blen; //stores length of larger number
        while(alen!=n){
            as='0'+as;
            alen=as.length();
        }
        while(blen!=n){
            bs='0'+bs;
            blen=bs.length();
        }
        int al=stoi(as.substr(0,n/2));
        int ar=stoi(as.substr(n/2,n-(n/2)));
        int bl=stoi(bs.substr(0,n/2));
        int br=stoi(bs.substr(n/2,n-(n/2)));
        int x1=karat(al,bl);
        int x2=karat(al+ar,bl+br);
        int x3=karat(ar,br);
        int m=ceil(n/2.0);
        return (x1*pow(10,m*2)+(x2-x1-x3)*pow(10,m)+x3);
    }
}

int main(){
    std::cout<<karat(42,53);
    return 0;
}