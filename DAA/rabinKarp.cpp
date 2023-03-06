#include<bits/stdc++.h> 

#define prime 13

using namespace std; 

// function to find the pattern in effective way/

int main() 

{

    string s="ABCCDDAEFGCDDF"; //    "ABAAABCDBBABCDDEBCABC";

    string p=  "CDD"; //ABC

    int plen = p.length();

    int slen = s.length();

    int ph=0,sh=0,h=1,maxchar=10;

	// we assume that the string and the pattern will contain only 10 different 

	//characters from A to J

    for(int i=0;i<plen-1;i++)

      h=(h*maxchar)%prime;  // to calculate pow(maxchar,plen-1)%prime

    for(int i=0;i<plen;i++)

    {

      ph=(ph*maxchar+p[i]-65+1)%prime;//to calculate hash value of the pattern

      sh=(sh*maxchar+s[i]-65+1)%prime;//to calculate hash value of the first window

    } 

    cout<<"hash value of the pattern"<<p<<" is "<<ph<<endl;

    cout<<"hash value of the window "<<s.substr(0,plen)<<" is "<<sh<<endl;

    for(int i=0;i<=slen-plen;i++)

    {       

      if(ph==sh) /only if the pattern's hash value & window's hash value match, we check the actual characters/

      {

        int flag=0,count=0;

        for(int j=0;j<plen;j++)

        { 

        if(s[i+j]==p[j])

        {

		  flag=1;

          count++;

        }

        else

          break;

        }

        if(count==plen)

        {

            cout<<"Pattern occurs at index: "<<i<<endl;

            //continue;

        }

      }

      //int nextchar=i+1;

      if(i<slen-plen) //if the string contains more characters to be compared

      {

        sh=((sh-(s[i]-65+1)*h)*maxchar+(s[i+plen]-65+1))%prime;

        while(sh<0)

          sh+=prime;

        cout<<"hash value of the window"<<s.substr(i+1,plen)<<" is "<<sh<<endl;

      }

    }//end of for

    return 0;

}