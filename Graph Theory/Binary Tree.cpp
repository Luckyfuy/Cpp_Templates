/*
二叉树
一种每个结点最多有两个子树的树结构
*/

#include <bits/stdc++.h>

// 节点
template<class type>
struct Node
{
    // 数据
    type data;
    // 指向子节点的指针
    Node<type> *le, *rt;

    // 构造函数
    Node(type _data);
};

// 初始化
template<class type>
Node<type>::Node(type _data)
{
    data = _data;
    le = rt = nullptr;
}

// 二叉树
template<class type>
class BinaryTree
{
    private:
        // 根节点
        Node<type> *root;

        // 建树
        const int end = -1;
        bool build(Node<type>*& r);

    public:
        // 构造函数
        BinaryTree();

        // 方法
        bool build();
        Node<type>* getRoot();
        void preOrder(Node<type>* r);
        void inOrder(Node<type>* r);
        void postOrder(Node<type>* r);
};

// 初始化
template<class type>
BinaryTree<type>::BinaryTree()
{
    root = nullptr;
}

// 建树
template<class type>
bool BinaryTree<type>::build(Node<type>*& r)
{
    type ele;
    std::cin >> ele;
    if (ele == end)
    {
        return false;
    }
    r = new Node<type>(ele);
    if (!build(r -> le))
    {
        r -> le = nullptr;
    }
    if (!build(r -> rt))
    {
        r -> rt = nullptr;
    }
    return true;
}

template<class type>
bool BinaryTree<type>::build()
{
    return build(root);
}

// 获取根节点指针
template<class type>
Node<type>* BinaryTree<type>::getRoot()
{
    return root;
}

// 先序遍历
template<class type>
void BinaryTree<type>::preOrder(Node<type>* r)
{
    if (r == nullptr)
    {
        return;
    }
    std::cout << r -> data << " ";
    preOrder(r -> le);
    preOrder(r -> rt);
}

// 中序遍历
template<class type>
void BinaryTree<type>::inOrder(Node<type>* r)
{
    if (r == nullptr)
    {
        return;
    }
    inOrder(r -> le);
    std::cout << r -> data << " ";
    inOrder(r -> rt);
}

// 后序遍历
template<class type>
void BinaryTree<type>::postOrder(Node<type>* r)
{
    if (r == nullptr)
    {
        return;
    }
    postOrder(r -> le);
    postOrder(r -> rt);
    std::cout << r -> data << " ";
}

// 测试
int main()
{
    BinaryTree<int> tree;
    tree.build();

    Node<int>* root = tree.getRoot();
    printf("%d\n", root -> data);

    tree.preOrder(root);
    puts("");
    tree.inOrder(root);
    puts("");
    tree.postOrder(root);
    puts("");

    setbuf(stdin, nullptr);
    getchar();
    return 0;
}