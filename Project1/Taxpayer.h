#ifndef TAXPAYER_H
#define TAXPAYER_H

#include <iostream>
#include <string>
#include "TaxInterface.h"  // Подключаем интерфейс

class Taxpayer : public TaxInterface {  // Наследуем от интерфейса
protected:
    std::string inn;
    int year;
    double taxableIncome;
    double nontaxableIncome;
    double totalTax;
    double totalIncome;
    const double taxRate;

    void validateYear(int year) const;
    void validateIncome(double income) const;
    void validateINN(const std::string& inn) const;

public:
    Taxpayer(const std::string& inn, int year);
    Taxpayer(const std::string& inn, int year, double taxableIncome, double nontaxableIncome = 0);
    virtual ~Taxpayer();
    Taxpayer(const Taxpayer& other);
    Taxpayer& operator=(const Taxpayer& other);

    void addIncome(double amount, bool isTaxable);
    void addIncome(double netIncomeAfterTax);
    virtual void printInfo() const;

    // Реализация метода интерфейса для вывода налогов
    void printTax() const override;

    const std::string& getINN() const;
    int getYear() const;
    double getTaxableIncome() const;
    double getNontaxableIncome() const;
    double getTotalTax() const;
    double getTotalIncome() const;
    double getTaxRate() const;

    friend std::istream& operator>>(std::istream& in, Taxpayer& taxpayer);
};

#endif // TAXPAYER_H



