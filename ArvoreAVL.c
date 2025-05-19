#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int balance;
} Node;

int height(Node* node) {
    if (node == NULL) return 0;
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int calculateAVLBalance(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

void rotation(Node* node) {
    int balance = calculateAVLBalance(*node);

    if (balance > 1) {
        // Left Left Case
        if (calculateAVLBalance(node->left) > 0) {
            // Perform right rotation
            Node* temp = node->left;
            node->left = temp->right;
            temp->right = node;
            node = temp;
        } 
        // Left Right Case
        else {
            Node* pB = node->left;
            Node* pC = node->left->right;
            pB->right = pC->left;
            pC->left = pB;
            node->left = pC->right;
            pC->right = node;
            node = pC;
        }
    } else {
        if (calculateAVLBalance(node->right < 0)) {
            Node* temp = node->right;
            node->right = temp->left;
            temp->left = node;
            node = temp;
        } else {
            Node* pB = node->right;
            Node* pC = node->right->left;
            pB->left = pC->right;
            pC->right = pB;
            node->right = pC->left;
            pC->left = node;
            node = pC;
        }
    }
    
}
    
// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;

    
}

// Function to find the minimum value node in a tree
Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to remove a node from the tree
Node* removeNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    } else if (data > root->data) {
        root->right = removeNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Main function
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Removing 20...\n");
    root = removeNode(root, 20);
    printf("In-order traversal after removal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Removing 30...\n");
    root = removeNode(root, 30);
    printf("In-order traversal after removal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Removing 50...\n");
    root = removeNode(root, 50);
    printf("In-order traversal after removal: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
