#ifndef TAXCALCULATOR_H
#define TAXCALCULATOR_H

#include <iostream>
#include <iomanip>
#include <type_traits>

template <typename T>
class TaxCalculator {
private:
    T income;
    T taxRate;

public:
    static const T TAX_RATE;

    TaxCalculator(T income) : income(income), taxRate(TAX_RATE) {}

    T calculateTax() const {
        return income * taxRate / 100;
    }

    void printTax() const {
        if constexpr (std::is_integral<T>::value) {
            std::cout << "Налог (без копеек): " << calculateTax() << " руб." << std::endl;
        }
        else {
            std::cout << "Налог (с копейками): " << std::fixed << std::setprecision(2) << calculateTax() << " руб." << std::endl;
        }
    }
};

template <typename T>
const T TaxCalculator<T>::TAX_RATE = 13;  // 13%

#endif // TAXCALCULATOR_H

