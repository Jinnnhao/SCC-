#include <iostream>
#include "Bank.h"

int main()
{
  
  shared_ptr<UserAccount> newAcc = make_shared<CheckingAccount>("John Smith",9999,1120,154.67);
shared_ptr<UserAccount> temp = make_shared<SavingsAccount>("Lily Zhaou",786534,1242,001.98);
//temp->withdraw(100);

shared_ptr<UserAccount> temp2= make_shared<CheckingAccount>("Vai vu",432657,1240,987.56);
    
string filename;
int action;
cout<<"What is the file name  ?";
cin>>filename;
Bank WellsFargo(filename);//test action 1 : incorrect file name
WellsFargo.sortAccounts();
WellsFargo.displayAccounts();
for (int i=0;i<9;i++){
cout<<"Which action would you like to test ?";
cin>>action;
if (action ==2){ // add a new account 
  int accountNumber,id;
      std::string accountName;
      double accountBalance;
    
      WellsFargo.addAccount(newAcc);
      cout<<" ****** Added  New Checking Account ******  "<<endl;
      cout << newAcc->toString() << endl; 
      cout <<"Displaying Resulting Sorted Database" <<endl;
      WellsFargo.displayAccounts();
}
else if  (action ==4){ // backing up accounts
  Bank Backup(WellsFargo);
    Backup.displayAccounts();
    if (Backup.checkSame(WellsFargo))
    {
        cout<<"Verified Backup"<<endl; // verifying that they are same;
    }
  
  else cout<<"Backup Error "<<endl;
}
else if (action ==3){ //remove and display
 
    if(WellsFargo.removeAccount(temp)){
        cout << "Displaying Resulting Sorted Database" << endl;
        WellsFargo.displayAccounts();
        cout << " ****** Account Does not Exist ****** " << endl;
    }
  
}
else if (action==5){ // back up and remove account from original
  Bank Backup(WellsFargo);
  
  WellsFargo.removeAccount(temp);
  WellsFargo.displayAccounts();
  if (Backup.checkSame(WellsFargo))
  cout<<"Verified Backup"<<endl; // verifying that they are same;
  else cout<<"Backup Error Databases do not match"<<endl;
}
else if (action ==6)
{ // withdraw money from CheckingAccount
     
      
    if( WellsFargo.accountWithdraw(temp2, 20))
    {
        cout<<"Withdraw Successful for this amount 20$"<<endl;
        cout << temp2->toString() << endl;
    }
    if (WellsFargo.accountWithdraw(temp2, -20))
    {
        cout<<"Withdraw Unsuccessful for this amount -20$"<<endl;
        cout << temp2->toString() << endl;
    }
    
}
  else if (action ==7)
  {
   
  if( WellsFargo.accountWithdraw(newAcc, 100))
    cout<<"Withdraw Successful for this amount 100$"<<endl;
  else
  {
      cout<<"Withdraw Unsuccessful for this amount - Minimum funds 99.99"<<endl;
      cout << newAcc->toString() <<endl;
  }
  if( WellsFargo.accountWithdraw(temp2, 5000))
    cout<<"Withdraw Successful for this amount 5000$"<<endl;
  else
  {
      cout<<"Withdraw Unsuccessful - Insufficient funds for this amount 5000$"<<endl;
      cout << temp2->toString() <<endl;
  }
  WellsFargo.displayAccounts();
  //cout<<"After Withdrawing Backup"<<endl;
  //Backup.displayAccounts();
}
else if (action == 8){ //withdraw money from savings account
 
 if( WellsFargo.accountWithdraw(temp, 20))
 {
     cout<<"Withdraw Successful"<<endl;
     cout << temp->toString() << endl;
 }
    
 else
 {
     cout<<"Withdraw Unsuccessful - Cannot withdraw from Savings Account "<<endl;
     cout << temp->toString() << endl;
 }
}
else if (action ==9){ //deposit money into savings
  if( WellsFargo.accountDeposit(temp,1001))
  {
    cout<<"Deposit Successful for $1001 - rewards added"<<endl;
    cout << temp->toString() << endl;
  }
     if( WellsFargo.accountDeposit(temp,20))
  {
    cout<<"Deposit Successful for $20 - NO rewards added"<<endl;
      cout << temp->toString() << endl;
  }
    
}

else if (action ==10) { //deposit money into checking
if( WellsFargo.accountDeposit(temp2, -20))
    cout<<"Withdraw Successful"<<endl;
    else cout<<"Checking Account Deposit Unsuccessful - Negative Amount: $-20"<<endl;
if( WellsFargo.accountDeposit(temp2, 20))
        cout<<"Checking Account Deposit  Successful for $20"<<endl;
    else cout<<"Withdraw Unsuccessful"<<endl;
}
else cout<<"Testing Ends"<<endl;
}
}
