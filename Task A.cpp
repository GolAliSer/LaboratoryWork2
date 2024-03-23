#include <iostream>
#include <set> 

int main() {
    int N; //переменная для количества чисел
    std::cin >> N; //вводим количество чисел

    std::set<int> numbers; //создаем множество чисел
    for (int i = 0; i < N; ++i) { //через цикл заполняем числами контейнер
        int num;
        std::cin >> num;
        numbers.insert(num); //добавляем введенное число в контейнер
    }

    int uniqueCount = numbers.size(); //так как set хранит каждый элемент лишь в одном экземпляре, размер коллекции будет равен количеству разных элементов, так как все дубликаты не добавляются в set
    std::cout << uniqueCount << std::endl;

    return 0;
}
