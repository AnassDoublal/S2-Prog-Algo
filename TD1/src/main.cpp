#include <vector>
#include <algorithm>

#include <fraction.hpp>

int main()
{
    Fraction f1{1, 3};
    Fraction f2{1, 2};

    Fraction plus{f1+f2};
    Fraction moins{f1-f2};
    Fraction fois{f1*f2};
    Fraction diviser{f1/f2};

    bool egal{f1==f2};
    bool different{f1!=f2};

    bool inferieur{f1<f2};
    bool inferieur_ou_egal{f1<=f2};
    bool superieur{f1>f2};
    bool superieur_ou_egal{f1>=f2};

    float d1 {static_cast<float>(f1)};

    std::cout << f1 << " + " << f2 << " = " << plus << "\n";
    std::cout << f1 << " - " << f2 << " = " << moins << "\n";
    std::cout << f1 << " * " << f2 << " = " << fois << "\n";
    std::cout << f1 << " / " << f2 << " = " << diviser << "\n";

    std::cout << f1 << " == " << f2 << " : " << egal << "\n";
    std::cout << f1 << " != " << f2 << " : " << different << "\n";

    std::cout << f1 << " < " << f2 << " : " << inferieur << "\n";
    std::cout << f1 << " <= " << f2 << " : " << inferieur_ou_egal << "\n";
    std::cout << f1 << " > " << f2 << " : " << superieur << "\n";
    std::cout << f1 << " >= " << f2 << " : " << superieur_ou_egal << "\n";

    std::cout << f1 <<  " en float : " << d1 << "\n";

    return 0;
}