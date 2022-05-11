
#include <iostream>
#include <fstream>
#include <sstream>
#include "App.hpp"
#include "Fruit.hpp"
#include "Alcohol.hpp"
#include "Logger.hpp"

App::App(Bartender *bartender, Logger l) {
    pBartender=bartender;
    log = l;
}

App::~App() {}

void App::Run() {


    int com = -1;
    while (com != 0){

        std::cout << "1. List \n";
        std::cout << "2. Add New Recipe \n";
        std::cout << "3. Remove Recipe \n";
        std::cout << "4. Rename Recipe \n";
        std::cout << "5. Choose Recipe \n";
        std::cout << "6. Save \n";
        std::cout << "7. Load \n";
        std::cout << "0. Close \n\n";

        std::cin >> com;

        switch (com) {

            case 1: pBartender->printKnowledge();                   /// 1 List
                std::cout << "\n";
                break;
            case 2:{                                                /// 2 Add Recipe
                std::string name;
                std::cout << "Name: \n";
                std::cin >> name;
                Recipe* buffer = new Recipe(name);

                while(name!="0"){

                    std::cout << "Name:( close = 0 ) \n";
                    std::cin >> name;
                    if(name == "0")
                        break;

                    double val;
                    std::cout << "Value:  \n";
                    std::cin >> val;

                    std::string type;
                    std::cout << "Type of Value: \n";
                    std::cin >> type;

                    double alc;
                    std::cout << "If it's not Alcohol then it's 0 \n";
                    std::cout << "Alcohol Persentage: \n";
                    std::cin >> alc;

                    if(alc == 0){
                        Fruit* ing = new Fruit(name,Amount(val,type));
                        buffer->add(ing);
                    }else{
                        Alcohol* ing = new Alcohol(name,Amount(val,type),alc);
                        buffer->add(ing);
                    }

                }

                pBartender->learn(buffer);

                log.begin("New Recipe");
                log.addRecipe(*pBartender);
                log.end();
                break;
            }
            case 3:{                                               /// 3 Remove Recipe
                int i;
                pBartender->printKnowledge();
                std::cin >> i;
                if(i<1 || pBartender->getDB()<i){
                    std::cout << " There's no such index. \n";
                    break;
                }
                log.begin("Remove");
                log.remRecipe(*pBartender->at(i));
                pBartender->forget(i);
                log.showRecipes(*pBartender);
                log.end();
                break;
            }
            case 4: {                                             /// 4 Rename Recipe
                int i;
                pBartender->printKnowledge();
                std::cin >> i;

                if(i<1 || pBartender->getDB()<i){
                    std::cout << " There's no such index. \n";
                    break;
                }

                std::string name;
                std::cout << "New Name: \n";
                std::cin >> name;

                log.begin("Name Change");
                log.showRecipeName(*pBartender->at(i));
                pBartender->at(i)->modName(name);
                log.showRecipeName(*pBartender->at(i));
                log.end();

                break;
            }
            case 5: {                                                ///5 Choose Recipe to modify
                pBartender->printKnowledge();
                std::cin >> com;
                if(com<1 || pBartender->getDB()<com){
                    std::cout << " There's no such index. \n";
                    break;
                }

                log.begin("Chosen");
                log.showRecipe(*pBartender->at(com));
                log.end();
                int inCom = -1;
                while (inCom != 0) {
                    std::cout << "1. Add Ingredients \n";
                    std::cout << "2. Remove Ingredients \n";
                    std::cout << "0. Close \n";

                    std::cin >> inCom;

                    switch (inCom) {
                        case 1: {                                       ///5.1 Add Ingredient
                            std::string name;

                            std::cout << "Name:( close = 0 ) \n";
                            std::cin >> name;
                            if(name == "0")
                                break;

                            double val;
                            std::cout << "Value:  \n";
                            std::cin >> val;

                            std::string type;
                            std::cout << "Type of Value: \n";
                            std::cin >> type;

                            double alc;
                            std::cout << "If it's not Alcohol then it's 0 \n";    // if alcohol percentage 0
                            std::cout << "Alcohol Persentage: \n";                // then it fruit
                            std::cin >> alc;

                            if(alc == 0){
                                Fruit* ing = new Fruit(name,Amount(val,type));
                                pBartender->at(com)->add(ing);
                            }else{
                                Alcohol* ing = new Alcohol(name,Amount(val,type),alc);
                                pBartender->at(com)->add(ing);
                            }

                            log.begin("New Ingredient");
                            log.addIngredient(*pBartender->at(com));
                            log.end();
                            break;
                        }
                        case 2: {                                                   ///5.2 Remove Ingredient
                            int i;
                            pBartender->at(com)->list();
                            std::cin >> i;

                            if(i<1 || pBartender->at(com)->getVec().size()<i){
                                std::cout << " There's no such index. \n";
                                break;
                            }

                            log.begin("Remove Ingredient");
                            log.remIngredient(*pBartender->at(com)->at(i));
                            pBartender->at(com)->remove(i);
                            log.showIngredients(*pBartender->at(com));
                            log.end();
                            break;
                        }
                        case 0:
                            std::cout << "0. Close \n";
                            break;
                        default:
                            break;
                    }
                }
                break;
                com=-1;
            }
            case 6:{                                 /// 6 Save
                std::string fn;
                std::cout << "Save(Teszt.txt)\n";
                std::cin >> fn;

                this->Save(fn);


                break;
            }
            case 7:{                                  /// 7 Load
                std::string fn;
                std::cout << "Load(Teszt.txt)\n";
                std::cin >> fn;

                this->Load(fn);


                break;
            }
            default:
                break;
        }
    }

}

void App::Save(std::string filename) {
    std::ofstream file;
    file.open(filename);
    int db = pBartender->getDB();
    file << db << "\n";

    for(int i = 0 ; i < db ; i++){
        std::cout << db;
        pBartender->at(i+1)->saveRecipe(file);
    }
}

void App::Load(std::string filename) {
    std::ifstream file;
    file.open(filename);

    std::string line;
    getline(file, line);
    int db = std::stoi(line);
    for(int i=0 ; i < db ; i++){
        getline(file, line);

        std::string token;
        std::string dm =",";                       // separator string
        int pos = line.find(dm);                   //find this pos of  the separator
        token = line.substr(0,pos);           // new string 0 to pos
        line.erase(0, pos + dm.length());  // delete string part to pos
        int l = std::stoi(line);

        Recipe* b = new Recipe(token);
        Ingredients* buff;
        for(int x=0;x<l;x++){
            int d = 0;
            getline(file, line);

            pos = line.find(dm);
            token = line.substr(0,pos);
            std::string name = token;
            line.erase(0, pos + dm.length());

            pos = line.find(dm);
            token = line.substr(0,pos);
            double val = std::stod(token);
            line.erase(0, pos + dm.length());

            pos = line.find(dm);
            if(pos == std::string::npos){
                buff = new Fruit(name,Amount(val,line));
            }else{
                token = line.substr(0,pos);
                std::string type = token;
                line.erase(0, pos + dm.length());
                double alc = std::stod(line);
                buff = new Alcohol(name,Amount(val,type),alc);

            }
            b->add(buff);
        }
        pBartender->learn(b);
    }

}
