#include <iostream>
#include <regex> // Подключаем библиотеку для работы с регулярными выражениями
#include <string>

int main() {
    std::string input; // Переменная для хранения пользовательского ввода
    std::cout << "Enter a string: "; // Запрашиваем ввод у пользователя
    std::getline(std::cin, input); // Считываем строку

    // Регулярное выражение для проверки корректности вещественного числа
    std::regex float_regex(R"(^[-]?(\d*\.\d+|\d+\.\d*|\d+|\.\d+)$)");

    // Проверяем соответствие строки регулярному выражению
    if (std::regex_match(input, float_regex)) {
        std::cout << "Yes\n"; // Если строка соответствует формату, выводим Yes
    } else {
        std::cout << "No\n"; // В противном случае выводим No
    }

    return 0;
}
