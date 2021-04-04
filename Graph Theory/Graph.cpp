/*
图
节点和边的集合
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
    Edge(int _from, int _to, type _dis)
    {
        from = _from;
        to = _to;
        dis = _dis;
    }
};

// 边的最大数量
const int MAX_SIZE = 100000;

// 图
template<class type>
class Graph
{
    private:
        // 每个点连接的边
        std::vector<Edge<type>> g[MAX_SIZE];
        // 每个点是否被访问过
        bool vis[MAX_SIZE];

    public:
        // 构造函数
        Graph();

        // 方法
        void drtInsert(int u, int v, type w);
        void undrtInsert(int u, int v, type w);
        void dfs(int u);
        void bfs(int u);
};

// 初始化
template<class type>
Graph<type>::Graph()
{
    for (int i = 1; i <= MAX_SIZE; ++i)
    {
        vis[i] = false;
    }
}

// 添加一条有向边
template<class type>
void Graph<type>::drtInsert(int u, int v, type w)
{
    g[u].push_back(Edge<type>(u, v, w));
}

// 添加一条无向边（双向边）
template<class type>
void Graph<type>::undrtInsert(int u, int v, type w)
{
    drtInsert(u, v, w);
    drtInsert(v, u, w);
}

// 深度优先搜索
template<class type>
void Graph<type>::dfs(int u)
{
    std::cout << u << " ";
    vis[u] = true;
    for (int v = 0; v < int(g[u].size()); ++v)
    {
        if (!vis[g[u][v].to])
        {
            dfs(g[u][v].to);
        }
    }
}

// 宽度优先搜索
template<class type>
void Graph<type>::bfs(int u)
{
    std::queue<type> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        std::cout << v << " ";
        for (int i = 0; i < int(g[v].size()); ++i)
        {
            if (!vis[g[v][i].to])
            {
                q.push(g[v][i].to);
                vis[g[v][i].to] = true;
            }
        }
    }
}

// 测试
int main()
{
    Graph<int> g;
    int n, flag;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u, v, w;
        scanf("%d %d %d %d", &flag, &u, &v, &w);
        if (flag)
        {
            g.drtInsert(u, v, w);
        }
        else
        {
            g.undrtInsert(u, v, w);
        }
    }

    scanf("%d %d", &flag, &n);
    if (flag)
    {
        g.dfs(n);
    }
    else
    {
        g.bfs(n);
    }
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}