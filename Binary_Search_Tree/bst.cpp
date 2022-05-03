#include <iostream>
#include <climits>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int k) : data(k), left(NULL), right(NULL)
    {
    }
};

void preOrder(node *root)
{
    if (root == NULL)
        return;

    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        root = new node(key);
        return root;
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

node *inorderSuccessor(node *root)
{
    node *curr = root->right;

    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    std::cout << "Inorder successor of  : " << root->data << " is " << curr->data << std::endl;
    return curr;
}

node *deleteNode(node *root, int key)
{
    // base case, if root is NULL
    if (root == NULL)
        return root;

    // if key is less than root
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    // if key is greater than root
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    // else key is same as root's key, then this is the node
    // to e deleted
    else
    {
        // key node has no child
        // key node has one child, this is optimized solution
        if (root->right == NULL)
        {
            node *root_left_child = root->left;
            // std::cout << "left_child deleting : " << root->data << std::endl;
            delete root;
            return root_left_child;
        }
        else if (root->left == NULL)
        {
            node *root_right_child = root->right;
            // std::cout << "right_child deleting : " << root->data << std::endl;
            delete root;
            return root_right_child;
        }
        // key node has 2 children, special case
        else
        {
            node *inSuccessor = inorderSuccessor(root);
            root->data = inSuccessor->data;
            root->right = deleteNode(root->right, inSuccessor->data);
            return root;
        }
    }

    return root;
}

// 50, 30, 20, 40, 70, 60, 80
node *constructBSTFromPreorder(int arr[], int size, int *index, int min, int max)
{
    if (*index >= size)
    {
        return NULL;
    }

    int key = arr[*index];
    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *index = *index + 1;

        if (*index < size)
            root->left = constructBSTFromPreorder(arr, size, index, min, root->data);
        if (*index < size)
            root->right = constructBSTFromPreorder(arr, size, index, root->data, max);
    }

    return root;
}

// Function to find k'th smallest element in BST
// Here count denotes the number of nodes processed so far
node *kthSmallest(node *root, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }

    node *temp = NULL;

    if (k > 1)
        temp = kthSmallest(root->left, k);
    if (k == 1)
    {
        return root;
    }
    k--;
    if (k > 1)
        temp = kthSmallest(root->right, k);

    return temp;
}

int main()
{
    /* Let us create following BST
          50
       /     \
      30      70
     /  \    /  \
   20   40  60   80 */

    node *root = insert(NULL, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);

    /* Let us create following BST
           10
        /     \
       5       40
      /  \       \
     1   7        50
    */

    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);
    int index = 0;

    node *root2 = constructBSTFromPreorder(pre, size, &index, INT_MIN, INT_MAX);
    cout << "\n Preorder traversal of the modified tree \n";
    preOrder(root2);

    int k = 3;
    node *kNode = kthSmallest(root2, k);
    cout << "3rd smallest element in BST : " << kNode->data << endl;

    return 0;
}