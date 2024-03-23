#include <iostream>
#include <stack>
#include <string>

// Функция для определения, является ли данная скобочная последовательность правильной
bool isBalanced(const std::string& sequence) {
    std::stack<char> stack;

    // Проходим по каждому символу в скобочной последовательности
    for (char bracket : sequence) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stack.push(bracket);  // Если встречаем открывающую скобку, помещаем ее в стек
        }
        else {
            if (stack.empty()) {
                return false;  // Если стек пустой и встречаем закрывающую скобку, последовательность неправильная
            }

            char top = stack.top();
            if ((top == '(' && bracket == ')') || (top == '[' && bracket == ']') || (top == '{' && bracket == '}')) {
                stack.pop();  // Если текущая закрывающая скобка соответствует последней открывающей, удаляем ее из стека
            }
            else {
                return false;  // Иначе последовательность неправильная
            }
        }
    }

    return stack.empty();  // После прохода по всем скобкам стек должен быть пустым
}

int main() {
    std::string sequence;
    std::cin >> sequence;

    if (isBalanced(sequence)) {
        std::cout << "yes\n";  // Скобочная последовательность правильная
    }
    else {
        std::cout << "no\n";  // Скобочная последовательность неправильная
    }

    return 0;
}
