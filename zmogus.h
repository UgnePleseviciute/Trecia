#ifndef ZMOGUS_H_INCLUDED
#define ZMOGUS_H_INCLUDED

#define ZMOGUS_H

#include <iostream>
#include <string>

class Zmogus {
protected:
    std::string Vardas;
    std::string Pavarde;

public:
    Zmogus() : Vardas(""), Pavarde("") {}

    Zmogus(const std::string& vardas, const std::string& pavarde)
        : Vardas(vardas), Pavarde(pavarde) {}

    // Getters
    std::string getVardas() const { return Vardas; }
    std::string getPavarde() const { return Pavarde; }

    // Setters
    void setVardas(const std::string& newVardas) { Vardas = newVardas; }
    void setPavarde(const std::string& newPavarde) { Pavarde = newPavarde; }

    virtual void dosmth() const = 0;

    virtual ~Zmogus() = default;  // Virtual destructor for polymorphism
};

#endif // ZMOGUS_H_INCLUDED
