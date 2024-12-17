#include "Taxpayer.h"
#include "PropertyTaxpayer.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    int recordCount;

    std::cout << "Введите количество записей: ";
    std::cin >> recordCount;

    std::vector<Taxpayer*> taxpayers;

    for (int i = 0; i < recordCount; ++i) {
        std::string inn;
        int year;
        double taxableIncome, nontaxableIncome, propertyValue;

        std::cout << "\nЗапись #" << i + 1 << ":\n";

        std::cout << "Введите ИНН (12 цифр): ";
        std::cin >> inn;

        std::cout << "Введите год расчета: ";
        std::cin >> year;

        std::cout << "Введите налогооблагаемый доход (0, если отсутствует): ";
        std::cin >> taxableIncome;

        std::cout << "Введите неналогооблагаемый доход (0, если отсутствует): ";
        std::cin >> nontaxableIncome;

        std::cout << "Введите стоимость жилья (0, если отсутствует): ";
        std::cin >> propertyValue;

        try {
            Taxpayer* taxpayer = nullptr;
            if (propertyValue > 0) {
                taxpayer = new PropertyTaxpayer(inn, year, propertyValue, taxableIncome, nontaxableIncome);
            }
            else {
                taxpayer = new Taxpayer(inn, year, taxableIncome, nontaxableIncome);
            }

            char addMore = 'y';
            while (addMore == 'y' || addMore == 'Y') {
                std::cin >> *taxpayer;
                std::cout << "Добавить еще доход? (y/n): ";
                std::cin >> addMore;
            }

            taxpayers.push_back(taxpayer);

        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
        }
    }

    double totalTaxSum = 0.0;
    for (const auto* taxpayer : taxpayers) {
        totalTaxSum += taxpayer->getTotalTax();
    }

    for (size_t i = 0; i < taxpayers.size(); ++i) {
        std::cout << "\n--- Информация о налогоплательщике #" << i + 1 << " ---\n";
        taxpayers[i]->printInfo();
        taxpayers[i]->printTax();  // Выводим налог, который не подлежит возврату
    }

    std::cout << "\nОбщий налог от всех налогоплательщиков: " << totalTaxSum << "\n";

    for (auto* taxpayer : taxpayers) {
        delete taxpayer;
    }

    return 0;
}






