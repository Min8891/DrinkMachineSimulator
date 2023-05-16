//  Program2 a bevarage vending machine
//  Created by Minjing Liang on 8/31/20.
//  Copyright © 2020 Minjing Liang. All rights reserved.
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct Drink{             // Declare a drink struct
    string drinkName;
    double price;
    int    quantity;
};

class DrinkMachine{      // Declare a vending machine class
private:
    // Define a struct array as a member of the class and initialize
    Drink drink[5] = { {"Cola", 1.00, 20},{"Root beer", 1.00, 20},{"Orange soda", 1.00, 20},{"Grape soda", 1.00, 20},{"Bottled water", 1.50, 20}};
    
    double inputMoney(int choice){   // Validate money function
        if(choice>=1 && choice<=5){
            if (drink[choice-1].quantity > 0)  // Test quantity
                return drink[choice-1].price;
            else
                return 0;
        }
        else
            return 0;
    }
    void dailyReport(){    // A report function called by destructor(sale and remain)
        double moneyCollected, total = 0;
        cout << "\t\t\t" << "Daily Report" <<endl;
        for (int i = 0 ; i < 5 ; i++){
            moneyCollected = (20 - drink[i].quantity) * drink[i].price;
            cout << fixed << showpoint << setprecision(2);
            cout << left <<setw(16) << drink[i].drinkName << "\t\t";
            cout << drink[i].quantity << "\t\t$" << moneyCollected << endl;
            total += moneyCollected;
        }
        cout << "Total money colleted is $" << total << endl;
    }
public:
    void displayChoices(){     // display menu function
        cout << "\t\tDrink Machine menu" <<endl;
        cout << fixed << showpoint << setprecision(2);
        for (int i = 0; i < 5; i++){
            cout << (i+1) << "\t" << left << setw(20)<< drink[i].drinkName;
            cout << "\t\t$" << drink[i].price << endl;
        }
        cout << 6 << "\t" << "Quit" << endl;
    }
    
    void buyDrink(int choice, double moneyReceived){  // function to do the sale
      
        double price = inputMoney (choice);          // check drink quantity
        if (price == 0){
            cout << "Sold out" << endl;
        }
        else{
            if (moneyReceived >= price){             // update quantity
                drink[choice-1].quantity -= 1;
                cout << "Here is your beverage, your change is $" << (moneyReceived - price) << endl;
            }
            else
                cout << "Money is not enough." << endl;
        }
    }
    
    ~DrinkMachine(){     //destructor
        dailyReport();
    }
};
int main() {
    DrinkMachine drinkMachine;
    int choice;
    double moneyReceived;
    do{                                 //do while loop display menu and
        drinkMachine.displayChoices();  // let customer choose drink and input money
        cout << "Enter your choice: ";
        cin >> choice;
        if ((choice <1) || (choice >5)){
            cout << "Please choose from 1 to 5" << endl;
        }
        else{
            cout << "Enter your money $";
            cin >> moneyReceived;
            drinkMachine.buyDrink(choice, moneyReceived); //call class member function
        }
    } while (choice != 6);
    return 0;
}
