/*
并查集
一种处理不相交集合的合并与查询问题的树型数据结构
*/

#include <bits/stdc++.h>

// 并查集的最大空间
const int MAX_SIZE = 100000;

// 并查集
template<class type>
class UnionFind {
    private:
        // 元素
        type ele[MAX_SIZE];

    public:
        // 构造函数
        UnionFind();

        // 方法
        void uni(type a, type b);
        type find(type e);
        bool ask(type a, type b);
};

// 初始化
template<class type>
UnionFind<type>::UnionFind() {
    for (int i = 1; i < MAX_SIZE; ++i)
        ele[i] = i;
}

// 合并a和b所在的集合
template<class type>
void UnionFind<type>::uni(type a, type b) {
    ele[find(a)] = find(b);
}

// 查询e所属集合
template<class type>
type UnionFind<type>::find(type e) {
    if (ele[e] == e)
        return e;
    return ele[e] = find(ele[e]);
}

// a和b是否在同一集合
template<class type>
bool UnionFind<type>::ask(type a, type b) {
    return find(a) == find(b);
}

// 测试
int main() {
    UnionFind<int> uf;
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        uf.uni(a, b);
    }

    std::cout.setf(std::ios_base::boolalpha);
    for (int i = 1; i <= n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        std::cout << uf.ask(a, b) << std::endl;
    }

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}