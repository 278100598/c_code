//2022.3.9 by ljz
//email 573902690@qq.com
//if you find any bug in my code
//please tell me
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define ull unsigned long long int
#define res int
using namespace std;
const int N=1e5+10;
const int LJC=2333;
char s[N],str[N];
int n;
ull pre[N],suf[N],pw[N];

vector<string> duval(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}

int main() {
	
	string ss;
	while(cin>>ss) {
		auto it = duval(ss);
		for(auto i:it) {
			cout<<i<<endl;
		}
		cout<<endl;
	}
	
    scanf("%s",str+1),pw[0]=1;
    n=int(strlen(str+1));
    for(res i=1;i<=n;i++)pre[i]=pre[i-1]*LJC+str[i],s[i]=str[i],pw[i]=pw[i-1]*LJC;
    
    for(res i=1;i<=n;i++) {
    	cout<<i<<" "<<pre[i]<<endl;
	}
    sort(s+1,s+n+1);
    suf[n+1]=0;
    for(res i=n;i;i--)suf[i]=suf[i+1]*LJC+str[i];
    for(res T=0;T<n;T++){
        if(s[T+1]!=str[T+1]){
            res id=T+1;
            for(res i=T+2;i<=n;i++){
                res l=0,r=n-T,ret=0;
                while(l<=r){
                    res mid=(l+r)>>1;
                    ull A=0,B=0;
                    if(mid<=id-T)A=suf[id-mid+1]-suf[id+1]*pw[mid],B=suf[i-mid+1]-suf[i+1]*pw[mid];
                    else {
                        A=(suf[T+1]-suf[id+1]*pw[id-T])*pw[mid-id+T]+pre[T+mid]-pre[id]*pw[T+mid-id];
                        if(mid<=i-T)B=suf[i-mid+1]-suf[i+1]*pw[mid];
                        else B=(suf[T+1]-suf[i+1]*pw[i-T])*pw[mid-i+T]+pre[T+mid]-pre[i]*pw[T+mid-i];
                    }
                    if(A==B)l=mid+1,ret=mid;
                    else r=mid-1;
                }
                char a=0,b=0;
                if(id-ret>=T+1)a=str[id-ret];
                else a=str[T+ret+1];
                if(i-ret>=T+1)b=str[i-ret];
                else b=str[T+ret+1];
                if(a<b);
                else id=i;
            }
            for(res i=1;i<=T;i++)printf("%c",str[i]);
            for(res i=id;i>=T+1;i--)printf("%c",str[i]);
            for(res i=id+1;i<=n;i++)printf("%c",str[i]);
            puts("");
            return 0;
        }
    }
    printf("%s\n",str+1);
}
