#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <node.hpp>

int main()
{
    Node* root = create_node(5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 0);

    std::cout << "Ordre infixe : ";
    root->display_infixe();
    std::cout << "\n";

    std::cout << "Hauteur de l'arbre: " << root->height() << "\n";

    delete_tree(root);
}