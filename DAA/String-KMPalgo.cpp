#include <bits/stdc++.h> 
using namespace std;
void calcLPS(string p,int LPS[]){
    LPS[0] = 0;                   
    int i = 0,j=1;
    while (j<p.length()){
        if(p[i]==p[j])
		{   
            LPS[j] = i+1;
            i++; j++;
        }
        else{                   
            if(i==0){         
                LPS[j] = 0;
                j++;
            }
            else{              
                i = LPS[i-1];
            }
        }
    }
}

int main()
{
    string s = "aaebcaaeaaebcaadaa"; //"ababcdabcb";
    string p = "aaebcaadaa"; //"abc";
    int slen = s.length();
    int plen = p.length();
    int LPS[plen];
    calcLPS(p,LPS); // to build the LPS table
    int i=0,j=0;
    while(i<slen){
        if(p[j]==s[i]){i++;j++;} // If there is a match, proceed to check the remaining characters
        if (j == plen) { 
            cout<<i - plen <<' ';  // to print the index of the string where the pattern matches                                  
            j = LPS[j - 1]; 
        } 
        else if (i < slen && p[j] != s[i]) {  
            if (j == 0)         
                i++;
            else
                j = LPS[j - 1];  //if there is a mismatch after a few matched characters,
        }                        // proceed to check only from the LPS of the previously 
    }                            // matched character
}