#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root == NULL)
        return;
    traverseInOrder(root->left);
    cout << root->key << " " ;
    traverseInOrder(root->right);
    return ;
}

//find maximum node
struct node *maximumNode(struct node *root){
    if(root == NULL){
        cout << "Tree is Empty!\n";
        return NULL;
    }
    if(root->right==NULL){
        return root;
    }
    return maximumNode(root->right);
}
// Insert a node
// Insert a node
struct node* insertNode(struct node* root, int key) {
    if (root == NULL) {
        struct node *temp = new struct node ;
        temp->key = key;
        return temp;
    }
    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    return root;
}



// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        cout << "Key is not in Tree!\n";
        return NULL;
    }
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with no child
        if (root->left == NULL && root->right == NULL){
            free(root);
        }
        // Node with only one child
        else if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            // Node with two children
            struct node *temp = maximumNode(root->left);
            root->key = temp->key;
            root->left = deleteNode(root->left, temp->key);
            return root;
        }
    }
    return root;
}




// Driver code
int main() {
    struct node *root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1 : // insert
                cin >> operand;
                ;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2 : // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default :
                cout << "Invalid Operator!\n";
                return 0;
        }
    }
    traverseInOrder(root);
}
