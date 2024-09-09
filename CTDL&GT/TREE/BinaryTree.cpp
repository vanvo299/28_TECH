// CÂY NHỊ PHÂN
#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int val;
    // 2 con tro
    node *left; // luu dia chi cua node con ben trai
    node *right; // luu dia chi cua node con ben phai
    // constructor
    node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
// tạo một node mới. LƯU Ý: có thể dùng constructor hoặc dùng hàm makeNode để tạo một node mới
// node *makeNode(int x)
// {
//     node *newNode = new node;
//     newNode->data = x;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode; 
// }

// hàm thêm cạnh vào cây
void makeRoot(node *root, int u, int v, char c)
{
    if (c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

// hàm thêm node vào cây nhị phân
void insertNode(node *root, int u, int v, char c)
{
    if (root == NULL) return;
    if (root->val == u) {
        makeRoot(root, u, v, c);
    }
    else {
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

// duyệt giữa (left - root - right)
void inorder(node *root)
{
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// duyệt trước (root - left - right)
void preorder(node *root)
{
    if (root != NULL) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// duyệt sau (left - right - root)
void postorder(node *root)
{
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

int main()
{
    node *root = NULL;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        if (root == NULL) {
            root = new node(u);
            makeRoot(root, u, v, c);
        } else {
            insertNode(root, u, v, c);
        }
    }
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}