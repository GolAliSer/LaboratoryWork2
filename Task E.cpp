﻿#include <iostream>
#include <stack>
#include <sstream>

int PostfixExample(const std::string &example) {
    std::stack<int> stack; //создаем стек, так как пример считывается с конца
    std::istringstream is(example); //разделяем пример на отдельные элементы
    std::string token; //создаем строку для проверки элементов примера

    while (is >> token) { //цикл, где будем поверять каждый элемент, пока строка не закончится
        if (token == "+") { //если проверяемый элемент +
            int number2 = stack.top(); //из стека берем верхнее число, это будем первое искомое число, ближайшее к +
            stack.pop(); //убираем верхнее число, после сохранения значения
            int number1 = stack.top(); //из стека берем новое верхнее число, это будем второе искомое число, ближайшее к предыдущему искомому
            stack.pop(); //убираем верхнее число, после сохранения значения
            stack.push(number1 + number2); //добавляем в стэк новое число
        }
        else if (token == "-") { //если проверяемый элемент -
            int number2 = stack.top(); //из стека берем верхнее число, это будем первое искомое число, ближайшее к -
            stack.pop(); //убираем верхнее число, после сохранения значения
            int number1 = stack.top(); //из стека берем новое верхнее число, это будем второе искомое число, ближайшее к предыдущему искомому
            stack.pop(); //убираем верхнее число, после сохранения значения
            stack.push(number1 - number2); //добавляем в стэк новое число
        }
        else if (token == "*") { //если проверяемый элемент *
            int number2 = stack.top(); //из стека берем верхнее число, это будем первое искомое число, ближайшее к *
            stack.pop(); //убираем верхнее число, после сохранения значения
            int number1 = stack.top(); //из стека берем новое верхнее число, это будем второе искомое число, ближайшее к предыдущему искомому
            stack.pop(); //убираем верхнее число, после сохранения значения
            stack.push(number1 * number2); //добавляем в стэк новое число
        }
        else { //если проверяемый элемент не является действием (число)
            stack.push(std::stoi(token)); //преобразовываем строчный вариант числа в числовой тип данных для дальнейшего подсчета
        }
    }
    return stack.top(); //возвращаем оставшееся число после перебора
}

int main() {

    std::string example; //переменная строки примера
    std::getline(std::cin, example); //вводим строку, getline закончит при /n, переносе строки

    int result = PostfixExample(example); //используем функцию
    std::cout << result << std::endl; //выводим результат

    return 0;
}
