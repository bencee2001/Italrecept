
#include <iostream>
#include <fstream>
#include "Alcohol.hpp"


Alcohol::Alcohol(std::string n1, Amount amount, double alcP=15.5)
        : Ingredients(n1, amount) , AlcoholPercentage(alcP){}

void Alcohol::print() {
    Ingredients::print();    // call the base class function
    std::cout << "\t Alcohol Percentage: " + std::to_string(AlcoholPercentage) + "%\n";
}

Alcohol::~Alcohol() {}

Alcohol *Alcohol::clone() {
    return new Alcohol(*this);
}

// initialization list call base constructor
Alcohol::Alcohol(const Alcohol &alc) : Ingredients(alc) {
    AlcoholPercentage = alc.AlcoholPercentage;
}

void Alcohol::saveIngred(std::ofstream& of) {
    of << name << "," << amount.value << "," << amount.type << "," << AlcoholPercentage << "\n";
}
