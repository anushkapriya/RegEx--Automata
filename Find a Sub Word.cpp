#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

bool chK(char ch)
{
    if(ch>='a' && ch<='z' )
        return true;
    if(ch>='A' && ch<='Z')
        return true;
    if(ch>='0' && ch<='9')
        return true;
    if(ch=='_')
        return true;
   return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int i,j,num,test;
    string str,in;
    vector<string> list;
    
    cin>>num;
    getchar();
    
    while(num--)
    {
        getline(cin,in);
        
        //making the list of all the word given
        list.push_back(in);
    }
    
    cin>>test;
    
    for(int t=1;t<=test;t++)
    {
        cin>>str;
        int cnt=0;
        for(i=0;i<list.size();i++)
        {
            int p=0;
            bool prec=false;
            char ch;
            for(j=0;j<list[i].size();j++)
            {
                if(p==str.size())
                {
                    if(chK(list[i].at(j)) && prec==true)
                    {
                        cnt++;
                        //cout<<ch<<str<<list[i].at(j)<<endl;
                    }
                    p=0;
                    prec=false;
                }
                
                if(list[i].at(j)==str.at(p))
                {
                    if(p==0 && j>=1 && chK(list[i].at(j-1)))
                    {
                        prec=true;
                        ch=list[i].at(j-1);
                    }
                    if(prec==true)
                        p++;
                    else
                        p=0;
                }
                else
                {
                    if(p>=1)
                        j--;
                    p=0;
                    prec=false;
                    
                }
            }
        }
        
        cout<<cnt<<endl;
    }
    
    return 0;
}
