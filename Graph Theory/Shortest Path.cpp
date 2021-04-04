/*
最短路
求两节点间权值和最小的路径
*/

#include <bits/stdc++.h>

// 图的最大空间
const int MAX_SIZE = 500;

// 图
template<class type>
class Floyd
{
    private:
        // 图、节点数
        int g[MAX_SIZE][MAX_SIZE], node;
        // 是否执行过最短路
        bool flag;

    public:
        // 构造函数
        Floyd(int _node);

        // 方法
        void insert(int u, int v, type w);
        type floyd(int u, int v);
};

// 初始化
template<class type>
Floyd<type>::Floyd(int _node)
{
    node = _node;
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= node; ++i)
    {
        g[i][i] = 0;
    }
    flag = false;
}

// 添加一条有向边
template<class type>
void Floyd<type>::insert(int u, int v, type w)
{
    g[u][v] = w;
}

// 最短路
// Floyd算法
template<class type>
type Floyd<type>::floyd(int u, int v)
{
    if (!flag)
    {
        for (int k = 1; k <= node; ++k)
        {
            for (int i = 1; i <= node; ++i)
            {
                for (int j = 1; j <= node; ++j)
                {
                    if (i != j && i != k && j != k)
                    {
                        g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
                    }
                }
            }
        }
        flag = true;
    }
    return g[u][v];
}

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

// 图
template<class type>
class Graph
{
    private:
        // 起点出发的距离、起点
        int dis[MAX_SIZE], start;
        // 每个点连接的边
        std::vector<Edge<type>> g[MAX_SIZE];

    public:
        // 构造函数
        Graph(int _start);

        // 方法
        void insert(int u, int v, type w);
        type spfa(int u);
        type dijkstra(int u);
};

// 初始化
template<class type>
Graph<type>::Graph(int _start)
{
    start = _start;
    memset(dis, 0x3f, sizeof(dis));
    dis[start] = 0;
}

// 添加一条有向边
template<class type>
void Graph<type>::insert(int u, int v, type w)
{
    g[u].push_back(Edge<type>(u, v, w));
}

// 最短路
// SPFA算法
template<class type>
type Graph<type>::spfa(int u)
{
    bool vis[MAX_SIZE] = {};
    std::queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < int(g[now].size()); ++i)
        {
            Edge<type> e = g[now][i];
            if (dis[e.to] > dis[now] + e.dis)
            {
                dis[e.to] = dis[now] + e.dis;
                if (!vis[e.to])
                {
                    q.push(e.to);
                    vis[e.to] = true;
                }
            }
        }
    }
    return dis[u];
}

// 最短路
// Dijkstra算法
template<class type>
type Graph<type>::dijkstra(int u)
{
    bool vis[MAX_SIZE] = {};
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push(std::make_pair(0, start));
    while (!q.empty())
    {
        int now = q.top().second;
        q.pop();
        if (!vis[now])
        {
            vis[now] = true;
            for (int i = 0; i < int(g[now].size()); ++i)
            {
                Edge<type> e = g[now][i];
                if (dis[e.to] > dis[now] + e.dis)
                {
                    dis[e.to] = dis[now] + e.dis;
                    q.push(std::make_pair(dis[e.to], e.to));
                }
            }
        }
    }
    return dis[u];
}

// 测试
int main()
{
    int m, n, s;
    scanf("%d %d %d", &m, &n, &s);
    Floyd<int> floyd(m);
    Graph<int> g(s);
    for (int i = 1; i <= n; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        floyd.insert(u, v, w);
        g.insert(u, v, w);
    }

    for (int i = 1; i <= m; ++i)
    {
        printf("%d ", floyd.floyd(s, i));
    }
    puts("");
    for (int i = 1; i <= m; ++i)
    {
        printf("%d ", g.dijkstra(i));
    }
    puts("");
    for (int i = 1; i <= m; ++i)
    {
        printf("%d ", g.spfa(i));
    }
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}