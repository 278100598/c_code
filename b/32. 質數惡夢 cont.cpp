#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cc=1;
	unsigned long long int a,b[13]={2,3,5,7,11,13,61,325,9375,28178,450775,9780504,1795265022};
	while(cin>>a)
	{
		int count=-1;
		for(int i=0;i<13;i++)
		{
			if(a==0||a==1)
			{
				cout<<"F"<<endl;
				break;
			}
			unsigned long long int power=b[i],sum=1,x=a-1;
			while(x!=0)
			{
				__uint128_t pp,ss,aa;
				aa=a;
				bool yy=false;
				if(x%2==1)
				{
					pp=power;
					ss=sum;
					ss=(pp*ss)%aa;
					power=pp;
					sum=ss;
					yy=true;
				}
				x/=2;
				pp=power;
				pp=(pp*pp)%aa;
				power=pp;
				if((sum==1||sum==a-1)&&yy)
				{
					count++;
					break;
				}
			}
			if(count==12||a==b[i])
			{
				cout<<"T"<<endl;
				break;
			}
			if(count!=i)
			{
				cout<<"F"<<endl;
				break;
			}
		}

		cc++;
	}
	return 0;
}
