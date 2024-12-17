#ifndef PROPERTYTAXPAYER_H
#define PROPERTYTAXPAYER_H

#include "Taxpayer.h"

class PropertyTaxpayer : public Taxpayer {
private:
    double propertyValue;
    double deductionAmount;

    void calculateDeduction();

public:
    PropertyTaxpayer(const std::string& inn, int year, double propertyValue, double taxableIncome = 0, double nontaxableIncome = 0);

    void setPropertyValue(double value);
    double getPropertyValue() const;
    double getDeductionAmount() const;
    void printInfo() const override;

    // Переопределение метода printTax для вывода налога на недвижимость
    void printTax() const override;

    ~PropertyTaxpayer() override;
};

#endif // PROPERTYTAXPAYER_H


