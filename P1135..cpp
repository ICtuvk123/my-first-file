#include<iostream>
using namespace std;
int to[205];
int dis[205]={0};

void dfs(int step,int pos,int n) {
    if (dis[pos]<=step) return ;
    dis[pos]=step;
    if (pos+to[pos]<=n) dfs(step+1,pos+to[pos],n);
    if (pos-to[pos]>=1) dfs(step+1,pos-to[pos],n); 
    return ;
}

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) {
        scanf("%d",to+i);
    }
    for (int i=1;i<=n;i++) {
        dis[i]=n+1;
    }
    dfs(0,a,n);
    if (dis[b]==n+1) printf("-1");
    printf("%d",dis[b]);
    return 0;
}