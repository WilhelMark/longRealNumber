#include <iostream>
#include <string>

// Функция проверяет, является ли строка корректной записью вещественного числа
bool isCorrectFloat(const std::string &str)
{
    // Позиция десятичной точки
    int dotPosition = -1;

    // Проверяем первый символ
    if (str.empty() || (str[0] != '-' && str[0] != '.' && !isdigit(str[0])))
    {
        return false; // Первый символ должен быть цифрой, точкой или знаком минус
    }

    // Проверяем наличие знака минус
    bool hasMinus = false;
    if (str[0] == '-')
    {
        hasMinus = true;
        if (str.length() == 1)
        {
            return false; // Знак минус не должен быть единственным символом
        }
    }

    // Проверяем остальную часть строки
    bool hasDigitBeforeDot = false;
    bool hasDigitAfterDot = false;

    for (size_t i = (hasMinus ? 1 : 0); i < str.length(); ++i)
    {
        char c = str[i];

        // Проверка десятичной точки
        if (c == '.')
        {
            if (dotPosition != -1)
            {
                return false; // Десятичная точка может быть только одна
            }
            dotPosition = i;
            continue;
        }

        // Проверка цифр
        if (!isdigit(c))
        {
            return false; // Все символы должны быть цифрами или точкой
        }

        // Проверка цифр до и после точки
        if (dotPosition == -1)
        {
            hasDigitBeforeDot = true;
        }
        else
        {
            hasDigitAfterDot = true;
        }
    }

    // Должна быть хотя бы одна цифра
    if (!hasDigitBeforeDot && !hasDigitAfterDot)
    {
        return false;
    }

    return true;
}

int main()
{
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    if (isCorrectFloat(input))
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
