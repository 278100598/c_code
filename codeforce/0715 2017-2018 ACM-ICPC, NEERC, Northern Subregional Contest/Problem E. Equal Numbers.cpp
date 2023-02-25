#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int m[1000001];
int main() {
	freopen("equal.in","r",stdin);    // Åª file.in ÀÉ
	freopen("equal.out","w",stdout);  // ¼g¤J file.out ÀÉ
	int n;
	for(int i=0;i<=1000000;i++) m[i]=0;
	cin>>n;
	for(int i=0;i<n;i++) {
		int a;
		cin>>a;
		m[a]++;
	}
	vector<int> v1,v2;
	for(int i=1;i<=1000000;i++) {
		if(m[i]!=0) {
			for(int j=i*2;j<=1000000;j+=i) {
				if(m[j]!=0) {
					v1.push_back(m[i]);
					break;
				}
			}
			v2.push_back(m[i]);
		}
	}
	if(!v1.empty())sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int t1=v2.size(),t2=v2.size()+1,i1=0,i2=0;
	for(int i=0;i<=n;i++) {
		cout<<min(t1,t2)<<" ";
		if(i1<v1.size()) v1[i1]--;
		if(i2<v2.size()) v2[i2]--;
		if(i1<v1.size()&&v1[i1]==0) {
			t1--;
			i1++;
		}
		if(i2<v2.size()&&v2[i2]==0) {
			t2--;
			i2++;
		}
	}
	return 0;
}

