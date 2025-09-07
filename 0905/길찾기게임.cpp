#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _node
{
    int idx;
    int x;
    int y;
    _node* left;
    _node* right;

    bool operator < (const _node& o) const
    {
        if (y != o.y) return y > o.y;
        if (x != o.x) return x > o.x;
        return idx > o.idx;
    }

} Node;

static void insertNode(Node* root, Node* cur) {
    if (cur->x < root->x) {
        if (root->left) insertNode(root->left, cur);
        else root->left = cur;
    }
    else {
        if (root->right) insertNode(root->right, cur);
        else root->right = cur;
    }
}

void preorder(Node* n, vector<int>& out) {
    if (!n) return;
    out.push_back(n->idx);
    preorder(n->left, out);
    preorder(n->right, out);
}

void postorder(Node* n, vector<int>& out) {
    if (!n) return;
    postorder(n->left, out);
    postorder(n->right, out);
    out.push_back(n->idx);
}

// 전위 순회, 후위 순회
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node> nodes;

    for (int i = 0; i < nodeinfo.size(); ++i)
    {
        nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
    }

    sort(nodes.begin(), nodes.end());

    Node* root = &nodes[0];

    for (int i = 1; i < nodes.size(); ++i) {
        insertNode(root, &nodes[i]);
    }

    vector<int> prev;
    vector<int> post;
    preorder(root, prev);
    postorder(root, post);
    answer.push_back(prev);
    answer.push_back(post);
    return answer;
}