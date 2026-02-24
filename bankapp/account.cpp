#include <iostream>
#include <string>
#include <cstdlib>


class Account {
    protected:

        std::string idnumber;
        double balance;
        std::string accountname;
        double overdraftLimit;
        double overdraftFee = 50;
        bool activeAccount;

        std::string generateAccountID(){ //generates an ID (fix to be unique later)
                std::string id = "";
                for(int i = 0; i < 8; i++){
                    id += (std::to_string(rand() % 10));
                }
                return id;
            }
        
    public:
        Account(){ // creating an empty account for the user
            idnumber = generateAccountID();
            balance = 0.00;
            accountname = "";
            overdraftLimit = -500;
            activeAccount = true;
        }
        Account(std::string id, double bal, std::string name, bool active){ // Used for loading data into a previously defined account.
            idnumber = id;
            balance = bal;
            accountname = name;
            overdraftLimit = -500;
            activeAccount = active;


        }
        Account(double bal, std::string name, bool active){ // Used for creating account for new account with a deposit.
            idnumber = generateAccountID();
            balance = bal;
            accountname = name;
            overdraftLimit = -500;
            activeAccount = active;


        }
        Account(const Account& other){ 
            this->idnumber = other.idnumber;
            this->balance = other.balance;
            this->accountname = other.accountname;
            this->overdraftLimit = other.overdraftLimit;
            this->activeAccount = other.activeAccount;

        }
        double checkbalance(){
            return balance;
        }
        std::string checkID(){
            return idnumber;
        }
        std::string getName(){
            return accountname;
        }
        bool getifactive(){
            return activeAccount;
        }
        // cout statements temporary(no UI and for simple testing)
        virtual void deposit(double add){
            if(add <= 0){
                std::cout << "Enter a valid amount" << std::endl; //temp
                return;
            }
            if(activeAccount == true){
                balance += add;
                if(balance < overdraftLimit){
                    balance -= overdraftFee;
                }
            }
        }
        virtual void withdraw(double subtract){
            if(subtract <= 0){
                std::cout << "Enter a valid amount" << std::endl; //temp
                return;
            }
            if(activeAccount == false){
                std::cout << "ACCOUNT IS INACTIVE" << std::endl; //temp
                return;
            }
            if(balance < subtract){
                std::cout << "INSUFFICIENT FUNDS" << std::endl << "IF U WISH TO OVERDRAFT USE OVERWITH"; //temp
                return;
            }
            else{
                balance -= subtract;
            }
        }
        virtual void owithdraw(double subtract){
            if(activeAccount == false){
                std::cout << "ACCOUNT IS INACTIVE" << std::endl; //temp
                return;
            }
            else{
                balance = balance - subtract;
                if(balance < overdraftLimit){
                    balance -= overdraftFee;
                }
            }
         }
        void renameacc(std::string namenew){
            accountname = namenew;
        }
        

        virtual ~Account(){}


};