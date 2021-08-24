/*
最小生成树
一个图的极小联通子图，包含原图的所有节点，且所有边的权值之和最小
*/

#include <bits/stdc++.h>

// 边
template<class type>
struct Edge
{
    // 起点、终点、边权
    int from, to;
    type dis;

    // 构造函数
    Edge() {}
    Edge(int _from, int _to, type _dis)
    {
        from = _from;
        to = _to;
        dis = _dis;
    }
};

// 图的最大空间
const int MAX_SIZE = 50000;

// 图
template<class type>
class Kruskal
{
    private:
        // 点、边的数量
        int node, edge, tot;
        // 每个点连接的边
        Edge<type> g[MAX_SIZE];

        // 比较函数
        static bool cmp(Edge<type> a, Edge<type> b);
        // 并查集
        int fa[MAX_SIZE];
        int find(int u);

    public:
        // 构造函数
        Kruskal(int _node, int _edge);

        // 方法
        void insert(int u, int v, type w);
        type kruskal();
};

// 按权值排序
template<class type>
bool Kruskal<type>::cmp(Edge<type> a, Edge<type> b)
{
    return a.dis < b.dis;
}

// 查询点u
template<class type>
int Kruskal<type>::find(int u)
{
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}

// 初始化
template<class type>
Kruskal<type>::Kruskal(int _node, int _edge)
{
    node = _node;
    edge = _edge;
    tot = 0;
}

// 添加一条无向边
template<class type>
void Kruskal<type>::insert(int u, int v, type w)
{
    ++tot;
    g[tot].from = u;
    g[tot].to = v;
    g[tot].dis = w;
}

// 最小生成树
// Kruskal算法
template<class type>
type Kruskal<type>::kruskal()
{
    type w = 0;
    int tot = 0;
    std::sort(g + 1, g + edge + 1, cmp);
    for (int i = 1; i <= node; ++i)
        fa[i] = i;

    for (int i = 1; i <= edge; ++i)
    {
        Edge<type> e = g[i];
        if (find(e.from) != find(e.to))
        {
            w += g[i].dis;
            fa[find(e.from)] = find(e.to);
        }
        if (++tot == edge - 1)
            break;
    }
    return w;
}

// 图
template<class type>
class Prim
{
    private:
        // 点、边的数量
        int node, edge;
        // 每个点连接的边
        std::vector<Edge<type>> g[MAX_SIZE];

    public:
        // 构造函数
        Prim(int _node, int _edge);

        // 方法
        void insert(int u, int v, type w);
        type prim();
};

// 初始化
template<class type>
Prim<type>::Prim(int _node, int _edge)
{
    node = _node;
    edge = _edge;
}

// 添加一条无向边
template<class type>
void Prim<type>::insert(int u, int v, type w)
{
    g[u].push_back(Edge<type>(u, v, w));
    g[v].push_back(Edge<type>(v, u, w));
}

// 最小生成树
// Prim算法
template<class type>
type Prim<type>::prim()
{
    const int INF = 0x3f3f3f3f;

    type w = 0, dis[node];
    int now = 1;
    bool vis[node];
    for (int i = 2; i <= node; ++i)
    {
        vis[i] = false;

        dis[i] = INF;
        for (int j = 0; j < int(g[i].size()); ++j)
            if (g[i][j].to == now)
                dis[i] = std::min(dis[i], g[i][j].dis);
    }

    for (int i = 1; i < node; ++i)
    {
        type minn = INF;
        vis[now] = true;
        for (int j = 1; j <= node; ++j)
        {
            if (!vis[j] && minn > dis[j])
            {
                minn = dis[j];
                now = j;
            }
        }
        w += minn;
        for (int j = 1; j <= node; ++j)
            for (int k = 0; !vis[j] && k < int(g[now].size()); ++k)
                if (dis[g[now][k].to] > g[now][k].dis)
                    dis[g[now][k].to] = g[now][k].dis;
    }
    return w;
}

// 测试
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    Kruskal<int> g1(m, n);
    Prim<int> g2(m, n);
    for (int i = 1; i <= n; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g1.insert(u, v, w);
        g2.insert(u, v, w);
    }

    printf("%d\n%d\n", g1.kruskal(), g2.prim());

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}