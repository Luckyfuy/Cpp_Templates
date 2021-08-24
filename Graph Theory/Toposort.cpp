/*
拓扑排序
对一个图的所有节点排序，使得每一条有向边(u,v)对应的u都排在v的前面
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
        // 点的数量
        int size;
        // 每个点连接的边
        std::vector<Edge<type>> g[MAX_SIZE];
        // 每个点的入度
        int in[MAX_SIZE];

    public:
        // 构造函数
        Graph(int _size);

        // 方法
        void insert(int u, int v, type w);
        bool toposort();
};

// 初始化
template<class type>
Graph<type>::Graph(int _size)
{
    size = _size;
    for (int i = 1; i <= size; ++i)
        in[i] = 0;
}

// 添加一条有向边
template<class type>
void Graph<type>::insert(int u, int v, type w)
{
    g[u].push_back(Edge<type>(u, v, w));
}

// 拓扑排序
template<class type>
bool Graph<type>::toposort()
{
    // 计算每个点的入度
    for (int i = 1; i <= size; ++i)
        for (int j = 0; j < int(g[i].size()); ++j)
            ++in[g[i][j].to];

    // 维持入度为0的点
    std::queue<type> q;
    // std::priority_queue<type, std::vector<type>, std::greater<type>> q;
    std::vector<type> num;
    for (int i = 1; i <= size; ++i)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int u = q.front();
        // int u = q.top();
        q.pop();
        num.push_back(u);
        for (int i = 0; i < int(g[u].size()); ++i)
        {
            int v = g[u][i].to;
            --in[v];
            if (in[v] == 0)
                q.push(v);
        }
    }

    // 若序列的长度与点的数量不等，则不存在拓扑序列
    if (int(num.size()) == size)
    {
        // 输出
        for (int i = 0; i < size; ++i)
            std::cout << num[i] << " ";
        return true;
    }
    return false;
}

// 测试
int main()
{
    int m, n;
    scanf("%d", &m);
    Graph<int> g(m);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.insert(u, v, w);
    }

    g.toposort();
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}