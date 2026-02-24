#include <iostream>
#include <string>
#include "account.h"

#ifndef SAVINGSACC_H
#define SAVINGSACC_H

class Savings:public Account{
    private:
        double interestrate;
        double minimumBalance;
        int monthlylimit;
        bool allowdeposit = true;
        int transactions = 0;


    public:
        Savings() : Account(){};
        Savings(double bal, std::string name, double minB, double irate) : Account(bal, name, bal >= minB){};

        Savings(const Savings& other) : Account(other){};
        ~Savings();

        void calculateinterest();
        void disableDeposits();
        void enableDeposits();

        void withdraw(double subtract)override;
        void deposit(double add)override;
};
#endif;