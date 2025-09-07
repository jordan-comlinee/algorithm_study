#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define Xvalue 0
#define Yvalue 1

using namespace std;

vector<vector<int>> tree;
vector<int> preorderResult;
vector<int> postorderResult;

void insertByX(int rootId, int childId, vector<vector<int>> nodeinfo)
{
    int cur = rootId;
    while (true)
    {
        int xChild = nodeinfo[childId - 1][Xvalue];
        int xCur = nodeinfo[cur - 1][Xvalue];

        if (xChild < xCur)
        {
            if (tree[cur][0] == 0)
            {
                tree[cur][0] = childId;
                break;
            }
            cur = tree[cur][0];
        }
        else
        {
            if (tree[cur][1] == 0)
            {
                tree[cur][1] = childId;
                break;
            }
            cur = tree[cur][1];
        }
    }
}

void preorder(int id)
{
    if (id == 0) return;
    preorderResult.push_back(id);
    preorder(tree[id][0]);
    preorder(tree[id][1]);
}

void postorder(int id)
{
    if (id == 0) return;
    postorder(tree[id][0]);
    postorder(tree[id][1]);
    postorderResult.push_back(id);
}

bool compare(vector<int> nodeA, vector<int> nodeB)
{
    if (nodeA[Yvalue] != nodeB[Yvalue])
    {
        return nodeA[Yvalue] > nodeB[Yvalue];
    }
    else
    {
        return nodeA[Xvalue] < nodeB[Xvalue];
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> allNode = nodeinfo;

    for (int i = 0; i < allNode.size(); ++i)
    {
        allNode[i].push_back(i + 1);
    }

    sort(allNode.begin(), allNode.end(), compare);

    tree.resize(allNode.size() + 1);

    for (int i = 1; i < tree.size(); ++i)
    {
        tree[i] = { 0,0 };
    }

    int rootId = allNode[0][2];

    for (int i = 1; i < allNode.size(); ++i)
    {
        int childId = allNode[i][2];

        insertByX(rootId, childId, nodeinfo);
    }

    preorder(rootId);
    postorder(rootId);

    vector<vector<int>> answer(2);
    answer[0] = preorderResult;
    answer[1] = postorderResult;
    return answer;
}
