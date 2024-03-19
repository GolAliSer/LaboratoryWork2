#include <iostream>
#include <set>

int main() {
    int N;
    std::cin >> N;

    std::set<int> numbers;
    for (int i = 0; i < N; ++i) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    int uniqueCount = numbers.size();
    std::cout << uniqueCount << std::endl;

    return 0;
}