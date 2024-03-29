#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>

int firstWord(std::string& str)
{
    char space = ' ';
    std::string::iterator pos;
    int nombreLettres{0};

    pos = std::find(str.begin(), str.end(), space);

    for (auto it = str.begin(); it != pos; ++it)
    {
        nombreLettres++;
    }

    return nombreLettres;
}

std::vector<std::string> split_string(std::string& str)
{
    char space = ' ';
    std::string token;

    std::vector<std::string> split;

    int i{0};
    while((i=str.find(space)) != std::string::npos)
    {
        token = str.substr(0, i);
        split.push_back(token);
        str.erase(0, i+1);
    }
    
    split.push_back(str);
    return split;
}

int main()
{
    srand(time(NULL));
    std::vector<int> vec;
    std::vector<int>::iterator pos;

    int target{0};
    std::string temp{""};
    int sum{0};

    for (int i = 0; i < 100; i++)
    {
        vec.push_back(rand() % 101);
    }

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << "\n";
    }
    
    std::cout << "Veuillez saisir un nombre entre 0 et 100 : ";
    std::cin >> target;

    pos = std::find(vec.begin(), vec.end(), target);

    // std::find & std::count

    if(pos != vec.end())
    {
        std::cout << "L'element est dans le tableau !";
        std::cout << "\nIl est prsent " << std::count(vec.begin(), vec.end(), target) << " fois.\n";
    }
    else
        std::cout << "L'element n'est pas dans le tableau.\n";
    
    // std::sort

    while(temp != "trier")
    {
        std::cout << "Entrez 'trier' pour trier le tableau : ";
        std::cin >> temp;
    }

    std::sort(vec.begin(), vec.end());

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << "\n";
    }

    // std::accumulate

    while(temp != "addition")
    {
        std::cout << "Entrez 'addition' pour additionner les elements du tableau : ";
        std::cin >> temp;
    }

    std::cout << "La somme fait : " << std::accumulate(vec.begin(), vec.end(), sum);

    // Ex 2

    std::string str = "pen pineapple apple pen";

    std::cout << "\nle premier mot de " << std::quoted(str) << " a " << firstWord(str) << " lettres.\n";

    std::vector<std::string> split = split_string(str);

    std::cout << "La chaine de caracteres splitee : \n"; 

    for (auto it = split.begin(); it != split.end(); ++it)
    {
        std::cout << *it << "\n";
    }
}