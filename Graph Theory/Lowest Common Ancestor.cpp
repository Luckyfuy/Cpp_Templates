/*
最近公共祖先
两个节点中离根最远的公共祖先
*/

#include <bits/stdc++.h>

// 树的最大空间
const int MAX_SIZE = 10000, MAX_LOG = 20;

// 有根树
template<class type>
class Tree {
    private:
        type root, fa[MAX_SIZE][MAX_LOG];
        std::vector<type> g[MAX_SIZE];
        int depth[MAX_SIZE], lg[MAX_LOG];

    public:
        // 构造函数
        Tree(type _root, int n);

        // 方法
        void dfs(type now, type dad);
        type lca(type a, type b);
};

// 初始化
template<class type>
Tree<type>::Tree(type _root, int n) {
    root = _root;
    for (int i = 1; i < n; ++i) {
        type a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i / 2] + 1;
    dfs(root, 0);
}

// DFS初始化
template<class type>
void Tree<type>::dfs(type now, type dad) {
    fa[now][0] = dad;
    depth[now] = depth[dad] + 1;
    for (int i = 1; i <= lg[depth[now]]; ++i)
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    for (int i = 0; i < int(g[now].size()); ++i)
        if (g[now][i] != dad)
            dfs(g[now][i] , now);
}

// 最近公共祖先
template<class type>
type Tree<type>::lca(type a, type b) {
    if (depth[a] < depth[b])
        std::swap(a, b);
    while (depth[a] > depth[b])
        a = fa[a][lg[depth[a] - depth[b]]];
    if (a == b)
        return a;
    for (int i = lg[depth[a]]; i >= 0; --i)
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

// 测试
int main() {
    int root, n, m;
    scanf("%d %d %d", &n, &m, &root);
    Tree<int> g(root, n);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", g.lca(a, b));
    }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}