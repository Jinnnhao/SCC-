#pragma once
#include "UserAccount.h"
//#include "Helper.h"
 #include <cstdlib>
 #include <memory>
 #include <vector>
 #include<iostream>

      UserAccount::UserAccount()
    {
         this->id=0;
         this->accountBalance=0;
         this->accountNumber=0;
         this->accountName="";
         
       }

     UserAccount::UserAccount(std::string accountName, int id, int accountNumber, double accountBalance)
     {
         this->id=id;
         this->accountBalance= accountBalance;
         this->accountNumber= accountNumber;
         this->accountName= accountName;
       // regular constructor
      }
      
       //getters
      
    std::string UserAccount::getAccountName()
    {
        return accountName;
    }
       
    int UserAccount::getAccountNumber()
    {
        return accountNumber;
    }
        
    double UserAccount::getAccountBalance()
    {
        return accountBalance;
    }

    int UserAccount::getId()
    {
        return id;
    }

      // setters : cannot change number and accountName
      //setting balance may be needed by admin

    

      //helper method
    std::string UserAccount::fixPoint(std::string number)
    {
        // taking the number to three decimal places
          int i= number.find('.');
          return number.substr(0,i+3);
    }
     
    bool UserAccount::equalTo (shared_ptr<UserAccount> a )
    {
        // compare all fields of this user account with a
        //if (this->accountBalance == a->accountBalance and this->accountNumber == a->accountNumber and this->accountName == a->accountName)
        //{
        //    return true;
        //}
        //else
        //{
         //   return false;
        //}
        
        return  std::tie(accountBalance, accountNumber, accountName) == std::tie(a->accountBalance, a->accountNumber, a->accountName);
    }
      
    std::string UserAccount::toString()
        {
        //std::cout<<fixPoint(std::to_string(accountBalance));
        return "Account Name: "+accountName+"\n"+
               "Account Number: "+std::to_string(accountNumber)+"\n"+
            "Account Balance: " +fixPoint(std::to_string(accountBalance))+"\n";
               
                
        }
    
void UserAccount::setAccountBalance(double accountBalance)
{
    this->accountBalance = accountBalance;
}


    void UserAccount::setAccountName(string accountName)
        {
            this->accountName = accountName;
        }
        
    void UserAccount::setAccountNumber(int number)
        {
            this->accountNumber = number;
        }
        
    void UserAccount::setId(int id)
        {
            this->id = id;
        }
     
    bool UserAccount::withdraw(double amount)
        {
        
                return false;

        }
      
      
    void UserAccount::deposit(double amount)
    {
        // deposit and
        //check if eligible for reward
        if (amount < MIN_REWARD_AMOUNT)
        {
           this-> accountBalance += amount;
        }
        
        if (amount > MIN_REWARD_AMOUNT)
           addReward(amount);
    }
      
     
    void  UserAccount::addReward(double amount)
    {
        this -> accountBalance = accountBalance + (REWARD_RATE * amount);
    }
    
    
     

  const double UserAccount::MIN_BALANCE=9.99;
  const double UserAccount::MIN_REWARD_AMOUNT=1000.0;
  const double UserAccount::REWARD_RATE=0.04;
 
bool UserAccount:: operator==(shared_ptr<UserAccount> a) const
{
    return (this->accountBalance == a->getAccountBalance() && this->accountNumber == a->getAccountNumber() && this->id == a->getId() && this->accountName == a->getAccountName());
}
