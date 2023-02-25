#include <iostream>
#include<map>

using namespace std;

map<char,int> mp;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t,m,n,k,i,j,tmp,b,Min;
    bool x[200005];
    char a;
    cin>>t;
    while(t--){
        b=1;
        Min=900000005;
        mp.clear();
        cin>>m>>n>>k;
        for(i=1;i<=k;i++)x[i]=0;
        x[0]=1;
        for(i=0;i<k;i++){
            cin>>a;
            mp[a]++;
        }
        for(auto it:mp){
        	auto c=it.first;
			auto i=it.second;
            for(j=k;j>=i;j--){
                if(x[j-i]){
                    x[j] |= x[j-i];
                }
            }
        }
		//for(int i=0;i<=k;i++) cout<<i<<" "<<x[i]<<endl;
        for(i=n;i<=k;i++){
        	cout<<i<<" "<<x[i]<<" "<<i+m<<endl;
            if(x[i] && i+m<=k){
                b=0;
                cout<<'0'<<endl;
                break;
            }
        }
        if(b==0)continue;
        for(auto it:mp){
        	auto c=it.first;
			auto e=it.second;
            for(i=1;i<=k-e;i++)x[i]=0;
            x[0]=1;
            for(auto it1:mp){
            	auto c1=it1.first;
				auto e1=it1.second;
                if(c==c1)continue;
                for(i=k-e;i>=e1;i--){
                    if(x[i-e1]){
                        x[i] |= x[i-e1];
                    }
                }
            }
            
            for(i=n-1;i>=0 && m>k-i-e;i--){
                if(x[i]){
                    Min=min(Min,(n-i)*(m-(k-i-e)));
                }
            }
        }
        cout<<Min<<endl;
    }
    return 0;
}

