#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#define ll long long
using namespace std;
typedef pair<int, int> PII;
int a[2003], b[2003];
int dp[2003];
int n;
int main() {
    int i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        int x, y;
        char ch;
        scanf("%d:%d %c", &x, &y, &ch);
        a[i] = x * 60 + y;
        b[i] = (ch == 'U');
    }
    int cnt = 0, last = -1e9;
    bool flag = 0;
    int pay = 0;
    for (i = 1; i <= n; i++) {
        if (a[i] - last <= 90) {
            if (b[i] == 0) {
                if (!pay) {
                    cnt += 26;
                    pay = 26;
                } else {
                    cnt += 44 - pay;
                    pay = 44;
                }
            } else if (!flag) {
                flag = 1;
                if (!pay) {
                    cnt += 28;
                    pay = 28;
                } else {
                    cnt += 44 - pay;
                    pay = 44;
                }
            } else {
                last = a[i];
                cnt += 28;
                pay = 28;
            }
        } else {
            last = a[i];
            if (b[i] == 0) {
                cnt += 26;
                pay = 26;
                flag =0;
            } else {
                flag = 1;
                cnt += 28;
                pay = 28;
            }
        }
        //printf("cnt = %d ", cnt);
    }
    printf("%d ", cnt);

    for (i = 0; i <= n; i++)
        dp[i] = 1e9;
    dp[0] = 0;
    a[0] = -1e9;
    for (i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + (b[i + 1] == 1 ? 28 : 26));
        //printf("%d %d %d////////\n",a[i]/60,a[i]%60, dp[i]);
        int cnt = 0;
        j = i + 1;
        int cur = a[i + 1];
        while (j <= n && a[j] - cur <= 90) {
            if (b[j] == 1)
                cnt++;
            if (cnt >= 2)
                break;
            j++;
        }
        j--;
        dp[j] = min(dp[j], dp[i] + 44);
    }
//  for(i = 1; i <= n; i++)
//      printf("%d~~~ ", dp[i]);
    printf("%d\n", dp[n]);
    return 0;
}
/*
2
00:00 U
23:59 S
5
10:00 U
10:30 S
10:50 U
11:20 U
12:51 S
4
20:00 S
21:30 S
21:31 S
21:32 S

10
1:11 U
1:12 S
1:13 U
1:14 S
3:33 S
3:43 U
20:00 S
21:30 S
21:31 S
21:32 S

 */
