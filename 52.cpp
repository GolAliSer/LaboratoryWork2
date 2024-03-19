#include <iostream>
#include <stack>
#include <sstream>

int PostfixExample(const std::string &example) {
    std::stack<int> stack;
    std::istringstream is(example);
    std::string token;

    while (is >> token) {
        if (token == "+") {
            int number2 = stack.top();
            stack.pop();
            int number1 = stack.top();
            stack.pop();
            stack.push(number1 + number2);
        }
        else if (token == "-") {
            int number2 = stack.top();
            stack.pop();
            int number1 = stack.top();
            stack.pop();
            stack.push(number1 - number2);
        }
        else if (token == "*") {
            int number2 = stack.top();
            stack.pop();
            int number1 = stack.top();
            stack.pop();
            stack.push(number1 * number2);
        }
        else {
            stack.push(std::stoi(token));
        }
    }
    return stack.top();
}

int main() {

    std::string example;
    std::getline(std::cin, example);

    int result = PostfixExample(example);
    std::cout << result << std::endl;

    return 0;
}