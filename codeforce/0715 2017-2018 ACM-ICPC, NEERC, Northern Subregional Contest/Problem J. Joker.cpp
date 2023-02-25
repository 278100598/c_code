#include<iostream>
#include<iomanip>
using namespace std;
int *card;
int main() {
	freopen("joker.in","r",stdin);    // Åª file.in ÀÉ
	freopen("joker.out","w",stdout);  // ¼g¤J file.out ÀÉ
	int n,m;
	long long int P=0,N=0,po=0,na=0,index=0,mx=-1;
	cin>>n>>m;
	card = new int[n+1];
	for(int i=1;i<=n;i++) cin>>card[i];
	for(int i=1;i<=n;i++) {
		if(card[i]>0) P+=card[i];
		else N-=card[i];
	}
	for(int i=1;i<=n;i++) {
		if(card[i]>0)po+=card[i];
		else na+=card[i];
		long long int x=(po*N+na*P);
		if(x>mx) {
			mx=x;
			index=i;
		}
	}
	cout<<index<<endl;
	for(int t=0;t<m;t++) {
		int a,b;
		cin>>a>>b;
		if(card[a]>0) P-=card[a];
		else N+=card[a];
		if(b>0) P+=b;
		else N-=b;
		card[a]=b;
		mx=-1;
		na=0;
		po=0;
		for(int i=1;i<=n;i++) {
			if(card[i]>0)po+=card[i];
			else na+=card[i];
			long long int x=(po*N+na*P);
			//cout<<po<<" "<<na<<" "<<P<<" "<<N<<" "<<x<<endl;
			if(x>mx) {
				mx=x;
				index=i;
			}
		}
		cout<<index<<endl;
	}
}
