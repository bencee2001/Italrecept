
#include <iostream>
#include "Bartender.hpp"

Bartender::Bartender() {
    cap = 5;
    knowledge = new Recipe*[cap];
    db = 0 ;
}

void Bartender::raiseArray() {

    cap = cap+5;
    Recipe** nw = new Recipe*[cap];   //buffer array
    for (int i=0;i<db;i++){
        nw[i] = this->knowledge[i];
    }

    delete [] knowledge;              //free the array
    knowledge = new Recipe*[cap];

    for (int i=0;i<db;i++){
        knowledge[i] = nw[i];
    }
}


void Bartender::learn(Recipe *r) {
    if(db==cap){               //if full
        raiseArray();
    }
    knowledge[db] = r;
    db++;
}

void Bartender::printKnowledge() {
    for(int i=0;i<db;i++){
        std::cout << std::to_string(i+1) + ". Recipe Name: " ;
        knowledge[i]->list();
    }
}

void Bartender::delArray() {
    for(int i=0;i<db;i++){          //delete the elements of the array
        delete knowledge[i];
    }
    delete [] knowledge;
}

Bartender::~Bartender() {
    delArray();
}

void Bartender::forget(int x) {
    x=x-1;
    Recipe** nw = new Recipe*[cap];
    int i =0;
    for(;i < x;i++){               // goes to the elemetns
        nw[i] = knowledge[i];
    }
    i++;                           //skip it
    for(;i<db;i++){
        nw[i-1] =knowledge[i];     // buffer without the element
    }

    delete [] knowledge;
    knowledge=new Recipe*[cap];

    db--;

    for(i=0;i<db;i++){
        knowledge[i] = nw[i];
    }
}

Recipe *Bartender::at(int i) {
    return knowledge[i-1];
}

int Bartender::getDB() const {
    return db;
}
