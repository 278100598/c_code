#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pii;
#define REP(i,n) for(ll i=0;i<n;i++)

#ifdef DEBUG
#define dbg(x) x
#define dbgp(x) cerr << x << endl;
#else
#define dbg(x) //x
#define dbgp(x) //cerr << x << endl;
#endif

#define MOD 100007
#define MAX_N 100002
#define MAX_DIM 7

ll aTree[MAX_N*3];
ll bTree[MAX_N*3];
ll tt=0;


void muti(ll **a,ll **b,int size) {
	ll x[size][size];
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			ll t=0;
			for(int k=0;k<size;k++) {
				ll aa=a[i][k],bb=b[k][j];
				t+=(aa*bb);
			}
			t%=MOD;
			x[i][j]=t;
		}
	}
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) a[i][j]=x[i][j];
	}
}
int f(long long int a,long long int b) {
	b%=7;
	if(a<=b) return 1;
	if(b==0) return 0;
	if(b==1) return 1;
	
	ll **e=new ll*[b],**x=new ll*[b];
	for(int i=0;i<b;i++) {
		e[i]=new ll[b];
		e[i][0]=1;
		x[i]=new ll[b];
		x[i][0]=1;
	}
	for(int i=1;i<b;i++) {
		for(int j=0;j<b;j++) {
			e[j][i]=(i<=j?1:0);
			for(int k=0;k<i;k++) e[j][i]+=e[j][k];
			x[j][i]=e[j][i];
		}
	}
	
	a-=(b+1);
	int m=a%b;
	a/=b;
	while(a>0) {
		if(a%2==1) muti(x,e,b);
		muti(e,e,b);
		a/=2;
		/*
		for(int i=0;i<b;i++) {
			for(int j=0;j<b;j++) {
				cout<<x[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	ll sum=0;
	for(int i=0;i<b;i++) sum+=x[i][m];
	return sum%MOD;
}

void increment(ll *tree, ll treeStart, ll rangeStart, ll rangeEnd, ll targetStart, ll targetEnd, ll incrementBy) {
    if (rangeStart >= targetEnd || rangeEnd <= targetStart) {
        return;
    }
    if (targetStart <= rangeStart && rangeEnd <= targetEnd) {
        tree[treeStart]+=incrementBy;
        return;
    }
    ll middle = (rangeStart + rangeEnd)/2;
    increment(tree, treeStart*2, rangeStart, middle, targetStart, targetEnd, incrementBy);
    increment(tree, treeStart*2+1, middle, rangeEnd, targetStart, targetEnd, incrementBy);
}

void fillTree(ll *tree, ll treeStart, ll rangeStart, ll rangeEnd,ll suma,ll sumb) {
    if (rangeEnd - rangeStart == 1) {
        tt += f(suma+aTree[treeStart],sumb+bTree[treeStart]);
        return;
    }

    
    ll middle = (rangeStart + rangeEnd)/2;
    fillTree(tree, treeStart*2, rangeStart, middle, suma+aTree[treeStart], sumb+bTree[treeStart]);
    fillTree(tree, treeStart*2+1, middle, rangeEnd, suma+aTree[treeStart], sumb+bTree[treeStart]);
}

int main(){
    int n, m;
    cin >> n >> m;

	for(int i=0;i<MAX_N*3;i++) aTree[i]=0;
    for(int i=0;i<MAX_N*3;i++) bTree[i]=0;

    // First value
    aTree[1] = 1;
    bTree[1] = 1;

    REP(i, m) {
        char c;
        ll j, k, h;
        cin >> c >> j >> k >> h;
        j--;
        k--;
        ll *tree;
        if (c == 'a') {
            tree = aTree;
        } else {
            tree = bTree;
        }
        if (k >= j) {
            increment(tree, 1, 0, n, j, k+1, h);
        } else {
            increment(tree, 1, 0, n, j, n, h);
            increment(tree, 1, 0, n, 0, k+1, h);
        }
    }
 
    ll finalA[n];
    ll finalB[n];
    for(int i=0;i<n;i++)finalA[i]=0;
    for(int i=0;i<n;i++)finalB[i]=0;



    fillTree(aTree, 1, 0, n,0,0);

    cout << tt << endl;
}
