#include <iostream>
using namespace std;
long long n,m1=1000000007,a[10000001],ans;
int main()
{
	a[1]=1,a[2]=2;
	for(int i=3;i<10000001;i++)
	{
		if(i%2)
		{
			a[i]=a[i-1];
			continue;
		}
		a[i]=(a[i-2]+a[i/2])%m1;
	}
	while(cin>>n)
		cout<<a[n]<<endl;
	return 0;
}
/*
#if 0
这是一个暴力，通过这个程序找到递增规律a[i]=(a[i-2]+a[i/2]);
#include <iostream>
#include <cstdio>
using namespace std;
long long n,t,a[28],b[28],c[28],sum,ans,f1;
long long m1=1000000007;
void check(int f,long long sum)
{
	if(sum==n)
	{
		ans=(ans+1)%m1;
		return;
	}
	if(f<0) return;
	for(int i=0;i<=b[f];i++)
	{
		if(sum+i*a[f]>n)
			return;
		sum+=i*a[f];
		check(f-1,sum);
		sum-=i*a[f];
	}
}
int main()
{
	a[0]=1;
	for(int i=1;i<=27;i++)
		a[i]=2*a[i-1];		//找到所有幂
	while(cin>>n)
	{
		if(n%2) n--;
		b[0]=n;
		t=n;
		ans=0;//初始化ans
		f1=0;//标记最大的2次幂
		for(int i=27;i>0;i--)
		{
			b[i]=0;
			if(t>=a[i])
			{
				if(f1==0) f1=i;
				b[i]=t/a[i];
			}
		}
		check(f1,0);
		if(n!=0&&ans==0)
			ans=1;
		cout<<ans<<endl;
	}	
	return 0;
}





#endif
#include <iostream>
#include <cstdio>
using namespace std;
long long n,t,a[28],b[28],c[28],sum,ans,f1;
long long m1=1000000007;
void check(int f,long long sum)
{
	if(sum==n)
	{
		ans=(ans+1)%m1;
		return;
	}
	if(f<0) return;
	for(int i=0;i<=b[f];i++)
	{
		if(sum+i*a[f]>n)
			return;
		sum+=i*a[f];
		check(f-1,sum);
		sum-=i*a[f];
	}
}
int main()
{
	a[0]=1;
	for(int i=1;i<=27;i++)
		a[i]=2*a[i-1];		//找到所有幂
	while(cin>>n)
	{
		if(n%2) n--;
		b[0]=n;
		t=n;
		ans=0;//初始化ans
		f1=0;//标记最大的2次幂
		for(int i=27;i>0;i--)
		{
			b[i]=0;
			if(t>=a[i])
			{
				if(f1==0) f1=i;
				b[i]=t/a[i];
			}
		}
		check(f1,0);
		if(n!=0&&ans==0)
			ans=1;
		cout<<ans<<endl;
	}	
	return 0;
}

#endif
*/