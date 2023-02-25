/******************************************************************/
/* ACM ICPC 2017-2018, NEERC                                      */
/* Northern Subregional Contest                                   */
/* St Petersburg, November 4, 2017                                */
/******************************************************************/
/* Problem F. Fygon 2.0                                           */
/*                                                                */
/* Original idea         Artem Vasilyev                           */
/* Problem statement     Artem Vasilyev                           */
/* Test set              Artem Vasilyev                           */
/******************************************************************/
/* Solution                                                       */
/*                                                                */
/* Author                Pavel Kunyavskiy                         */
/******************************************************************/

#include <cstdio>
#include <map>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using namespace std;

typedef long long ll;

const int MAXN = 27;

int g[MAXN];

int convert(char c) {
  if (c == '1') return 0;
  assert('a' <= c && c <= 'z');
  return c - 'a' + 1;
}

void add(int a, int b) {
  a = convert(a);
  b = convert(b);
  g[a] |= 1 << b;
  g[a] |= 1 << a;
  g[b] |= 1 << b;
}

unordered_map<int, ll> cache;

ll go(int x) {
	for(int i=0;i<MAXN;i++) {
		printf("%d",!!(x&(1<<i)));
	}
	printf("\n");
  if (x == 0) return 1;
  ll &ans = cache[x];
  if (ans != 0) return ans;
  for (int i = 0; i < MAXN; i++) {
    if ((x & g[i]) == (1 << i)) {
      assert(x & (1 << i));
      ans += go(x ^ (1 << i));
    }
  }
  return ans;
}

int main() {
  //freopen("fygon20.in", "r", stdin);
  //freopen("fygon20.out", "w", stdout);

  int n;
  scanf("%d", &n);
  --n;
  add('1', 'n');

  for (int i = 0; i < n; i++) {
    char a, b, c;
    assert(scanf(" for %c in range(%c, %c):", &a, &b, &c) == 3);
    add(b, a);
    add(a, c);
  }

	for (int i = 0; i < MAXN; i++) {
	    if (g[i]) {
	      printf("%c: ", i + 'a' - 1);
	    }
	    for (int j = 0; j < MAXN; j++) {
	      if (g[i] && g[j]) {
	        printf("%d", !!(g[i] & (1 << j)));
	      }
	    }
	    if (g[i]) {
	      printf("\n");
	    }
	  }

  for (int k = 0; k < MAXN; k++) {
    for (int i = 0; i < MAXN; i++) {
      if (g[i] & (1 << k)) {
        g[i] |= g[k];
      }
    }
  }
  for (int i = 0; i < MAXN; i++) {
    if (g[i]) {
      printf("%c: ", i + 'a' - 1);
    }
    for (int j = 0; j < MAXN; j++) {
      if (g[i] && g[j]) {
        printf("%d", !!(g[i] & (1 << j)));
      }
    }
    if (g[i]) {
      printf("\n");
    }
  } 

  int used = (1 << MAXN) - 1;

  for (int i = 0; i < MAXN; i++) {
    if (g[i] == 0) {
      used &= ~(1 << i);
    }
    for (int j = i + 1; j < MAXN; j++) {
      if (g[i] == g[j]) {
        used &= ~(1 << j);
      }
    }
  }

  int k = __builtin_popcount(used) - 2;

  cache.rehash(1 << k);

  ll num = go(used);
  printf("%d\n",num);
  
  ll den = 1;
  for (int i = 1; i <= k; i++) {
    den *= i;
  }

  ll g = __gcd(num, den);
  num /= g;
  den /= g;

  printf("%d %lld/%lld\n", k, num, den);
}


