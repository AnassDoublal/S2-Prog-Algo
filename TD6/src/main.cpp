#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <node.hpp>
#include <smartNode.hpp>

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

    std::cout << "Hauteur de l'arbre : " << root->height() << "\n";

    std::cout << "Valeur min de l'arbre : " << root->min() << "\n";
    std::cout << "Valeur max de l'arbre : " << root->max() << "\n";

    delete_tree(root);

    // Smart pointers

    std::cout << "-----SMART POINTERS-----\n";

    std::unique_ptr<SmartNode> root1 = create_smart_node(5);
    root1->insert(3);
    root1->insert(7);
    root1->insert(2);
    root1->insert(4);
    root1->insert(6);
    root1->insert(8);
    root1->insert(1);
    root1->insert(9);
    root1->insert(0);

    std::cout << "Ordre infixe : ";
    root1->display_infixe(root1);
    std::cout << "\n";
}