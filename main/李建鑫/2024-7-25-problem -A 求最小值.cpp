#include<iostream>
using namespace std;
int n,x,t,y=1;
int main()
{
	cin>>n>>x;
	for(int i=2;i<=n;i++)
	{
		cin>>t;
		if(x>t)
		{
			x=t;
			y=i;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}