#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
/*1.1 Implement an algorithm to determine if a string has all unique characters. 
      What if you can not use additional data structures
*/

bool isUnique1(string s)
{
    bool characters[256];
    memset(characters, 0, sizeof(characters));
    for(int i=0;i<s.length();i++)
    {
        int temp=(int)s[i];
        if(characters[temp]==1){
            return false;
        }else{
            characters[temp]=1;
        }
       
    }
     return true;
}

bool isUnique2(string s){
    int characters[8];
    memset(characters, 0, sizeof(characters));
    for(int i=0;i<s.length();i++)
    {
        int temp=(int)s[i];
        int index=temp/32;
        int shift=temp%32;
        if((characters[index] &1<<shift)==1)
        {
            return false;
        }else{
            characters[index]|=1<<shift;
        }
    }
    return true;
    
}

int main()
{
   bool check = isUnique2("fol win g"); 
   if(check){
       cout<<"string is unique";
   }
   else{
       cout<<"string is not unique";
   }
   
   return 0;
}


