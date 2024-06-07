#include <../include/ex3.hpp>

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    } else if (card_value == 10) {
        name += "10";
    } else if (card_value == 11) {
        name += 'V';
    } else if (card_value == 12) {
        name += 'Q';
    } else if (card_value == 13) {
        name += 'K';
    } else if (card_value == 14) {
        name += 'A';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    } else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    } else if (card.kind == CardKind::Club) {
        name += "Club";
    } else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}