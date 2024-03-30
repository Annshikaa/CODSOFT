#include <iostream>
#include <unistd.h>
using namespace std;
void showProgressBar(int duration, int steps) {
    int progressBarWidth = 25;
    for (int i = 0; i < steps; ++i) {
        float progress = static_cast<float>(i) / steps;
        int barWidth = static_cast<int>(progress * progressBarWidth);
        cout << "[";
        for (int j = 0; j < progressBarWidth; ++j) {
            if (j < barWidth)
                cout << ".";
            else
                cout << " ";
        }
        cout << "] " << int(progress * 101.0) << "%\r";
        cout.flush();

        // Simulate some work being done
        usleep(duration * 1000);
    }
    cout << endl;
}

class BankAccount {
private:
    std::string name;
    int accountNumber;
    std::string type;
    double balance;

public:
    // Constructor to assign initial values
    BankAccount(std::string n, int num, std::string t, double b) {
        name = n;
        accountNumber = num;
        type = t;
        balance = b;
    }

    // To deposit an amount
    void deposit(double amount) {
        balance += amount;
    }

    // To withdraw an amount after checking balance
    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            std::cout << "Insufficient balance" << std::endl;
            return false;
        }
    }

    // To display the name and balance
    void display() {
        std::cout << "Name: " << name << ", Balance: $" << balance << std::endl;
    }
};

int main()
 {
    int loadingDuration = 100; // in milliseconds
    int numberOfSteps = 200;

    showProgressBar(loadingDuration, numberOfSteps);
    cout << "Hello!!!" << std::endl;
    cout << "WELCOME TO INTERNATIONAL BANK" << std::endl;
    
    std::string name;
    int accountNumber;
    std::string type;
    double balance;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;

    std::cout << "Enter account type: ";
    std::cin >> type;

    std::cout << "Enter initial balance: $";
    std::cin >> balance;

    BankAccount account(name, accountNumber, type, balance);

    int choice;
    double amount;

    while (true) {
        std::cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter deposit amount: $";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdrawal amount: $";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.display();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;

    return 0;
}


