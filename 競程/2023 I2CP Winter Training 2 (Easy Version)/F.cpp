#include<iostream>
#include<vector>
#include<map>
using namespace std;
int A,B;
map<int,int> m;
vector<int> fp;

int main() {
	while(cin>>A>>B) {
		m.clear();
		fp.clear();
		
		int x=A%B,y=B,end;
		for(int i=0;;i++) {
			x*=10;
			//cout<<x<<' '<<x%y<<' '<<i<<'\n';
			if(m.find(x) == m.end()) m[x]=i;
			else {
				end = m[x];
				break;
			}
			fp.push_back(x/y);
			x%=y;
		}
		
		//cout<<end<<' '<<fp.size()<<'\n';
		cout<<A<<'/'<<B<<" = "<<A/B<<'.';
		for(int i=0;i<end;i++) cout<<fp[i];
		cout<<'(';
		for(int i=end;i<fp.size() && i<50;i++) cout<<fp[i];
		if(fp.size()>50) cout<<"...";
		cout<<")\n";
		
		cout<<"   "<<fp.size()-end<<" = number of digits in repeating cycle\n"<<'\n';
	}
	
	
	return 0;
}
