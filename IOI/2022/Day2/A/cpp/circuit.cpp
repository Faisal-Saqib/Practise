#include "circuit.h"

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 2022, N = 2e5 + 100;
ll w[N], zz, a[N], n, m1, pre[N];
ll con[N];
vector<int> ch[N];
ll seg[N << 2][2];
int lzy[N<<2];
void pull(int v,int lc,int rc)
{
  seg[v][0] = (seg[lc][0] + seg[rc][0]) % mod;
  seg[v][1] = (seg[lc][1] + seg[rc][1]) % mod;
}
void build(int l = 0, int r = zz, int v = 1)
{
  if (l == r)
  {
    seg[v][0] = a[l] * con[l];
    seg[v][1]=(!a[l])*con[l];
    lzy[v]=0;
    return;
  }
  int m=(l+r)>>1;
  int lc=(v<<1),rc=lc|1;
  build(l,m,lc);
  build(m+1,r,rc);
  pull(v,lc,rc);
}
void push(int l,int r,int v)
{
  if(lzy[v])
  {
    swap(seg[v][0],seg[v][1]);
    if(l!=r)
    {
      lzy[v<<1]^=lzy[v];
      lzy[v<<1|1]^=lzy[v];
    }
    lzy[v]=0;
  }
}
void Update(int ql,int qr,int l=0,int r=zz,int v=1)
{
  push(l,r,v);
  if(r<ql or qr<l)return;
  if(ql<=l and r<=qr)
  {
    lzy[v]^=1;
    push(l,r,v);
    return;
  }
  int m = (l + r) >> 1;
  int lc = (v << 1), rc = lc | 1;
  Update(ql,qr,l, m, lc);
  Update(ql,qr,m + 1, r, rc);
  pull(v, lc, rc);
}
void init(int N, int M, std::vector<int> P, std::vector<int> A)
{
  n = N;
  m1 = M;
  zz = m1 - 1;
  for (int i = 0; i < M; i++)
    a[i] = A[i], w[i + N] = 1;
  ;
  for (int i = 1; i < n + m1; i++)
  {
    ch[P[i]].push_back(i);
  }
  for (int i = n - 1; i >= 0; i--)
  {
    w[i] = 1;
    for (auto j : ch[i])
    {
      w[i] = (w[i] * w[j]) % mod;
    }
    w[i] = (w[i] * (int)ch[i].size()) % mod;
    // cout<<"Hola "<<i<<' '<<w[i]<<endl;
  }
  for (int i = 0; i < n + m1; i++)
    con[i] = 1;
  for (int i = n - 1; i >= 0; i--)
  {
    pre[0] = 1;
    for (int j = 0; j < ch[i].size(); j++)
    {
      pre[j + 1] = pre[j] * w[ch[i][j]] % mod;
    }
    // w[i] dont need to recompute
    ll suf = 1;
    for (int j = ch[i].size(); j >= 1; j--)
    {
      ll cur = (suf * pre[j - 1]) % mod;
      con[ch[i][j - 1]] = cur;
      suf=(suf*w[ch[i][j-1]])%mod;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (auto j : ch[i])
    {
      con[j] = (con[j] * con[i]) % mod;
    }
  }
  for(int i=0;i<M;i++)
  {
    con[i]=con[i+N];
  }
  build();
}

int count_ways(int L, int R)
{
  Update(L-n,R-n);
  return seg[1][0];
}