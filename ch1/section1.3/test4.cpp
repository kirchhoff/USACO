#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(int argc, char *argv[])
{
    char hash[1000];
    string input;
    freopen("in.txt","r",stdin);
M:   while(cin>>input){
        memset(hash,0,1000);
        int len=input.size();//;;strlen(input);
        int i=0;
        while(i<len)
        {
            if((input[i]<='9'&&input[i]>='0') ||( input[i]<='z'&&input[i]>='a') )
                hash[input[i]]++;
            else
            {
                cout<<"<invalid input string>"<<endl;
                goto M;
            }
            i++;
        }
        int ok=0;
        while(1){
            ok=0;
            for(i=0;i<1000;++i)
            {
                if(hash[i]!=0)
                {
                    printf("%c",i);
                    hash[i]--;
                    ok=1;
                }
            }
            if(ok==0)
            {
                cout<<endl;
                break;
            }
        }
    }

    return 0;
}
