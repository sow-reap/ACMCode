#include<iostream>
using namespace std;
const int M=2000005;
int a[M],n,m;
int first[M],next[M],to[M],tot=0;
void add(int x,int y)
{
	tot++;
//	next[tot]=first[x];
	if(first[x]) 
		next[first[x]]=tot;
	else
		first[x]=tot;
	to[tot]=y;
}
int check(int x,int y)
{
	if(y==0) return x;
	int t=first[x];
	if(t!=0) 
		check(to[t],y-1);
	while(y)
	{
		check(next[t],y-1);
	}
}
int main()
{
//	for(int i=1;i<=n;i++)
//		add(i,i);
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		int t;
		cin>>t;
		add(t,i);
	}
	for(int i=2;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(y==1)
		{
			cout<<x<<endl;
			continue;
		}
		else y--;
		cout<<check(x,y);
	}
	return 0;
}