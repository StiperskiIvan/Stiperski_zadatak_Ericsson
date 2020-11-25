#include "Fruit.h"

// definition of Fruit constructor
Fruit::Fruit(std::string x, std::string y, std::string z) 
{
    name = x;
    weight = y;
    price = z;
}
// definition of printFruit function that returns formated string for printing one fruit
std::string Fruit::printFruit() 
{
    return "\nName\t: " + name + "\nPrice\t: " + price + "kn" + "\nWeight\t: " + weight + "kg";
}
// definition of printAllFruit function that returns formated string for printing all fruits
std::string Fruit::printAllFruit()
{
    return name + "- " + price + "kn, " + weight + "kg";
}

