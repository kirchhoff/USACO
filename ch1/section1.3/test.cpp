#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int last;
int x[100];
int y[100];
int m,n;
int sum=0;
struct point{
	int v;
	int x;
	int y;
};
vector<point> all;
vector<point> np;
bool h(const point &a,const point &b){
	return a.v>b.v;
}
bool l(const point &a,const point &b){
	return a.v<b.v;
}
void delp(int a,int b,int v){
	if(x[a]>1&&y[b]>1){
		x[a]--;
		y[b]--;
	}else
        sum += v;
}
void addp(int a,int b){
	if(x[a] == 0)last--;
	if(y[b] == 0)last--;
	x[a]++;
	y[b]++;
}
int main(){
    //freopen("data.txt", "r", stdin);
	int i,j,T,t = 1;
	int s;
	cin>>T;
	point p;
    int tt=0;
	while(tt<T){
        tt++;
		cin>>m>>n;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cin>>p.v;
				p.x = i;
				p.y = j;
				all.push_back(p);
				x[i] = 0;
				y[j] = 0;
			}
		}
		sort(all.begin(),all.end(),l);
		last = n + m;
		i = 0;
		while(last > 0){
			addp(all[i].x,all[i].y);
			np.push_back(all[i++]);
		}
		sum = 0;
		sort(np.begin(),np.end(),h);
		for( i =0; i<np.size();i++)
			delp(np[i].x,np[i].y,np[i].v);
		all.clear();
		np.clear();
		printf("Case %d: ",t++);
		cout<<sum<<endl;
	}

	return 0;
}
