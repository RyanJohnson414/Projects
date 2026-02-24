#include <iostream>
#include <string>
#include "account.h"

class Checking : public Account{
    private:
        bool lock;
    public:
        Checking() : Account(){
            lock = false;
        }
        Checking(double bal, std::string name, bool active, bool locked) : Account(bal, name, active){
            lock = locked;
        }
        Checking(const Checking& other) : Account(other){
            lock = other.lock;
        }
        void deposit(double add)override{
            if(add <= 0){
                std::cout << "Enter a valid amount" << std::endl; //temp
                return;
            }
            if(activeAccount == false){
                std::cout << "Account is inactive." <<std::endl;
                return;
            }
            else{
                balance += add;
                std::cout << add << " deposited to " << accountname << std::endl;
            }



        }
        void withdrawC(double subtract, std::string organization){
            if(subtract <= 0){
                std::cout << "Enter a valid amount" << std::endl; //temp
                return;
            }
            if(activeAccount == false || lock == true){
                std::cout << "Account is inactive." <<std::endl;
                return;
            }
            if(overdraftLimit >= balance - subtract){
                subtract = overdraftFee + subtract;
                balance -= subtract;
                std::cout << subtract << " and overdraft fee applied as withdraw to " << organization << std::endl;
                return;
            }
            else{
                balance -= subtract;
                std::cout << subtract << " applied as withdraw to " << organization << " From account" << accountname << std::endl;
            }
            return;

            
        }
        void owithdraw(double subtract)override{
            if(!activeAccount){
                std::cout << "ACCOUNT IS DEACTIVATED, please reactive." << std::endl;
                return;
            }
            if(!lock){
                std::cout << "Account is locked, unlock first." << std::endl;
                return;
            }
            if(overdraftLimit > balance){
                std::cout << "account is not overdrawn." << std::endl;
                return;
            }
            else{
                balance = balance - overdraftFee - subtract;
                return;
            }
        }
        void re_deactivateAcc(){
            if(activeAccount == false){
                activeAccount = true;
                return;
            }
            else{
                activeAccount = false;
                return;
            }
        }
        void un_lockAcc(){
            if(lock){
                lock = false;
                return;
            }
            if(!lock){
                lock = true;
                return;
            }
        }

};