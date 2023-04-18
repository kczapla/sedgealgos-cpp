#include "sedgealgos/data_structures/array/array.hpp"
#include "sedgealgos/data_structures/queue/random_queue.hpp"
#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/random/std_random.hpp"

#include <ostream>
#include <string>
#include <sstream>

using namespace sedgealgos::data_structures::array;
using namespace sedgealgos::data_structures::queue;
using namespace sedgealgos::io;

enum class Rank {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

std::ostream& operator<<(std::ostream& os, Rank const r) {
    switch(r) {
        case Rank::TWO:
            os << "two";
            break;
        case Rank::THREE:
            os << "three";
            break;
        case Rank::FOUR:
            os << "four";
            break;
        case Rank::FIVE:
            os << "five";
            break;
        case Rank::SIX:
            os << "six";
            break;
        case Rank::SEVEN:
            os << "seven";
            break;
        case Rank::EIGHT:
            os << "eight";
            break;
        case Rank::NINE:
            os << "nine";
            break;
        case Rank::TEN:
            os << "ten";
            break;
        case Rank::JACK:
            os << "jack";
            break;
        case Rank::QUEEN:
            os << "queen";
            break;
        case Rank::KING:
            os << "king";
            break;
        case Rank::ACE:
            os << "ace";
            break;
        default:
            break;
    }

    return os;
}

enum class Pip {
    HEART,
    TILES,
    CLOVERS,
    PIKES
};

std::ostream& operator<<(std::ostream& os, Pip const p) {
    switch(p) {
        case Pip::HEART:
            os << "heart";
            break;
        case Pip::TILES:
            os << "tiles";
            break;
        case Pip::CLOVERS:
            os << "clovers";
            break;
        case Pip::PIKES:
            os << "pikes";
            break;
        default:
            break;
    }

    return os;
}

enum class Color {
    RED,
    BLACK
};

class Card {
public:
    Card() = default;

    Card(Pip p, Rank r) : pip{p}, rank{r} {}

    std::string string() const {
        std::stringstream ss;

        ss << "{ " << pip << ", " << rank << " }";

        return ss.str();
    }

private:
    Pip pip;
    Rank rank;
};

using Deck = sedgealgos::data_structures::queue::RandomQueue<Card, sedgealgos::random::StdRandom>;

Deck prepareDeck() {
    Deck deck;

    Array<Pip> pips;
    pips.push_back(Pip::CLOVERS);
    pips.push_back(Pip::HEART);
    pips.push_back(Pip::PIKES);
    pips.push_back(Pip::TILES);

    Array<Rank> ranks;
    ranks.push_back(Rank::TWO);
    ranks.push_back(Rank::THREE);
    ranks.push_back(Rank::FOUR);
    ranks.push_back(Rank::FIVE);
    ranks.push_back(Rank::SIX);
    ranks.push_back(Rank::SEVEN);
    ranks.push_back(Rank::EIGHT);
    ranks.push_back(Rank::NINE);
    ranks.push_back(Rank::TEN);
    ranks.push_back(Rank::JACK);
    ranks.push_back(Rank::QUEEN);
    ranks.push_back(Rank::KING);
    ranks.push_back(Rank::ACE);

    for (auto p : pips) {
        for (auto r : ranks) {
            deck.enqueue(Card{p, r});
        }
    }

    return deck;
}

void printPlayerHand(Array<Card> const& hand, int player_no) {
    StdOut stdout;
    stdout.printf("player %d deck: ", player_no);
    for (auto c : hand) {
        stdout.printf("%s, ", c.string());
    }
    stdout.println("");
}

int main() {
    auto deck{prepareDeck()};

    Array<Card> player1;
    Array<Card> player2;
    Array<Card> player3;
    Array<Card> player4;
    while (!deck.is_empty()) {
        player1.push_back(deck.dequeue());
        player2.push_back(deck.dequeue());
        player3.push_back(deck.dequeue());
        player4.push_back(deck.dequeue());
    }

    printPlayerHand(player1, 1);
    printPlayerHand(player2, 2);
    printPlayerHand(player3, 3);
    printPlayerHand(player4, 4);

    return 0;
}
