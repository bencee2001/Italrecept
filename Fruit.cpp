
#include <iostream>
#include <fstream>
#include "Fruit.hpp"

Fruit::Fruit(std::string n, Amount am):Ingredients(n,am) {} // call base constructor

Fruit::~Fruit() {}

void Fruit::print() {
    Ingredients::print();   // cal base class function
    std::cout << "\n" ;
}

Fruit::Fruit(const Fruit &f):Ingredients(f) {}

Fruit *Fruit::clone() {
    return new Fruit(*this);
}

void Fruit::saveIngred(std::ofstream &of) {
    of << name << "," << amount.value << "," << amount.type << "\n";
}
