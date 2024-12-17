#ifndef TAXINTERFACE_H
#define TAXINTERFACE_H

class TaxInterface {
public:
    virtual void printTax() const = 0;  // Чисто виртуальная функция
    virtual ~TaxInterface() = default;
};

#endif // TAXINTERFACE_H




