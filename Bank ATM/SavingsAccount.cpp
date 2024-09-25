#pragma once
#include "SavingsAccount.h"
#include<iostream>
//#include "Helper.h"

SavingsAccount::SavingsAccount()
    {
        setId(0);
        setAccountBalance(0);
        setAccountName("");
        setAccountNumber(0);
    }
     
SavingsAccount::SavingsAccount(std::string accountName, int id, int accountNumber, double accountBalance)
    {
        //regular constructor
        setId(id);
        setAccountBalance(accountBalance);
        setAccountName(accountName);
        setAccountNumber(accountNumber);
    }

 string SavingsAccount::toString()
    {
      return "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
              "Account Balance: " +fixPoint(std::to_string(getAccountBalance()))+"\n"
              +
               "Account Type: Savings \n";

    }
 bool SavingsAccount::withdraw(double amount)
    {
        return false;
    }

void SavingsAccount::deposit(double amount)
    {
        // deposit and
        //check if eligible for reward
        if (amount < MIN_REWARD_AMOUNT)
        {
            this-> setAccountBalance(amount + this->getAccountBalance());
        }
        
        if (amount > MIN_REWARD_AMOUNT)
        {
            this -> addReward(amount);
        }
        
    }
   
