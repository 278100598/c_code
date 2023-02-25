#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a,b,c,d,e,f,x=0,y=0,z=0,aa[1000],j=1; 
	while(cin>>a>>b>>c>>d>>e>>f)
	{
		for(long long int i=-35;i<=35;i++)
		{
			x=y;
			y=a*i*i*i*i*i+b*i*i*i*i+c*i*i*i+d*i*i+e*i+f;
			if((x<0&&y>0)||(x>0&&y<0))
			{
				aa[2*j-1]=i-1;
				aa[2*j]=i;
				z++;
				j++;
			}
			else if(y==0)
			{
				aa[2*j-1]=i;
				aa[2*j]=i;
				z++;
				j++;
			}
		}
		if(z==0)
		{
			cout<<"N0THING! >\\\\\\<"; 
		}
		else if(z>6)
		{
			cout<<"Too many... = ="<<'"';
		}
		else
		{
			for(int i=1;i<=z;i++)
			{
				cout<<aa[2*i-1]<<" "<<aa[2*i]<<"\n";
			}
		}
	}
	return 0;
}
