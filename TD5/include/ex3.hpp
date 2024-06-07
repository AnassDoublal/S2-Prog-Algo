#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <numeric>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const {
        return kind == other.kind && value == other.value;
    }

    size_t hash() const {
        return static_cast<size_t>(value) * 4 + static_cast<size_t>(kind);
    }
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(const Card& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size);

std::string card_name(Card const& card);

