#include<iostream>
#include<queue>
using namespace std;
#define Max 400 
int dir[8][2]={
    {2,1},{2,-1},{-2,1},{-2,-1},
    {1,2},{1,-2},{-1,2},{-1,-2}
};
int dis[Max+5][Max+5];
class Node {
public:
    Node(int x,int y,int s):x(x),y(y),s(s) {}
    int x,y,s;
};

void bfs(int n,int m,int x,int y) {
    queue<Node> q;
    q.push(Node(x,y,0));
    dis[x][y]=0;
    while (!q.empty()) {
        Node now=q.front();
        q.pop();                                            //遍历本层节点并把本层结点出队
        for (int k=0;k<8;k++) {
            int dx=now.x+dir[k][0];
            int dy=now.y+dir[k][1];
            if (dx<1||dx>n) continue;
            if (dy<1||dy>m) continue;
            if (dis[dx][dy]!=-1) continue;
            q.push(Node(dx,dy,now.s+1));
            dis[dx][dy]=now.s+1;
        }                                                   //找下一层的节点入队
    }
    return ;
}

int main() {
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            dis[i][j]=-1;
        }
    }
    bfs(n,m,x,y);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (j>1) printf(" ");
            printf("%d",dis[i][j]);
        }
        printf("\n");
    }
    return 0;
}