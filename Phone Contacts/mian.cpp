//
//  main.cpp
//  Final Program
//
//  Created by Jinhao Liang on 4/23/23.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void Display(std::map<std::string, std::string> &M)
{
    
    for (auto it : M)
    {
        // the map traversal will automatically output in an ascending order
        std::cout << it.first << " " << it.second << std::endl;
           // the key == the name      // the value == the number
        
    }
   
}

void Add (std::string Newname, std::string Newnumber, std::map<std::string, std::string> &M)
{
    // if the contact is not exist in the phonebook
    if(M.find(Newname) == M.end())
    {
        // add a new contact
        M[Newname] = Newnumber;
        std::cout << "*The new contact is successfully added!*" << std::endl;
        std::cout << std::endl;
    }
    else // if the name already existed in the phonebook
    {
        std::cout << "*This name is already added! Cannot be added again*" << std::endl;
        std::cout << std::endl;
    }
    
    
}

void Remove(std::string removeName, std::map<std::string, std::string> &M)
{
    // if the name can be found in the phonebook, then remove it
    if(M.find(removeName) != M.end())
    {
        M.erase(removeName);
        std::cout << "*The contact is successfully removed!*" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "*The name is not existed in the phonebook, cannot be found!*" << std::endl;
        std::cout << std::endl;
        
    }
}

void Change(std::string name, std::string Newnumber, std::map<std::string, std::string> &M)
{
    // if the name can be found in the phonebook, then change the number to the New number
    if(M.find(name) != M.end())
    {
        M[name] = Newnumber;
        std::cout << "*The contact info is successfully changed!*" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "*The name is not existed in the phonebook, cannot be found!*" << std::endl;
        std::cout << std::endl;
    }
    
}

void Update (std::map<std::string, std::string> &M)
{
    std::ifstream input ("updates.txt");
    if(input.fail())
    {
        std::cout << "*The file cannot be open!*" << std::endl;
        return;
    }
    else
    {
        while (!input.eof())
        {
            std::string line, name, number;
            std::getline(input,line);
            
            std::istringstream istream(line);
            
            istream >> name >> number;
            
            // If the new read name is not found in the phonebook, then it can be added in as a new contact
            // if the name is alreay existed, then just igonre it
            if(M.find(name) == M.end())
            {
                M[name] = number;
            }
            
        }
        
        std::cout << "*The phonebook is successfully updated!*" << std::endl;
        std::cout << std::endl;
    }
    
}


int main() {
    
    std::string filename = "contacts.txt";
    std::ifstream input(filename);
    std::map <std::string, std::string> phoneBook; // a map with people's name as a key and a phone number as value; both in string type
    
    // input from the file and fill up the phoneBook
    
        if(input.fail())
    {
        std::cout << "File cannot open!!" << std::endl;
        return 0;
    }
    else
    {
        while(!input.eof())
        {
            std::string line, name, number;
            
            std::getline(input,line); // get a line from the file and stored in line
            
            std::istringstream istring(line); //output from the line through istring
            istring >> name >> number; // output the name and number from the line respectively
            
            // store the name as the key and the number as the value into the map as a element
            phoneBook[name] = number;
        
        }
    
    }
    
    char option; // to hold the options from the user
    
    do
    {
        // output the menu
       
        std::cout << "***************************************************************************************"<<std::endl;
        std::cout << "Menu:"<<std::endl;
        std::cout << "D : Display all contacts in aphabetic order (sorted by first name)" <<std::endl;
        std::cout << "A : Add a contact (user enters the name and phone number from console)" <<std::endl;
        std::cout << "R : Remove a contact (user enters the name from console)" <<std::endl;
        std::cout << "C : Change contact information (user enters the name and new phone number from console)" <<std::endl;
        std::cout << "U : Reads a list of contacts from the “update.txt” file into the existing database" <<std::endl;
        std::cout << "Q: Quits the applications" << std::endl;
        std::cout << "***************************************************************************************"<<std::endl;
        std::cout <<std::endl;
        std::cout << "Please enter your option code to fulfill your command: " ;
        std::cin >> option;
        std::cout << std::endl;
        
        switch (option) {
            case 'D':{
                std::cout << "*******************"<<std::endl;
                std::cout << "The phone book list:" <<std::endl;
                Display(phoneBook);
                std::cout << "*******************"<<std::endl;
                std::cout << std::endl;
                
                std::cout << "Pleast 'M' to see the menu again or 'Q' to quit the app: ";
                std::cin >> option;
                break;
                
            }
                
            case 'A':{
                std::string name, number;
                std::cout << "Please enter the name of the contact: ";
                std::cin >> name;
                std::cout << "Please enter the number: ";
                std::cin >> number;
                std::cout << std::endl;
                Add(name, number, phoneBook);
                std::cout << "New phone book display: " << std::endl;
                Display(phoneBook);
                std::cout << std::endl;
                
                std::cout << "Pleast 'M' to see the menu again or 'Q' to quit the app: ";
                std::cin >> option;
                break;
                
            }
                
            case 'R':{
                std::string Rname;
                std::cout << "Please enter the name of the contact: ";
                std::cin >> Rname;
                std::cout << std::endl;
                Remove(Rname, phoneBook);
                std::cout << "New phone book display: " << std::endl;
                Display(phoneBook);
                std::cout << std::endl;
                
                std::cout << "Pleast 'M' to see the menu again or 'Q' to quit the app: ";
                std::cin >> option;
                break;
                
            }
             
            case 'C':{
                std::string Cname, Cnumber;
                std::cout << "Please enter the name of the contact: ";
                std::cin >> Cname;
                std::cout << "Please enter the new number: ";
                std::cin >> Cnumber;
                std::cout << std::endl;
                Change(Cname, Cnumber, phoneBook);
                std::cout << "New phone book display: " << std::endl;
                Display(phoneBook);
                std::cout << std::endl;
                
                std::cout << "Pleast 'M' to see the menu again or 'Q' to quit the app: ";
                std::cin >> option;
                break;
            }
            
            case 'U':{
                std::cout << std::endl;
                Update(phoneBook);
                std::cout << "New phone book display: " << std::endl;
                Display(phoneBook);
                std::cout << std::endl;
                
                std::cout << "Pleast 'M' to see the menu again or 'Q' to quit the app: ";
                std::cin >> option;
                break;
            }
         
        }
        
    }while(option != 'Q');
    
}
