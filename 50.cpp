#include <iostream>
#include <queue>

int main() {
    std::queue<int> player1, player2;

    for (int i = 0; i < 5; i++) {
        int card;
        std::cin >> card;
        player1.push(card);
    }

    for (int i = 0; i < 5; i++) {
        int card;
        std::cin >> card;
        player2.push(card);
    }

    int turns = 0;
    while (!player1.empty() && !player2.empty()) {
        int card1 = player1.front();
        player1.pop();
        int card2 = player2.front();
        player2.pop();

        if ((card1 == 0 && card2 == 9) || (card2 == 0 && card1 == 9)) {
            if ((card1 == 0 && card2 == 9)) {
                player1.push(card1);
                player1.push(card2);
            }
            else {
                player2.push(card1);
                player2.push(card2);
            }
        }
        else if (card1 > card2) {
            player1.push(card1);
            player1.push(card2);
        }
        else if (card2 > card1) {
            player2.push(card1);
            player2.push(card2);
        }

        turns++;
        if (turns > 1000000) {
            std::cout << "botva" << std::endl;
            return 0;
        }
    }
    if (player1.empty()) {
        std::cout << "second " << turns << std::endl;
    }
    else if (player2.empty()) {
        std::cout << "first " << turns << std::endl;
    }
    return 0;
}