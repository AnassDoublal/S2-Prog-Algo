#include <../include/ex1.hpp>

size_t folding_string_hash(std::string const& s, size_t max)
{
    size_t sum{0};

    for (size_t i = 0; i < s.size(); i++)
    {
        sum += s[i];
    }

    return sum % max;
}

size_t folding_string_ordered_hash(std::string const& s, size_t max)
{
    size_t sum{0};

    for (size_t i = 0; i < s.size(); i++)
    {
        sum += s[i] * i;
    }

    return sum % max;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m)
{
    size_t sum{0};
    size_t pVal{p};

    int power{1};

    for (size_t i = 0; i < s.size(); i++)
    {           
        sum += s[i] * power % m;

        power *= p;
    }
    
    return sum % m;
}