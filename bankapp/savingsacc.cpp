#include <iostream>
#include <string>
#include "account.h"
#include "savingsacc.h"

class Savings:public Account{
    private:
        double interestrate;
        double minimumBalance;
        int monthlylimit;
        bool allowdeposit = true;
        int transactions = 0;


    public:
        Savings() : Account(){ // used for opening low yeild savings account 
            minimumBalance = 100;
            interestrate = 0.0015; // equal to 0.15% easier to be used for multiplication (monthly)
            monthlylimit = 10;
            allowdeposit = true;
        }
        Savings(double bal, std::string name, double minB, double irate) : Account(bal, name, bal >= minB){ // param constructor inputs for irate and minB will be guided by the main to ensure non insane interest rate
            minimumBalance = minB;
            interestrate = irate;
            monthlylimit = 3;

        }
        Savings(const Savings& other) : Account(other){ // simplify
            this->interestrate = other.interestrate;
            this->monthlylimit = other.monthlylimit;
            this->minimumBalance = other.minimumBalance;
            this->allowdeposit = other.allowdeposit;
        }
        ~Savings(){

        }

        void calculateinterest(){ // public for test function 
            double temp = balance * interestrate;
            balance += temp;
        }
        void disableDeposits(){
            allowdeposit = false;
        }
        void enableDeposits(){
            allowdeposit = true;
        }

        void withdraw(double subtract)override{
            if(allowdeposit == false){
                std::cout << "Deposits not allowed to this account" << std::endl;
                return;
            }
            if(transactions >= monthlylimit){
                std::cout << "Monthly transaction limit reached" << std::endl;
                return;
            }
            if(balance - subtract < minimumBalance){
                std::cout << "Below minimum balance" << std::endl;
                return;
            }
            balance -= subtract;
            transactions++;
        }
        void deposit(double add)override{
            if(allowdeposit == false){
                std::cout << "Deposits not allowed to this account" << std::endl;
                return;
            }
            if(transactions >= monthlylimit){
                std::cout << "Monthly transaction limit reached" << std::endl;
                return;
            }
            balance += add;
            transactions++;

        }
};