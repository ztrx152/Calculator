#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

// Функция для очистки ввода
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция для отображения меню
void displayMenu() {
    cout << "\n=== КАЛЬКУЛЯТОР ===" << endl;
    cout << "1. Сложение (+)" << endl;
    cout << "2. Вычитание (-)" << endl;
    cout << "3. Умножение (*)" << endl;
    cout << "4. Деление (/)" << endl;
    cout << "5. Возведение в степень (^)" << endl;
    cout << "6. Квадратный корень (√)" << endl;
    cout << "7. Выход" << endl;
    cout << "Выберите операцию: ";
}

// Функция для получения числа от пользователя
double getNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        if (cin >> number) {
            break;
        } else {
            cout << "Ошибка! Пожалуйста, введите число: ";
            clearInput();
        }
    }
    return number;
}

int main() {
    int choice;
    double num1, num2, result;
    
    cout << "Добро пожаловать в калькулятор!" << endl;
    
    while (true) {
        displayMenu();
        
        // Проверка корректности выбора операции
        if (!(cin >> choice)) {
            cout << "Ошибка! Пожалуйста, введите число от 1 до 7." << endl;
            clearInput();
            continue;
        }
        
        clearInput(); // Очистка буфера ввода
        
        switch (choice) {
            case 1: // Сложение
                num1 = getNumber("Введите первое число: ");
                num2 = getNumber("Введите второе число: ");
                result = num1 + num2;
                cout << "Результат: " << num1 << " + " << num2 << " = " << result << endl;
                break;
                
            case 2: // Вычитание
                num1 = getNumber("Введите первое число: ");
                num2 = getNumber("Введите второе число: ");
                result = num1 - num2;
                cout << "Результат: " << num1 << " - " << num2 << " = " << result << endl;
                break;
                
            case 3: // Умножение
                num1 = getNumber("Введите первое число: ");
                num2 = getNumber("Введите второе число: ");
                result = num1 * num2;
                cout << "Результат: " << num1 << " * " << num2 << " = " << result << endl;
                break;
                
            case 4: // Деление
                num1 = getNumber("Введите делимое: ");
                num2 = getNumber("Введите делитель: ");
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Результат: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Ошибка! Деление на ноль невозможно." << endl;
                }
                break;
                
            case 5: // Возведение в степень
                num1 = getNumber("Введите основание: ");
                num2 = getNumber("Введите показатель степени: ");
                result = pow(num1, num2);
                cout << "Результат: " << num1 << " ^ " << num2 << " = " << result << endl;
                break;
                
            case 6: // Квадратный корень
                num1 = getNumber("Введите число: ");
                if (num1 >= 0) {
                    result = sqrt(num1);
                    cout << "Результат: √" << num1 << " = " << result << endl;
                } else {
                    cout << "Ошибка! Невозможно извлечь корень из отрицательного числа." << endl;
                }
                break;
                
            case 7: // Выход
                cout << "Спасибо за использование калькулятора! До свидания!" << endl;
                return 0;
                
            default:
                cout << "Неверный выбор! Пожалуйста, выберите операцию от 1 до 7." << endl;
                break;
        }
        
        // Пауза перед следующим действием
        cout << "\nНажмите Enter для продолжения...";
        cin.get();
    }
    
    return 0;
}
