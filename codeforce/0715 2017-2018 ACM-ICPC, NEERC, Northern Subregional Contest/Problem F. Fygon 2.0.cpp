#include<iostream>
#include<bitset>
#include<unordered_map> 
#include <algorithm>
using namespace std;
unordered_map<bitset<27>,long long int> d; 
bitset<27> x[27];

int change(char c) {
	if(c=='1') return 0;
	return c-'a'+1;
}

long long int gcd(long long int a,long long int b){
	if(b==0) return a;
	if(b>a) return (b,a);
	return gcd(b,a%b);
}

long long int go(bitset<27> y) {
	if(d[y]!=0) return d[y];
	if(y.count()==0) return 1;
	long long int sum=0;
	for(int i=0;i<27;i++) {
		if((x[i] & y) == (1<<i)) {
			y[i]=false;
			sum+=go(y);
			y[i]=true;
		}
	}
	d[y]=sum;
	return sum;
}

void add(char a,char b) {
	x[change(a)][change(b)]=true;
	x[change(a)][change(a)]=true;
	x[change(b)][change(b)]=true;
	for(int i=0;i<27;i++) {
		if(x[i][change(a)]) x[i] |= x[change(b)];
		if(x[change(b)][i]) x[change(a)] |= x[i];
	}
}

int main() {
	freopen("fygon20.in","r",stdin);    // Åª file.in ÀÉ
	freopen("fygon20.out","w",stdout);  // ¼g¤J file.out ÀÉ
	int m;
	cin>>m;
	string s;
	getline(cin,s);
	add('1','n');
	for(int i=1;i<m;i++) {
		getline(cin,s);
		char a=s[s.find("in")-2],b=s[s.find(",")-1],c=s[s.find(")")-1];
		add(b,a);
		add(a,c);
	}
	
	
	bitset<27> y=(1<<27)-1;
	for(int i=0;i<27;i++) {
		if(x[i].count()==0) y[i]=false;
		for(int j=i+1;j<27;j++) {
			if(x[i] == x[j]) y[j]=false;
		}
	}
	
	
	/*cout<<"  zyxwvutsrqponmlkjihgfedcba1"<<endl;
	for(int i=0;i<27;i++) {
		cout<<char(i+'a'-1)<<" "<<x[i]<<endl;
	}*/
	int k=y.count()-2;
	d.rehash(1 << k);
	long long int power=1,out=go(y);
	for(int i=1;i<=k;i++) power*=i;
	long long int g=gcd(power,out);
	
	cout<<k<<" "<<out/g<<"/"<<power/g<<endl;
	
	return 0;
}

