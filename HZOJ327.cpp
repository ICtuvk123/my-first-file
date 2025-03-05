#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class WeightedUnionSet{
public:
    WeightedUnionSet(int n):fa(n + 1),val(n + 1) {
        for (int i = 0 ; i <= n ; i++) {
            fa[i] = i;
            val[i] =0;
        }
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }
    void merge(int a,int b,int t) {
        int aa = get(a),bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (t + val[b] - val[a] + 2) % 2;
        return ;
    }
    vector<int> fa,val;
};

struct Data {
    int a,b,c;
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<Data> arr(m); 
    WeightedUnionSet u(n);
    int ans = 0;
    for (int i = 0 ; i < m ; i++) {
        scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
    }
    sort(arr.begin(),arr.end(),[&](const Data &a,const Data &b) {
        return a.c > b.c;
    });
    for (int i = 0 ; i < m ; i++) {
        int a = arr[i].a , b = arr[i].b;
        if (u.get(a) != u.get(b)) {
            u.merge(a,b,1);
            continue;
        }
        if ((u.val[a] + u.val[b]) % 2 == 0) {
            ans = arr[i].c;
            break;
        } 
    }
    printf("%d\n",ans);
    return 0;
}