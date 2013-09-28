/*
  ID:twd30651
  PROG:transform
  LANG:C++
*/
#include <iostream>
#include <fstream>
//#define DEBUG
using namespace std;
int N;
char tmp[10][10];
char a[10][10];
char b[10][10];
bool equal()
{
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               if(tmp[i][j]!=b[i][j])return false;
          }
     return true;
}
int no1()
{
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[j][N-i-1]=a[i][j];
          }
     return 1;
}
int no2()
{
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[N-i-1][N-j-1]=a[i][j];
          }
     return 1;
}
int no3()
{
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[N-j-1][i]=a[i][j] ;
          }
     return 1;
}
int no4()
{
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[i][N-j-1]=a[i][j];
          }
     return 1;
}
int no51()
{
     char *s[10];
     for(int i=0;i<N;++i)
          s[i]=new char [N];
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               s[i][N-j-1]=a[i][j];
          }
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[j][N-i-1]=s[i][j];
          }
     for(int i=0;i<N;++i)
          free(s[i]);
     return 1;
}
int no52()
{
      char *s[10];
     for(int i=0;i<N;++i)
          s[i]=new char [N];
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               s[i][N-j-1]=a[i][j];
          }
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[N-i-1][N-j-1]=s[i][j];
          }
     for(int i=0;i<N;++i)
          free(s[i]);
     return 1;
}
int no53()
{
     char *s[10];
     for(int i=0;i<N;++i)
          s[i]=new char [N];
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               s[i][N-j-1]=a[i][j];
          }
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               tmp[N-j-1][i]=s[i][j] ;
          }
     for(int i=0;i<N;++i)
          free(s[i]);
     return 1;
}
void show()
{
     cout<<"tmp is "<<endl;
     for(int i=0;i<N;++i){
          for(int j=0;j<N;++j)
          {
               printf("%c",tmp[i][j]);
          }
          cout<<endl;
     }
     cout<<"b is "<<endl;
     for(int i=0;i<N;++i){
          for(int j=0;j<N;++j)
          {
               printf("%c",b[i][j]);
          }
          cout<<endl;
     }
}
int main(int argc, char *argv[])
{
     freopen("transform.in","r",stdin);
     freopen("transform.out","w",stdout);
     cin>>N;
     for(int i=0;i<N;++i){
          string x;
          cin>>x;
          for(int j=0;j<N;++j)
          {
               a[i][j]=x[j];
          }
     }
     for(int i=0;i<N;++i){
          string x;
          cin>>x;
          for(int j=0;j<N;++j)
          {
               b[i][j]=x[j];
          }
     }
     if(no1()&&equal())
     {
          cout<<"1"<<endl;
          return 0;
     }
     if(no2()&&equal())
     {
          cout<<"2"<<endl;
          return 0;
     }
     if(no3()&&equal())
     {
          cout<<"3"<<endl;
          return 0;
     }
     if(no4()&&equal())
     {
          cout<<"4"<<endl;
          return 0;
     }
     if(no51()&&equal())
     {
          cout<<"5"<<endl;
          return 0;
     }
     if(no52()&&equal())
     {
          cout<<"5"<<endl;
          return 0;
     }
     if(no53()&&equal())
     {
          cout<<"5"<<endl;
          return 0;
     }
     bool flag=true;
     for(int i=0;i<N;++i)
          for(int j=0;j<N;++j)
          {
               if(a[i][j]!=b[i][j])flag=false;
          }
     if(flag)
     {
          cout<<"6"<<endl;
          return 0;
     }
     cout<<"7"<<endl;
     return 0;
}
