
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"
void fillVector (ifstream &input,vector<shared_ptr<UserAccount>> &accountsVector)
{
    //while not eof getline from file
    // parse the line and create shared pointer to BankAccount
    //push the pointe onto the accounts vector
    
   string accountName; string lastName; string firstName,inputLine,type;
  int id,accountNumber;
  double accountBalance;
    try {
        // open the file
        while (!input.eof())
        {
            // Use the getline function to read data line by line from the file
            getline(input,inputLine);
            //Use of stringstream methods to parse input data
            std::istringstream istream(inputLine);
            istream >> firstName >> lastName >> id >> accountName >> accountBalance >> type;
            accountName = firstName+" "+lastName;
            if(type == "S")
            {
                std::shared_ptr <UserAccount> B = std::make_shared<SavingsAccount>(accountName, id, accountNumber, accountBalance);
                accountsVector.push_back(B); // using push.back function to add vector's elements
            }
            if(type == "C")
            {
                std::shared_ptr <UserAccount> B = std::make_shared<CheckingAccount>(accountName, id, accountNumber, accountBalance);
                accountsVector.push_back(B); // using push.back function to add vector's elements
            }
        }
        
    } catch( string msg) // To catch a excetion occurs (try + catch)
    {
        std::cout<<msg;
        exit(0);
    }
  
  
}

void Bank::displayAccounts(){
  
  for (int i=0;i<accountsVector.size();i++){
    cout<<accountsVector[i]->toString()<<endl;
  }
}

Bank::Bank(const Bank &other)
{
  //cout<<" In copy constructor  "<<endl;
  accountsVector.resize(other.accountsVector.size());
  
  //cout<<accountsVector.size()<<endl;
  //create a cop constructor that copies the two vectors
    //std::copy(other.accountsVector.begin(), other.accountsVector.end(), std::back_inserter(this->accountsVector));
    accountsVector = other.accountsVector;
    sortAccounts();
}


Bank::Bank(string filename)
{
    ifstream file(filename);
    string accountName;
    string lastName;
    string firstName,inputLine,type;
    int id,accountNumber;
    double accountBalance;
    
    if (file.fail())
    {
        std::cout << "File Open Error -99" << std::endl;
        exit(0);
    }
    else
    {
        
         try {
             // open the file
             while (file.good())
             {
                 // Use the getline function to read data line by line from the file
                 getline(file,inputLine);
                 if(file.eof()) break;
                 //Use of stringstream methods to parse input data
                 istringstream istream(inputLine);
                 istream >> firstName >> lastName >> id >> accountNumber >> accountBalance >> type;
                 accountName = firstName+" "+lastName;
                 if(type == "S")
                 {
                     std::shared_ptr <UserAccount> B = std::make_shared<SavingsAccount>(accountName, id, accountNumber, accountBalance);
                     accountsVector.push_back(B); // using push.back function to add vector's elements
                 }
                 if(type == "C")
                 {
                     std::shared_ptr <UserAccount> B = std::make_shared<CheckingAccount>(accountName, id, accountNumber, accountBalance);
                     accountsVector.push_back(B); // using push.back function to add vector's elements
                 }
                 
                 
                 
             }
             file.close();
         } catch( string msg) // To catch a excetion occurs (try + catch)
         {
             std::cout<<msg;
             exit(0);
         }

    }
    file.close();
 // throw File Open Error - File Exception -99 if file cannot be opened
//use try catch statement
}

void Bank::addAccount(shared_ptr<UserAccount> a)//should sort vector
{
    
    accountsVector.push_back(a);
    sortAccounts();
  //add an account
  // be sure to keep vector sorted
//use STL sort using Greater THan Function Object
}

void Bank::sortAccounts()
{
  // use the STL sort by passing the beginning, end and Greater Than Functor
    if (accountsVector.size()>1)
    {
      shared_ptr<UserAccount> temp;
      for (int i=0;i<accountsVector.size()-1;i++)
        for (int j=0;j<accountsVector.size()-i-1;j++)
        {
            if (accountsVector[j]->getAccountNumber() > accountsVector[j+1]->getAccountNumber())
          {
                temp = accountsVector[j];
                accountsVector[j]=accountsVector[j+1];
                accountsVector[j+1]=temp;
          }
        }
    
    }
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount)
{
    if (amount < 0)
    {
        return false;
    }
    
    else
    {
        a->deposit(amount);
        return true;
    }
    
    
 // return false if amount is negative
 // return true after depositing into account
}


bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount)
{
  // if the withdraw amount is suitable then withdraw from account and return true
    if(a->withdraw(amount))
    {
        return true;
    }
    else
        return false;

 //otherwise return false
}
    
    
bool Bank::checkSame( Bank &other)
{
    bool flag = false;
    for (auto i = 0; i <= accountsVector.size(); i++)
    {
        if(accountsVector[i]==(other.accountsVector[i]))
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
            
        }
            
    }
    sortAccounts();
    
    
    return flag;
 // check if this bank has the exact same accounts as the other bank
 //use equalTo method created in the UserAccount class (that implments Comparable)
 // return true if same, false otherwise  
  // equalTo should check if each and every field matches
}
    
    
    
    
bool Bank::removeAccount(shared_ptr<UserAccount> a)
{
    bool flag = false;
    //int accountNumber = a->getAccountNumber();
    // auto position = std::find(accountsVector.begin(), accountsVector.end(), a);
    //vector<shared_ptr<UserAccount>>::iterator position = std::find(this->accountsVector.begin(), this->accountsVector.end(), a);
    
    auto position = std::find_if(accountsVector.begin(),accountsVector.end(),[&](std::shared_ptr<UserAccount> const& p) {return p->getAccountNumber() == a->getAccountNumber();});
    // finally did the shared pointer search
                           
    if (position != accountsVector.end())
    {
        cout<< "****** Removing  Account ******" << endl;
        cout << a->toString() << endl;
    
        accountsVector.erase(position);
    
        sortAccounts();
        flag = true;
    }
    return flag;
  //search for the the given account a, if found
  //use vector.erase method to remove it and return true
  //otherwise return false
    
}


