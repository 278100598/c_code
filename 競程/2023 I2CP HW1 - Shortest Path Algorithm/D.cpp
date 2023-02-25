#include<iostream>
#include<map>
using namespace std;
int N,M,turn=1;
double w[300][300];
map<string,int> name;

int main() {
	while(cin>>N) {
		if(N==0) break;
		name.clear();
		for(int i=0;i<N;i++) {
			string s;
			cin>>s;
			name[s]=i;
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) w[i][j]=-1;
			w[i][i]=1;
		}
		
		cin>>M;
		for(int i=0;i<M;i++) {
			string a,b;
			double c;
			cin>>a>>c>>b;
			w[name[a]][name[b]]=c;
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				for(int k=0;k<N;k++) {
					if(w[j][i]!=-1 && w[i][k]!=-1) w[j][k] = max(w[j][k],w[j][i]*w[i][k]);
				}
			}
		}
		
		bool flag=false;
		for(int i=0;i<N;i++) {
			if(w[i][i]>1) flag=true;
		}
		
		if(flag) printf("Case %d: Yes\n",turn++);
		else printf("Case %d: No\n",turn++);
	}
	
	return 0;
}
