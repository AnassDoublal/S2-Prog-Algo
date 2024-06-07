#include "smartNode.hpp"

std::unique_ptr<SmartNode> create_smart_node(int value)
{
    return std::make_unique<SmartNode>(SmartNode{value});
}

std::unique_ptr<SmartNode>& SmartNode::most_left(std::unique_ptr<SmartNode>& node)
{
    return (node && node->left) ? most_left(node->left) : node;
}

bool remove(std::unique_ptr<SmartNode>& node, int value)
{
    if (!node) return false;
    if (value < node->value)
        return remove(node->left, value);
    else if (value > node->value)
        return remove(node->right, value);
    else {
        if (!node->left && !node->right) {
            node.reset();
        } else if (!node->left) {
            node = std::move(node->right);
        } else if (!node->right) {
            node = std::move(node->left);
        } else {
            std::unique_ptr<SmartNode>& minRight = SmartNode::most_left(node->right);
            node->value = minRight->value;
            remove(minRight, minRight->value);
        }
        return true;
    }
}

bool SmartNode::is_leaf() const
{
    return !left && !right;
}

void SmartNode::insert(int value)
{
    if (value < this->value) {
        if (!left) {
            left = std::make_unique<SmartNode>(SmartNode{value});
        } else {
            left->insert(value);
        }
    } else {
        if (!right) {
            right = std::make_unique<SmartNode>(SmartNode{value});
        } else {
            right->insert(value);
        }
    }
}

void SmartNode::display_infixe(const std::unique_ptr<SmartNode>& node)
{
    if (node) {
        display_infixe(node->left);
        std::cout << node->value << " ";
        display_infixe(node->right);
    }
}