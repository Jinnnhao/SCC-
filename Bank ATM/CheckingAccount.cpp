#pragma once
 #include "CheckingAccount.h"
 //#include "Helper.h"
 #include<iostream>
 CheckingAccount::CheckingAccount()
    {
        setId(0);
        setAccountBalance(0);
        setAccountName("");
        setAccountNumber(0);
    }

CheckingAccount::CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance)
    {
        setId(id);
        setAccountBalance(accountBalance);
        setAccountName(accountName);
        setAccountNumber(accountNumber);
        
    }

string CheckingAccount::toString()
    {
        return  "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
               "Account Balance: "+fixPoint(std::to_string(getAccountBalance()))+"\n"
               +
               "Account Type: Checking \n";
     }
bool CheckingAccount::withdraw(double amount)
    {
        if (amount > 0)
        {
            if (this->getAccountBalance() - amount >= MIN_BALANCE_CHECKING )
            {
                this->setAccountBalance(this->getAccountBalance() - amount);
               
                return true;
            }
            else
                return false;
        }
        if (amount < 0)
        {
            return true;
        }
        
        else return false;
    }
 
void CheckingAccount::deposit(double amount)
    {
        this->UserAccount::deposit(amount);
    }



const  double  CheckingAccount::MIN_BALANCE_CHECKING=99.99;

