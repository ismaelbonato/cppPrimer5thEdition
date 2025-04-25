#include <iostream>

class TreeNode
{
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
        : value("")
        , count(0)
        , left(nullptr)
        , right(nullptr)
    {
        std::cout << "TreeNode()" << std::endl;
    };
    
    TreeNode(const TreeNode &origin)
        : value(origin.value)
        , count(origin.count)
        , left(origin.left)
        , right(origin.right)
    {
        std::cout << "TreeNode(const TreeNode &origin)" << std::endl;
    };

    ~TreeNode() = default;
};

class BinStrTree
{
private:
    TreeNode *root;
    std::size_t *userCount;

public:
    BinStrTree()
        : root(new TreeNode)
        , userCount(new std::size_t(1))
    {
        std::cout << "BinStrTree() userCount: " << *userCount << std::endl;
    };

    BinStrTree(const BinStrTree &origin)
        : root(origin.root)
        , userCount(origin.userCount)
    {
        std::cout << "BinStrTree(const BinStrTree &origin)" << std::endl;
        ++(*userCount);
    };

    BinStrTree &operator=(const BinStrTree &rhs)
    {
        std::cout << " BinStrTree & operator=(const BinStrTree &rhs)" << std::endl;
        if (this == &rhs) {
            return *this;
        }

        --(*userCount);
        if (*userCount == 0) {
            std::cout << "old userCount: " << *userCount << std::endl;
            std::cout << "delete root" << std::endl;
            delete root;
            delete userCount;
        }

        root = rhs.root;
        userCount = rhs.userCount;

        ++(*userCount);

        return *this;
    };
    ~BinStrTree()
    {
        std::cout << " ~BinStrTree userCount: " << *userCount << std::endl;
        --(*userCount);
        if (*userCount == 0) {
            delete root;
            delete userCount;
        }
    };
};

int main()
{
    BinStrTree binTree;

    BinStrTree binTree2(binTree);

    BinStrTree binTree3 = binTree;
    BinStrTree binTree4;
    

    binTree4 = binTree;

    return 0;
}
