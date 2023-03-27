#include<bits/stdc++.h>
using namespace std;


int max(int a,int b){
    return a>b?a:b;
}


int crosssum(int a[],int l,int mid,int h){
    int s=0;
    int left=INT_MIN;
    for(int i=mid;i>=l;i--){
        s+=a[i];
        if(s>left){
            left=s;
        }
    }
    int u=0;
    int right=INT_MIN;
    
    for(int i=mid+1;i<=h;i++){
        u+=a[i];
        if(u>right){
            right=u;
        }   
    }
    return left+right;
}

int maxsum(int a[],int l,int h){
    if(l==h){
        return a[l];
    }
    int mid=(l+h)/2;
    int temp=max(maxsum(a,l,mid),maxsum(a,mid+1,h));
    return max(temp,crosssum(a,l,mid,h));
}

int main()
{
    std:cout<<"Enter array length: ";
    int len;
    std::cin>>len;
    int arr[100];
    
    for(int i=0;i<len;i++){
        std::cout<<"Enter element "<<i+1<<": ";
        std::cin>>arr[i];
    }
	cout<<"maximum subarray sum is: "<<maxsum(arr,0,len);
}