#include<iostream>
#include<limits.h>

int findMaxIndex(float* pwratio,int last){
    float maxnum=INT_MIN;
    int maxIndex;
    for(int i=0;i<last;i++){
        if(pwratio[i]>maxnum){
            maxIndex=i;
            maxnum=pwratio[i];
        }
    }
    return maxIndex; 
}

void selectionSort(float* pwratio,int* profits,int* weights,int size){
    int maxIndex;
    int last;
    for(int i=0;i<size;i++){
        last=size-i-1;
        maxIndex=findMaxIndex(pwratio,last+1);
        float temp=pwratio[maxIndex];
        pwratio[maxIndex]=pwratio[last];
        pwratio[last]=temp;
        // std::cout<<pwratio[last];
        
        temp=profits[maxIndex];
        profits[maxIndex]=profits[last];
        profits[last]=temp;

        temp=weights[maxIndex];
        weights[maxIndex]=weights[last];
        weights[last]=temp;
    }
}

int main(){
    std::cout<<"Enter the size of your arrays: ";
    int size;
    std::cin>>size;
    std::cout<<"Enter the max weight: ";
    int weight;
    std::cin>>weight;
    int* profits=new int[size];
    int* weights=new int[size];
    float* pwratio=new float[size];
    for(int i=0;i<size;i++){
        std::cout<<"Enter the profits and weights for object "<<(i+1)<<" ";
        std::cin>>profits[i]>>weights[i];
        pwratio[i]=(float)profits[i]/(float)weights[i]; 
    }
    
    selectionSort(pwratio,profits,weights,size);
    std::cout<<"Weight   Profit   pwratio"<<std::endl;
    for(int i=0;i<size;i++){
        std::cout<<weights[i]<<"        "<<profits[i]<<"        "<<pwratio[i]<<std::endl;
    }
    int tmpweight=0;
    float profit=0;
    int j;
    for(int i=size-1;i>=0;i--){
        tmpweight+=weights[i];
        if(tmpweight<weight){
            profit+=profits[i];
            std::cout<<profit<<" ";
        }
        else{
            j=i;
            break;}
    }
    profit+=pwratio[j]*(weights[j]-(tmpweight-weight));
    std::cout<<profit;
    return 0;

}