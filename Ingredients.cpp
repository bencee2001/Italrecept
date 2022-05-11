
#include <iostream>
#include "Ingredients.hpp"

Ingredients::Ingredients(std::string n, Amount amount) : amount(amount), name(n) {}

Ingredients::~Ingredients() {}

void Ingredients::print() {
    std::cout<< "Name: " + name
                + "\t Amount: " + std::to_string(amount.value) + " " + amount.type;
}


Ingredients::Ingredients(const Ingredients &ing) {
    this->name = ing.name;
    this->amount = ing.amount;
}

Amount::Amount(double v, std::string t) {
    this->value=v;
    this->type=t;
}

Amount::Amount(){}

