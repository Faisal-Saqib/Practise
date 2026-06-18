#include "islands.h"

#include <variant>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+100;
bool vis[N],in[N],cyc=0;
vector<int> ma[N];
void dfs(int x)
{
  in[x]=vis[x]=1;
  for(auto y:ma[x])
  {
    if(!vis[y])
    {
      dfs(y);
    }
    else if(in[x])
    {
      cyc=1;
    }
  }
  in[x]=0;
}
int cnt[1000][1000];
std::variant<bool, std::vector<int>> find_journey(
    int N, int M, std::vector<int> U, std::vector<int> V) {
  for(int i=0;i<N;i++)
  {
    vis[i]=0;
    in[i]=0;
    ma[i].clear();
    for(int j=0;j<N;j++)
    {
      cnt[i][j]=0;
    }
  }
  for(int i=0;i<M;i++)
  {
    ma[U[i]].push_back(V[i]);
    cnt[U[i]][V[i]]++;
  }
  cyc=0;
  dfs(0);
  for(int x=0;x<N;x++)
  {
    for(int y=0;y<N;y++)
    {
      if(vis[x] and cnt[x][y]>=2)
      {
        return vector<int>({});
      }
    }
  }
  return false;
}
