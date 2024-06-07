#include <../include/ex1.hpp>
#include <../include/ex2.hpp>
#include <../include/ex3.hpp>

int main()
{
    // Ex 1
    std::cout << "\nEx 1\n\n";
    
    std::string str{"abc"};
    std::string str1{"cba"};
    std::string str2{"bac"};

    std::cout << "Folding : " << folding_string_hash(str, 1024) << "\n";
    std::cout << "Folding ordered : " << folding_string_ordered_hash(str1, 1024) << "\n";
    std::cout << "Polynomial : " << polynomial_rolling_hash(str2, 127, 200000) << "\n";

    // Ex 2
    std::cout << "\nEx 2\n\n";

    size_t num_repairs = 100;
    std::vector<std::pair<std::string, float>> repairs = get_robots_fix(num_repairs);

    std::unordered_map<std::string, std::vector<float>> fixes_map = robots_fixes_map(repairs);

    for (const auto& pair : fixes_map) {
        const std::string& robot_name = pair.first;
        const std::vector<float>& costs = pair.second;
        float total_cost = sum_vector(costs);
        std::cout << "Robot " << robot_name << " a un cout total de reparation de : " << total_cost << "\n";
    }

    // Ex 3
    std::cout << "\nEx 3\n\n";

    std::vector<Card> cards = get_cards(100);

    std::unordered_map<Card, int> card_counts;

    for (const auto& card : cards) {
        ++card_counts[card];
    }

    for (const auto& pair : card_counts) {
        std::cout << card_name(pair.first) << " : " << pair.second << " fois" << "\n";
    }
}