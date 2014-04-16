#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string.h>
#define N 1000
using namespace std;

char** PermutNN;
int Pcount;
int arrsize;

void Permutation(char* pStr, char* pBegin);

void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;

    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
    {
       // printf("%s\n", pStr);
        char* stemp = new char[arrsize+1];

        strcpy(stemp,pStr);
        *PermutNN = stemp;
        PermutNN++;
         Pcount ++;

    }
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++ pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin + 1);


            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

        }
    }
}


int main(int argc, char *argv[])
{
    Pcount  = 0;

    int t;//(1 ≤ t ≤ 10000)
    cin>>t;
    int* numarr = new int[t];

    for(int i = 0;i<t;i++){
        cin>>numarr[i];
    }
     cout<<endl;
    arrsize = numarr[0]+numarr[1];
    char* strarr = new char[arrsize];

    for(int i = 0;i<numarr[0];i++)
        strarr[i] = '0';
    for(int i = numarr[0];i<(numarr[0]+numarr[1]);i++)
        strarr[i] = '1';



    cout<<strarr;

    cout<<endl<<"-----"<<endl;

   // char pStr[] = "";
    Permutation(strarr);

    if(numarr[2]<=Pcount){
        cout<<PermutNN[numarr[2]];

    }else{
        cout<<"Impossible"<<endl;
    }




    return 0;
}
/*#include <iostream>
using namespace std;
int main()
{
    int a[12]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800};
    int d[12];
    int m;
    cin>>m;
    while(m--)
    {
        int b[4]={0,0,0,1};
        long long n;
        cin>>n;
        n--;
        for(int j=0;j<4;j++)
        {
            int count =n/a[4-j];
            d[j]=b[count];
            for(int i=count;i<4;i++)
            {
                b[i]=b[i+1];
            }
            n-=count*a[4-j];
        }
        for(int i=0;i<4;i++)
            cout<<(d[i]);
        cout<<endl;
    }
    }*/
