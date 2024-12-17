#include "PropertyTaxpayer.h"
#include <iostream>

PropertyTaxpayer::PropertyTaxpayer(const std::string& inn, int year, double propertyValue, double taxableIncome, double nontaxableIncome)
    : Taxpayer(inn, year, taxableIncome, nontaxableIncome), propertyValue(propertyValue), deductionAmount(0) {
    if (propertyValue < 0) {
        throw std::invalid_argument("Стоимость жилья не может быть отрицательной.");
    }
    calculateDeduction();
}

void PropertyTaxpayer::setPropertyValue(double value) {
    if (value < 0) {
        throw std::invalid_argument("Стоимость жилья не может быть отрицательной.");
    }
    propertyValue = value;
    calculateDeduction();
}

double PropertyTaxpayer::getPropertyValue() const {
    return propertyValue;
}

double PropertyTaxpayer::getDeductionAmount() const {
    return deductionAmount;
}

void PropertyTaxpayer::calculateDeduction() {
    const double maxDeductionBase = 2000000.0;
    double applicableValue = (propertyValue > maxDeductionBase) ? maxDeductionBase : propertyValue;
    deductionAmount = applicableValue * taxRate;
}

void PropertyTaxpayer::printInfo() const {
    Taxpayer::printInfo();
    std::cout << "Стоимость жилья: " << propertyValue << "\n"
        << "Сумма вычета: " << deductionAmount << "\n";
}

void PropertyTaxpayer::printTax() const {
    std::cout << "Налог с имущества: " << deductionAmount << std::endl;
}

PropertyTaxpayer::~PropertyTaxpayer() {}



