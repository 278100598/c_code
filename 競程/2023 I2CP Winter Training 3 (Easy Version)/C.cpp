#include<iostream>
#include<iomanip>
#include<map>
using namespace std;
int T;
string s;
map<string,int> m;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	getline(cin,s);
	T = stoi(s);
	while(T--) {
		int sum=0;
		m.clear();
		getline(cin,s);
		while(cin.peek()!='\n' && cin.peek()!=EOF) {
			getline(cin,s);
			m[s]++;
			sum++;
		}
		
		for(auto it:m) {
			cout<<it.first<<' ';
			double x=(it.second*100)/(double)sum;
			//cout<<fixed<<setprecision(4)<<x<<'\n';
			printf("%.4lf\n",x);
		}
		if(T!=0) cout<<"\n";
	}
	
	return 0;
}
