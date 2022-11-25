#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node
{
    char data;
    int freq;
    node *left, *right;

    node(char d, int f)
    {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct comp
{
    bool operator()(node *l, node *r)
    {
        return l->freq > r->freq;
    }
};

void printCodes(struct node *root, string str)
{
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << " : " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffMan(vector<char> &chars, vector<int> &freq)
{
    priority_queue<node *, vector<node *>, comp> pq;

    node *left, *right, *top;

    for (int i = 0; i < chars.size(); i++)
    {
        pq.push(new node(chars[i], freq[i]));
    }

    while (pq.size() != 1)
    {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCodes(pq.top(), "");
}

int main()
{
    vector<char> chars = {'a', 'b', 'c', 'd'};
    vector<int> freq = {5, 1, 6, 3};

    huffMan(chars, freq);

    return 0;
}