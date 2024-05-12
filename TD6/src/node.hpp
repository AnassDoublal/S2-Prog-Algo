#pragma once

#include <vector>
#include <iostream>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };
    bool is_leaf() const;
    int height() const;
    void delete_childs();
    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
};

Node* create_node(int value);
Node* insert(Node* root, int data);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);