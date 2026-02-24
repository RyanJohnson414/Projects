#include <iostream>
#include <string>
#include "account.h"

#ifndef CHECKINGACC_H
#define CHECKINGACC_H


class Checking : public Account{
    private:
        bool lock;
    public:
        Checking() : Account(){};
        Checking(double bal, std::string name, bool active, bool locked) : Account(bal, name, active){};
        Checking(const Checking& other) : Account(other){};
        void deposit(double add)override;
        void withdrawC(double subtract, std::string organization);
        void owithdraw(double subtract)override;
        void re_deactivateAcc();
        void un_lockAcc();

};
#endif