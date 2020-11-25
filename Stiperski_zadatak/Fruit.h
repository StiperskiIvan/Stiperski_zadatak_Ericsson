#pragma once
#include<sstream>

class Fruit
{
public:
    Fruit(std::string x, std::string y, std::string z); //declaration of Fruit constructor
    std::string name;
    std::string weight;
    std::string price;
    
    std::string printFruit(); //declaration of printFruit function
    std::string printAllFruit(); // declaration of printAllFruit function
};

