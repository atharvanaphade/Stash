#include <bits/stdc++.h>

using namespace std;

const short inf = 30000;
const int N = 10010;
const int M = 100010;

int from[M], to[M], pred[M];
int x[N], col[N], last[N];
int res[M], r[M];
int pr[M], ne[M];
bool b[M], c[M];
short dist[N], d[N][N];

int main() {
  int tt;
  scanf("%d", &tt);
  memset(d, 0, sizeof(d));
  for (int qq = 1; qq <= tt; qq++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      scanf("%d %d", from + i, to + i);
      from[i + m] = to[i];
      to[i + m] = from[i];
    }
    double beg = clock();
    printf("Case #%d: ", qq);
    fflush(stdout);
    for (int i = 0; i < n; i++) last[i] = -1;
    for (int i = 0; i < m + m; i++) {
      pred[i] = last[from[i]];
      last[from[i]] = i;
    }
    for (int i = 0; i < n; i++) col[i] = 0;
    bool ok = true;
    for (int i = 0; i < n; i++)
      if (col[i] == 0) {
        int b = 1, e = 1;
        x[1] = i;
        col[i] = 1;
        while (b <= e) {
          int j = last[x[b]];
          while (j >= 0) {
            if (col[to[j]] == col[x[b]]) {
              ok = false;
              break;
            }
            if (col[to[j]] == 0) {
              e++;
              x[e] = to[j];
              col[x[e]] = 3 - col[x[b]];
            }
            j = pred[j];
          }
          if (!ok) break;
          b++;
        }
        if (!ok) break;
      }
    if (!ok) {
      printf("-1\n");
      fflush(stdout);
      continue;
    }
    for (int st = 0; st < n; st++) {
      for (int i = 0; i < n; i++) dist[i] = inf;
      int b = 1, e = 1;
      x[1] = st;
      dist[st] = 0;
      while (b <= e) {
        int j = last[x[b]];
        short dd = dist[x[b]] + 1;
        while (j >= 0) {
          if (dist[to[j]] == inf) {
            e++;
            x[e] = to[j];
            dist[x[e]] = dd;
          }
          j = pred[j];
        }
        b++;
      }
      for (int i = 0; i < n; i++) d[st][i] = dist[i];
    }
    for (int edge = 0; edge < m; edge++) res[edge] = -1;
    for (int edge = 0; edge < m; edge++) {
      pr[edge] = edge - 1;
      ne[edge] = edge + 1;
    }
    pr[m] = m - 1;
    ne[m - 1] = m;
    pr[0] = m + 1;
    ne[m + 1] = 0;
    int ans = 0;
    for (int edge = 0; edge < m; edge++) {
      if (res[edge] != -1) {
        continue;
      }
      for (int i = 0; i < n; i++) b[i] = (d[from[edge]][i] < d[to[edge]][i]);
      int kr = 0;
      int t = ne[m + 1];
      while (t < m) {
        c[t] = (b[from[t]] != b[to[t]]);
        if (c[t]) r[kr++] = t;
        t = ne[t];
      }
      for (int j = 0; j < kr; j++) {
        int new_edge = r[j];
        for (int i = 0; i < n; i++) b[i] = (d[from[new_edge]][i] < d[to[new_edge]][i]);
        bool ok = true;
        int t = ne[m + 1];
        while (t < m) {
          ok &= (c[t] == (b[from[t]] != b[to[t]]));
          t = ne[t];
        }
        if (!ok) {
          ans = -1;
          break;
        }
        res[new_edge] = ans;
      }
      if (ans == -1) {
        break;
      }
      for (int j = 0; j < kr; j++) {
        int new_edge = r[j];
        pr[ne[new_edge]] = pr[new_edge];
        ne[pr[new_edge]] = ne[new_edge];
      }
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}