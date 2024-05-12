#include <node.hpp>

Node* create_node(int value)
{
    Node* node = new Node{value};

    return node;
}

bool Node::is_leaf() const
{
    if(!left && !right)
        return true;
    
    return false;
}

Node* insert(Node* root, int data)
{
    if (!root) {
        return new Node{data};
    }
    if (data < root->value) {
        root->left = insert(root->left, data);
    } else if (data > root->value) {
        root->right = insert(root->right, data);
    }
    return root;
}

int Node::height() const
{
    if (!this) return -1;
    int leftHeight = left ? left->height() : -1;
    int rightHeight = right ? right->height() : -1;
    return 1 + std::max(leftHeight, rightHeight);
}

void Node::delete_childs()
{
    if (left) {
            left->delete_childs();
            delete left;
            left = nullptr;
        }
        if (right) {
            right->delete_childs();
            delete right;
            right = nullptr;
        }
}

void Node::display_infixe() const {
        if (left) left->display_infixe();
        std::cout << value << " ";
        if (right) right->display_infixe();
    }

std::vector<Node const*> Node::prefixe() const
{
   std::vector<Node const*> result;
    result.push_back(this);
    if (left) {
        auto leftPrefix = left->prefixe();
        result.insert(result.end(), leftPrefix.begin(), leftPrefix.end());
    }
    if (right) {
        auto rightPrefix = right->prefixe();
        result.insert(result.end(), rightPrefix.begin(), rightPrefix.end());
    }
    return result;
}

Node*& most_left(Node*& node)
{
    return (node && node->left) ? most_left(node->left) : node;
}

bool remove(Node*& node, int data) {
    if (!node) return false;
    if (data < node->value)
        return remove(node->left, data);
    else if (data > node->value)
        return remove(node->right, data);
    else {
        if (!node->left && !node->right) {
            delete node;
            node = nullptr;
        } else if (!node->left) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (!node->right) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else { // Case 4: Two children
            Node*& minRight = most_left(node->right);
            node->value = minRight->value;
            remove(minRight, minRight->value);
        }
        return true;
    }
}

void delete_tree(Node* node)
{
    if (!node) 
        return;

    delete_tree(node->left);
    delete_tree(node->right);

    delete node;
}