#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> setOfStrings;
    char operation;
    std::string input;

    while (true) {
        std::cin >> operation;  // Считываем тип операции

        if (operation == '#') {
            break;  // Если встречен символ #, завершаем ввод операций
        }

        std::cin >> input;  // Считываем строку для операции

        if (operation == '+') {
            setOfStrings.insert(input);  // Добавляем строку в множество
        }
        else if (operation == '-') {
            setOfStrings.erase(input);  // Удаляем строку из множества
        }
        else if (operation == '?') {
            // Проверяем наличие строки в множестве и выводим соответствующее сообщение
            if (setOfStrings.find(input) != setOfStrings.end()) {
                std::cout << "YES\n";
            }
            else {
                std::cout << "NO\n";
            }
        }
    }

    return 0;
}