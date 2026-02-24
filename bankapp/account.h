#include <iostream>
#include <string>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    protected:

        std::string idnumber;
        double balance;
        std::string accountname;
        double overdraftLimit;
        double overdraftFee = 50;
        bool activeAccount;

        std::string generateAccountID();
    public:
        Account();
        Account(std::string id, double bal, std::string name, bool active);
        Account(double bal, std::string name, bool active);
        Account(const Account& other);

        double checkbalance();
        std::string checkID();
        std::string holderName();
        bool getifactive();

        virtual void deposit(double add);
        virtual void withdraw(double subtract);

        virtual void owithdraw(double subtract);

        void renameacc(std::string namenew);

        virtual ~Account();
};
#endif
