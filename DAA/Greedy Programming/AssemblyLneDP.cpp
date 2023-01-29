#include <bits/stdc++.h>

int min(int a, int b){
    return a < b ? a : b;
}

int carAssembly(int a[][4],int t[][4],int*e,int *x){
    int first,second,i;

    first=e[0]+a[0][0];
    second=e[1]+a[1][0];

    for(int i=1;i<4;i++){
        int up=min(first+a[0][i],second+a[0][i]+t[1][i]);
        int down=min(second+a[1][i],first+a[1][i]+t[0][i]);

        first=up;
        second=down;
    }
    return min(first+x[0],second+x[1]);

}

int main(){
    // int size;
    // std::cout<<"Enter the size of the assembly line: ";
    // std::cin>>size;
    // int** a=new int*[2];
    // int** t=new int*[2];
    // for(int i=0;i<size;i++){
    //     a[i]=new int[size];
    //     t[i]=new int[size];
    // }

    int a[][4] = { { 4, 5, 3, 2 },
                   { 2, 10, 1, 4 } };
    int t[][4] = { { 0, 7, 4, 5 },
                   { 0, 9, 2, 8 } };
    int e[] = { 10, 12 }, x[] = { 18, 7 };
    std::cout<<carAssembly(a,t,e,x);
    

    return 0;
}