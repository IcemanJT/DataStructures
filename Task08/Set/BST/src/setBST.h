struct setBSTNode
{
    int data;
    setBSTNode *left;
    setBSTNode *right;
    setBSTNode *parent;

    setBSTNode(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class setBST
{
    setBSTNode *root;
    int size;
    void printSet(setBSTNode *root);
    void clearSet(setBSTNode *root);

    void shiftNodes(setBSTNode *root, setBSTNode *node, setBSTNode *child);

    void setAdd(setBSTNode *root, setBST &s);

    void setIntersection(setBSTNode *root, setBST &s, setBST &result);

    void setDifference(setBSTNode *root, setBST &s, setBST &result);

    void setSubset(setBSTNode *root, setBST &s, bool &result);

    void setEqual(setBSTNode *root, setBST &s, bool &result);

    void deleteTree(setBSTNode *root);

public:
    setBST();
    ~setBST();
    setBST(const setBST &s);
    void insert(int x);
    void withdraw(int x);
    bool isInSet(int x);
    void printSet();
    void clearSet();
    int getSize();

    setBSTNode* isInSet_pointer(int x);

    setBST &operator+(const setBST &s);
    setBST &operator*(const setBST &s);
    setBST &operator-(const setBST &s);

    bool operator==(const setBST &s);
    bool operator<=(const setBST &s);
};