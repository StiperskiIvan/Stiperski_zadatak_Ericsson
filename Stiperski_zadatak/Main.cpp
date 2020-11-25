// Stiperski_zadatak.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include "Fruit.h"

// Declaration of functions in the program
//std::vector <Fruit>& fruitList - reference for main <fruit> class vector so that it can be used and updated by all programs
//std::vector <std::string> &temper - reference for saved fruit favorites vector used to print out favorites
void inventoryControl(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void inventoryOverview(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void purchase(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void welcomeScreen(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void icrAdd(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void icrRem(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void icrCha(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void icrSort(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);
void buy(std::vector <Fruit>& fruitList, std::vector <std::string> &temper);


//Function to compare chars in a case insensitive way
bool compareChar(char& c1, char& c2)
{
    if (c1 == c2)
        return true;
    else if (toupper(c1) == toupper(c2))
        return true;
    return false;
}
//Function to compare strings in case Insensitive way
//Function calls the compareChar function
bool caseInSensStringCompare(std::string& str1, std::string& str2)
{
    return ((str1.size() == str2.size()) &&
        equal(str1.begin(), str1.end(), str2.begin(), &compareChar));
}
//function that returns string value of the name of a fruit object
//stored in favorite vector if needed
std::string fruitFavorite(std::vector <Fruit>& fruitList, std::string search)
{
    for (auto fruit : fruitList)
    {
        if (caseInSensStringCompare(fruit.name, search))
        {
            return fruit.name;
        }
    }
}
//Function that converts float to stream and round to 2 decimal points
std::string convertString(double s)
{ 
    double x = round((s) * 100.00) / 100.00;//rounds the value double to 2 decimals
    std::string y{};
    std::stringstream tem; //creates a stringstream tem
    tem << std::fixed << std::setprecision(2) << x; //adds value of double variable "s" to "tem" stringstream with with precision of 2 decimal points
    y=tem.str();//string variable that takes the value of stringstream "tem"
    return y;
}
//function that tests if user wants to do the same action again
std::string continueAgain()
{
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cout << "\nInput a number of your prefered option : ";
    std::string x{};
    std::cin >> x;
    return x;
}
//Function that clears the input cin and prints out an error, wrong input message
void testInputType() 
{
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "\nWrong type of input" << std::endl;
}
//function that lists out all of the current fruit
void listFruit(std::vector <Fruit> &fruitList) 
{
    std::cout << "\n";
    for (auto& fruit : fruitList) 
    {
        std::cout << fruit.printAllFruit() << std::endl;
    }
}
//User input number function
int insertNumber()
{
    std::string x{};                
    std::cin >> x;
    int intx{};
    while (true)
    {
        //if a string matches the numbers 1-5 it is converted to integer 
        //and forwarded to switchScreen function
        if (x == "1" || x == "2" || x == "3" || x == "4" || x == "5")
        {
            std::stringstream y{x}; // sets value of stringstream y with x
            y >> intx;         // the value of strinstream y is added to int intx variable 
            break;
        }

        //if it does not match to numbers 1 to 5 a new input is required
        else
        {
            testInputType(); // clear the buffer so that something doesnt interupt the next input
            std::cout << "\nInput a number of your prefered option : ";
            std::cin >> x;
        }
    }
    return intx;
}
// function that inputs the number of a prefered choise in the welcome screen and switches to the prefered Screen
void switchScreen(int x, std::vector <Fruit>& fruitList, std::vector <std::string> &temper)
{
    
    switch (x)
    {
    case 1:
        inventoryControl(fruitList,temper);
        break;
    case 2:
        inventoryOverview(fruitList, temper);
        break;
    case 3:
        purchase(fruitList, temper);
        break;
    case 4:
        std::cout << "\n\nGoodbye from the store!";
        break;
    default:
        std::cout << "\n\nSomething went wrong, please try again typing in an integer number from 1 to 4.\n\n";
        welcomeScreen(fruitList, temper);
        break;
    }
}
// Welcome screen - main navigation screen
void welcomeScreen(std::vector <Fruit>& fruitList, std::vector <std::string>& temper)
{
    std::cout << "&&&&& Welcome to Magic Garden Fruit Store! &&&&&\n\n"; //Welcome message
    std::cout << "1 - Inventory Control" << std::endl;
    std::cout << "2 - Inventory Overview" << std::endl;
    std::cout << "3 - Purchase" << std::endl;
    std::cout << "4 - Exit program\n\n";
    std::cout << "Input a number of your prefered option: ";
    int choseOption{ insertNumber() }; // Variable that saves the user input from function insertNumber()
    switchScreen(choseOption, fruitList, temper);
}
//function that switches windows between sub-screens of Inventory Control
void switchIcr(int x, std::vector <Fruit>& fruitList, std::vector <std::string>& temper)
{
    switch (x)
    {
    case 1:
        icrAdd(fruitList, temper);
        inventoryControl(fruitList, temper);
        break;
    case 2:
        icrRem(fruitList, temper);
        inventoryControl(fruitList, temper);
        break;
    case 3:
        icrCha(fruitList, temper);
        inventoryControl(fruitList, temper);
        break;
    case 4:
        icrSort(fruitList, temper);
        inventoryControl(fruitList, temper);
        break;
    case 5:
        welcomeScreen(fruitList, temper);
        break;
    default:
        std::cout << "\n\nPlease try again with inputs from 1 to 4. \n\n";
        inventoryControl(fruitList, temper);
        break;
    }
}
//Function that has an introduction message and info about inventory control
//and takes a user input to switch between sub-screens
void inventoryControl(std::vector <Fruit> & fruitList, std::vector <std::string>& temper)
{
        std::cout << "\n&&&&& Welcome to the Inventory Control! &&&&&\n\n"; 
        std::cout << "List of fruits currently in the inventory:"<< std::endl;
        listFruit(fruitList); //print out current fruit list
        std::cout << "\nYou have an option to..." << std::endl;
        std::cout << "\n1 - Add fruit" << std::endl;
        std::cout << "2 - Remove fruit" << std::endl;
        std::cout << "3 - Change Fruit" << std::endl;
        std::cout << "4 - Sort Fruit" << std::endl;
        std::cout << "5 - Back\n\n";
        std::cout << "Input a number of your prefered option: ";
        int choseOption{ insertNumber() }; // Int variable that saves the user input from function insertNumber()
        switchIcr(choseOption, fruitList, temper);
}
//Function to add new fruit objects to current vector and write it in vector fruitName in format name,price,weight 
void icrAdd(std::vector <Fruit> & fruitList, std::vector <std::string>& temper)
{
    while (true)
    {
        std::cout << "\nWhich fruit would you like to add?" << std::endl;
        std::cout << "\nEnter name, price and weigth bellow..." << std::endl;
        Fruit newFruit("", "", ""); //declare an empty Fruit object newFruit
        while (true)
        {
            bool i{ false };//declaration of marker to indicate if the input name is unique
            std::cout << "\nName: ";
            std::string n{};//string for name variable
            std::cin >> n;
            // convert every character of input to lowercase
            for (int k = 0; k < n.length(); ++k) 
            {
                n[k] = tolower(n[k]);
            }
            for (auto& fruit : fruitList)
            {
                if (caseInSensStringCompare(fruit.name,n))
                {
                    std::cout << "\nFruit name already exsists, try another name." << std::endl;
                    i = true;       
                }      
            }
            if (n.empty())   
                testInputType();// print out that the input is wrong type and clear input

            else if(i==false)
            {
                newFruit.name = n;
                break;
            }
        }

        while (true)
        {
            double p{};//string for price variable
            std::cout << "\nPrice [kn]: ";
            std::cin >> p;
            if (std::cin.fail() || p <= 0)//testing if input is double or lower or equal to 0
            {
                testInputType();// print out that the input is wrong type and clear input
                std::cout << "\nPlease try again..." << std::endl;
            }
            else
            {
                newFruit.price = convertString(p);//converts inserted double to string
                break;
            }
        }
        while (true)
        {
            double w{};//string for weigth variable
            std::cout << "\nWeight [kg]: ";
            std::cin >> w;
            if (std::cin.fail() || w < 0)//testing if input is double or lower then 0
            {
                testInputType(); // print out that the input is wrong type and clear input
                std::cout << "\nPlease try again..." << std::endl;
            }
            else
            {
                newFruit.weight = convertString(w); //converts inserted double to string 
                break;
            }
        }
        fruitList.push_back(newFruit); // inserts newfruit object in object Fruit vector at the last place
        std::cout << "\nUpdated fruit list..." << std::endl;
        listFruit(fruitList); // printing of the new fruit list updated
        std::cout << "\nWould you like to add another fruit?\n" << std::endl;
        std::string x{ continueAgain() }; //testing if the user would like to repeat the action
        if (x != "1")
            break;
    }
}
//Function to remove the current fruit from the list, user types the fruit name
//if match object is removed from the vector and updated list is printed
void icrRem(std::vector <Fruit> & fruitList, std::vector <std::string>& temper)
{
    while (true)
    {
        std::cout << "\nWhich fruit would you like to remove?" << std::endl;
        while (true)
        {
            bool i{ false }; //declaration of marker to indicate if the input name is unique
            int k{ 0 };
            std::cout << "\nEnter name: ";
            std::string n{};//string for name variable
            std::cin >> n;
            for (auto& fruit : fruitList)
            {
                if (caseInSensStringCompare(fruit.name, n))
                {
                    std::cout << fruit.printFruit() << std::endl;
                    fruitList.erase(fruitList.begin() + k);//erases the object from the fruitList <Fruit> vector
                    i = true;
                    break;
                }
                ++k;
            }
            if (i == true)          
                break;     
            else
                std::cout << "\nYour fruit was not found, maybe try searching another fruit." << std::endl;
        }
        std::cout << "\nUpdated fruit list..." << std::endl;
        listFruit(fruitList); // printing of the new fruit list updated
        std::cout << "\nWould you like to remove another fruit?\n" << std::endl;
        std::string x{ continueAgain() }; //testing if the user would like to repeat the action
        if (x != "1")
            break;

    }
}
//Function that allows you to change the fruit from the current list, type in fruit, if match allow to change attributes price and weight.
void icrCha(std::vector <Fruit> & fruitList, std::vector <std::string>& temper)
{
    while (true)
    {
        std::cout << "\nWhich fruit would you like to change?" << std::endl;
        while (true)
        {
            bool i{ false }; //declaration of marker to indicate if the input name is unique
            std::cout << "\nEnter name: ";
            std::string n{};//string for name variable
            std::cin >> n;
            for (auto& fruit : fruitList)
            {
                if (caseInSensStringCompare(fruit.name, n))
                {
                    while (true)
                    {
                        double p{};//string for price variable
                        std::cout << "\nEnter new price [kn]: ";
                        std::cin >> p;
                        if (std::cin.fail() || p <= 0)//testing if input is type double, lower or equal to 0
                        {
                            testInputType(); // print out that the input is wrong type and clear input
                            std::cout << "\nPlease try again..." << std::endl;
                        }
                        else
                        {
                            fruit.price = convertString(p);//converts inserted double to string
                            break;
                        }
                    }
                    while (true)
                    {
                        double w{};//string for weigth variable
                        std::cout << "\nEnter new weigth [kg]: ";
                        std::cin >> w;
                        if (std::cin.fail() || w < 0)//testing if input is double or lower then 0
                        {
                            testInputType();// print out that the input is wrong type and clear input
                            std::cout << "\nPlease try again..." << std::endl;
                        }
                        else
                        {
                            fruit.weight = convertString(w);//converts inserted double to string
                            break;
                        }
                    }
                    i = true; //Succesfull new entry bool i = true;
                    std::cout << "\nUpdated fruit..." << std::endl;
                    std::cout << fruit.printFruit() << std::endl;
                    break;
                }
            }
            if (i == true)
                break;
            else
                std::cout << "\nYour fruit was not found, maybe try searching another fruit." << std::endl;
        }
        std::cout << "\nWould you like to change another fruit?\n" << std::endl;
        std::string x{ continueAgain() }; //testing if the user would like to repeat the action
        if (x != "1")
            break;
    }
}
//Function that sorts in ascending and descending order a touple filled with data from fruitList object vector
//prints out sorted lists
void icrSort(std::vector <Fruit> & fruitList, std::vector <std::string>& temper)
{
    while (true)
    {
        std::cout << "\nHow would you like to sort the list?\n" << std::endl;
        std::cout << "1 - By name from A to Z\n2 - By name from Z to A"<<std::endl;
        std::cout << "3 - From High price to Low price\n4 - From Low price to High price" << std::endl;

        while (true)
        {
            std::cout << "\nInput a number of your prefered option : ";
            std::string x{};
            std::cin >> x;
            //making tuple vector to temporary hold the values of list
            //filling the tuple with name and converted values in double from string from price and weigth
            std::vector<std::tuple<std::string, double, double>> temp{}; 
            //for loop to add values from string object vector fruitList to tuple <strin,double,double>
            for (auto& fruit : fruitList)
            {
                double prKn{ stod(fruit.price) }; //converts string to double
                double weKg{ stod(fruit.weight) };//converts string to double 
                temp.push_back({ fruit.name,prKn,weKg });
            }
            
            if (x == "1")
            {
                //Sort the tuple by the [0] element in ascending oreder 
                //lambda expresion - make a function creation inside the sort command
                //creates two constant tuples and tests each [0] element to sort the list
                sort(temp.begin(), temp.end(), [](const std::tuple<std::string, double, double>& left, const std::tuple<std::string, double, double>& right)
                    { return(std::get<0>(left) < std::get<0>(right)); });
                std::cout << "\nSorted list from A to Z:\n" << std::endl;
                //print out the sorted tuple 
                for (int i = 0; i < temp.size(); ++i)
                {
                    std::cout << std::get<0>(temp[i]) << "- " << std::get<1>(temp[i]) << "kn " << std::get<2>(temp[i]) << "kg" << std::endl;
                }
                break;
            }
            else if (x == "2")
            {
                //Sort the tuple by the [0] element in descending oreder 
                //lambda expresion - make a function creation inside the sort command
                //creates two constant tuples and tests each [0] element to sort the list
                sort(temp.begin(), temp.end(), [](const std::tuple<std::string, double, double>& left, const std::tuple<std::string, double, double>& right)
                    { return(std::get<0>(left) > std::get<0>(right)); });
                std::cout << "\nSorted list from Z to A:\n" << std::endl;
                //print out the sorted tuple 
                for (int i = 0; i < temp.size(); ++i)
                {
                    std::cout << std::get<0>(temp[i]) << "- " << std::get<1>(temp[i]) << "kn " << std::get<2>(temp[i]) << "kg" << std::endl;
                }
                break;
            }
            else if (x=="3")
            {
                //Sort the tuple by the [1] element in ascending oreder 
                //lambda expresion - make a function creation inside the sort command
                //creates two constant tuples and tests each [0] element to sort the list
                sort(temp.begin(), temp.end(), [](const std::tuple<std::string, double, double>& left, const std::tuple<std::string, double, double>& right)
                    { return(std::get<1>(left) > std::get<1>(right)); });
                std::cout << "\nSorted list from High price to low price:\n" << std::endl;
                //print out the sorted tuple 
                for (int i = 0; i < temp.size(); ++i)
                {
                    std::cout << std::get<0>(temp[i]) << "- " << std::get<1>(temp[i]) << "kn " << std::get<2>(temp[i]) << "kg" << std::endl;
                }
                break;
            }
            else if (x == "4")
            {
                //Sort the tuple by the [0] element in descending oreder 
                //lambda expresion - make a function creation inside the sort command
                //creates two constant tuples and tests each [0] element to sort the list
                sort(temp.begin(), temp.end(), [](const std::tuple<std::string, double, double>& left, const std::tuple<std::string, double, double>& right)
                    { return(std::get<1>(left) < std::get<1>(right)); });
                std::cout << "\nSorted list from Low price to High price:\n" << std::endl;
                //print out the sorted tuple 
                for (int i = 0; i < temp.size(); ++i)
                {
                    std::cout << std::get<0>(temp[i]) << "- " << std::get<1>(temp[i]) << "kn " << std::get<2>(temp[i]) << "kg" << std::endl;
                }
                break;
            }
            else
            {
                testInputType(); // print out that the input is wrong type and clear input
                break;
            }

        }

        std::cout << "\nWould you like to sort the list in another way?\n" << std::endl;
        std::string y{ continueAgain() }; //testing if the user would like to repeat the action
        if (y != "1")
            break;
    }
}
//Function that searches does an input fruit match asked fruit
void searchBar(std::vector <Fruit>& fruitList , std::vector <std::string>& temper)
{
    while (true)
    {
        bool i{ false }; //declaration of marker to indicate if the input name is unique
        std::string favF{}; //string to store fruit names needed for favorite list
        std::cout << "\nType in the fruit you would like to search: ";
        std::string h{};
        std::cin >> h;

        for (auto& fruit : fruitList)
        {
            if (caseInSensStringCompare(fruit.name, h))
            {
                std::cout << fruit.printFruit() << std::endl; //printing the fruit if matches the current fruit in vector fruitList
                i = true;
                std::cout << "\nWould you like to add that fruit to favorites?\n" << std::endl;
                std::string x{ continueAgain() }; //testing if the user would like to repeat the action
                if (x == "1")
                {
                     std::string favF{ fruitFavorite(fruitList,h) }; //saving fruit name in favorite string favF
                     temper.push_back(favF); //pushing string value in string vector of favorites
                }
                break;
            }
        }

        if (i==false)
            std::cout << "\nYour fruit was not found, maybe try searching another fruit." << std::endl;

        std::cout << "\nWould you like to search another fruit?\n" << std::endl;        
        std::string y{continueAgain()}; //testing if the user would like to repeat the action      
        if (y != "1")
            break;
    }
}
//function that switches windows between sub-screens of Inventory Overview
void switchOvr(int x, std::vector <Fruit>& fruitList, std::vector <std::string>& temper)
{
    switch (x)
    {
    case 1:
        searchBar(fruitList,temper);
        inventoryOverview(fruitList, temper);
        break; 
    case 2:
        welcomeScreen(fruitList, temper);
        break;
    default:
        std::cout << "\n\nSomething went wrong, please try again. \n\n";
        inventoryOverview(fruitList, temper);
        break;
    }
}
//Function that has an introduction message and info about inventory Overview
//and takes a user input to switch between sub-screens
void inventoryOverview(std::vector <Fruit> & fruitList, std::vector <std::string>& temper)
{
    std::cout << "\n\n&&&&& Welcome to inventory Overview &&&&&"<< std::endl;
    std::cout << "\nIn this section you can search your desired product and you can store them to your favorites to make your shopping easy!\n" << std::endl;
    std::cout << "1- Search the desired fruits" << std::endl;
    std::cout << "2- Back" << std::endl;
    std::cout << "\nInput a number of your prefered option : ";
    int choseOption{ insertNumber() }; // Variable that saves the user input from function insertNumber()
    switchOvr(choseOption, fruitList, temper);
   
}
// Function that takes in a name of fruit and weigth and calculates total price weigth*price
// Updates inventory status and prints out the updated inventory status
void buy(std::vector <Fruit>& fruitList, std::vector <std::string>& temper)
{
    bool t{ false }; //declaration of marker to indicate if the input name is unique
    while (true)
    {
        std::cout << "\nType in the fruit you would like to buy: ";
        std::string n{ };
        std::cin >> n;
        for (auto& fruit : fruitList)
        {
            if (caseInSensStringCompare(fruit.name, n))
            {
                std::cout << fruit.printFruit() << std::endl;//print out the current fruit
                std::cout << "\nYour price will be automaticlly calculated according to the entered amount." << std::endl;
                double wKg{};
                while (true)
                {
                    std::cout << "\nEnter the amount that you would like to buy in kg: ";
                    std::cin >> wKg;
                    if (std::cin.fail())//testing if input is double or not   
                        testInputType();
                    //calculation of the price, output total price and update inventory
                    else
                    {
                        bool i{ false }; //declaration of marker to indicate if the weight is in range and correct
                        double wGht{}; //weight of the selected item
                        double fPr{}; //price of the selected fruit
                        double tPrice{}; // total calculated price
                        std::string newPrice{};
                        wGht = stod(fruit.weight);// converts string to double 
                        if (wKg >= 0 && wKg <= wGht)
                        {
                            fPr = stod(fruit.price); // converts string to double    
                            tPrice = fPr * wKg;
                            std::cout << "\nTotal price you need to pay for the item " << fruit.name << " is: ";
                            std::cout << tPrice << " kn" << std::endl;
                            fruit.weight = convertString((wGht - wKg));   //save as string                                                        
                            std::cout << "\nUpdated inventory...." << std::endl;
                            std::cout << fruit.printFruit() << std::endl;//print out the current fruit
                            i = true;
                        }
                        else
                        {
                            std::cout << "\nThe amount you entered exceeds the current amount in inventory." << std::endl;
                            std::cout << "\nMaximum allowed amount is: " << fruit.weight << " kg" << std::endl;
                        }
                        if (i == true) // if price is in range get out of loop with result if not continue in loop
                            break;
                    }
                }
                t = true;
            }
        }
        if (t == false)
            std::cout << "\nYour fruit was not found, maybe try searching another fruit." << std::endl;

        std::cout << "\nWould you like to buy another fruit?\n" << std::endl;
        std::string x{ continueAgain() }; //testing if the user would like to repeat the action
        if (x != "1")
            break;
    }
}
//function that switches windows between sub-screens of Purchase
void switchPur(int x, std::vector <Fruit>& fruitList, std::vector <std::string>& temper)
{
    switch (x)
    {
    case 1:
        buy(fruitList,temper);
        purchase(fruitList, temper);
        break;
    case 2:
        welcomeScreen(fruitList, temper);
        break;
    default:
        std::cout << "\n\nSomething went wrong, please try again. \n\n";
        purchase(fruitList, temper);
        break;
    }
}
//function where you can buy fruits and update the state of fruit vector after purchase
void purchase(std::vector <Fruit> & fruitList, std::vector <std::string> &temper)
{
    std::cout << "\n\n&&&&& Welcome to purchase page! &&&&&\n" << std::endl;
    std::cout << "In this section you can buy your desired fruit" << std::endl;
    std::cout << "Just type in the desired fruit and amount that you would like to buy.";
    std::cout << "\nIf you saved any favorites, a list of the fruit is below.\n" << std::endl;
    //output the favorite list if exsisting
    for (auto &fruit : fruitList)
    {
        for (int i = 0; i < temper.size(); ++i)
        {
            if (fruit.name == temper[i]) 
            {
                std::cout << fruit.name << "- " << fruit.price << "kn " << fruit.weight << "kg" << std::endl;
                break;
            }
        } 
    }
    std::cout << "\n1- Search and buy desired fruits" << std::endl;
    std::cout << "2- Back" << std::endl;
    std::cout << "\nInput a number of your prefered option : ";
    int choseOption{ insertNumber() }; // Variable that saves the user input from function insertNumber()
    switchPur(choseOption, fruitList, temper);
}

int main()
{
    //initialize the list of groceries from the .txt file
    std::ifstream myIniFile;
    myIniFile.open("initialVariable.txt",std::ifstream::app);//open the txt file and save it to variable initialVariable ::app means append to existing, dont overwrite
    std::vector <Fruit> fruitList;       //initialize the object Fruit vector
    std::vector <std::string> objectFruit;    //initialize the string vector objectFruit
    std:: string line;     //string line variable for temporarey storing words from txt file 'initialVariable'
    std::vector <std::string> temper; // declaration of string vector to store favorites

    //while loops that get string objects from initialVariable variable
    //outer loop goes row bi row in initialVariable which stores objects with
    //tags name, weigth and price, and inner loop split the string with 3 values
    //separetad by ',' and stores them in fruitList Fruit class vector
    while(getline(myIniFile,line,'\n'))
    { 
        objectFruit.clear();                                               //clearing the objectFruit vector from previous data
        std::stringstream inputStringstream(line);                         //transform string line in apropriate c_type format
        while (getline(inputStringstream, line, ','))
        {
            objectFruit.push_back(line);                                   //adding one bi one element from the row stored in line variable to string vector objectFruit
        }
        Fruit newFruit(objectFruit[0], objectFruit[1], objectFruit[2]);    //defining a new object in class Fruit with variables from objectFruit vector
        fruitList.push_back(newFruit);                                     //adding new object to Fruit class vector fruitlist
    }
    myIniFile.close();//close the .txt file after reading and importing
    welcomeScreen(fruitList,temper); //call the main navigation welcome screen

    //open txt file again in write mode
    //delete the file content
    //if not posible in other ways save the file string by string devided by comma
    //in for loop write in the content line by line
    std::ofstream myFile;
    myFile.open("initialVariable.txt", std::ofstream::trunc); // ofstream::truc - deletes all current data in .txt file

    for(auto &fruit: fruitList)
    {
       myFile << fruit.name << "," << fruit.weight << "," << fruit.price << std::endl;  //write final vector values back to file
    }
    myFile.close();
    return 0;
}