/*
  ID:twd30651
  PROG:calfflac
  LANG:C++
*/
#include <iostream>
#include <fstream>
#include <string>
char *c2=new char[22000];
int tt[22000];
using namespace std;
void manacher(char *cc,int s_size)
{
    char *ss=new char[s_size*2+3];
    int size=s_size*2+3;
    ss[0]='$';
    ss[1]='`';
    int k=2;
    for(int i=0;i<s_size;++i)
    {
         ss[k++]=cc[i];
         ss[k++]='`';
    }
    ss[k]='\0';
    int *p=new int[size];
    int id=1;
    int mx=1;
    p[1]=1;
    p[0]=1;
    for(int i=2;i<size;++i)
    {
         if(mx-i>0)p[i]=min(p[2*id-i],mx-i); 
         else
              p[i]=1;
         while(ss[i+p[i]] == ss[i-p[i]])++p[i];
         if(p[i]+i>mx){
              mx=p[i]+i;
              id=i;
         }
    }
    int max=0;
    int index=0;
    for(int i=2;i<size;++i)
    {
         if(p[i]>max)
         {
              max=p[i];
              index=i;
         }
    }
    cout<<max-1<<endl;
  /*    for(int j=index-max+1;j<index+max;++j)
    {
        cout<<ss[j];
    }
    for(int j=index-max+2;j<index+max;j+=2)
    {
        cout<<cc[j/2-1];
    }*/
    for(int i=tt[(index-max+2)/2-1];i<=tt[(index+max-2)/2-1];++i)
    {
        cout<<c2[i];
    }
    cout<<endl;
}
int main(int argc, char *argv[])
{
     freopen("calfflac.in","r",stdin);
     freopen("calfflac.out","w",stdout);
     string origin;
     string s;
     char c;
     char *cc=new char[22000];
     int i=0;
     int j=0;
     while((c=getchar())!=EOF)
     {
         c2[j++]=c;
         origin+=c;
         if(isalpha(c))
         {
             tt[i]=j-1;
             cc[i++]=tolower(c);
         }
     }
     cc[i]='\0';
     c2[j]='\0';
     manacher(cc,i);
     
     return 0;
}
/*
 * Compiling...
 * Compile: OK
 *
 * Executing...
 *    Test 1: TEST OK [0.011 secs, 3612 KB]
 *       Test 2: TEST OK [0.011 secs, 3612 KB]
 *          Test 3: TEST OK [0.011 secs, 3612 KB]
 *             Test 4: TEST OK [0.011 secs, 3612 KB]
 *                Test 5: TEST OK [0.011 secs, 3612 KB]
 *                   Test 6: TEST OK [0.011 secs, 3612 KB]
 *                      Test 7: TEST OK [0.011 secs, 3612 KB]
 *                         Test 8: TEST OK [0.011 secs, 3764 KB]
 *
 *                         All tests OK.
 *
 */
