#include <iostream>
#include<fstream>
#include<sstream>
#include "Songcpp.h"
#include "VectorADTcpp.h"
#include <chrono>
using namespace std::chrono;



int populatedataBase(VectorADT<Song> &mySongs){
  std::ifstream input("SongsData.txt");
  std::string line;
  std::string title;
  std::string singer;
  std::string cp;//chart position in string
  int chartPosition=0;
  int dataCount=0;
  if (!input){
    throw new std::string("File Open Error ");
    std::exit(-1);
  }
  while (std::getline(input,line)){
   // std::getline(input,line);
    std::string token;
      std::istringstream instream(line);
      std::getline(instream,title, ',');
      std::getline(instream, singer, ',');
      std::getline(instream, cp,'\n');
     // std::cout<<cp<<std::endl;
      chartPosition = std::stoi(cp);
      Song * s = new Song(title,singer,chartPosition);
      mySongs.push_back(s);
      dataCount++;

      }
return dataCount;
}

int main() {

VectorADT<Song> database;

int dataCount=populatedataBase(database);
//database.printVectorADT();
LessThan<Song> f;


    
// Capture the time taken for selection sort
int steps =database.sort(f);
// Get starting timepoint
/*auto start = high_resolution_clock::now();
 
// Get ending timepoint
auto stop = high_resolution_clock::now();

// Get duration. Substart timepoints to
// get duration. To cast it to proper unit
// use duration cast method
auto duration = duration_cast<microseconds>(stop - start);

    std::cout<<std::endl;
std::cout<<"Execution time of sort is " <<duration.count()<<"\n";
    std::cout<<std::endl;*/
    
std::cout<<"*************************************\n";
 std::cout<<"Selection Sorting By Chart Position Steps = "<<steps<<std::endl;
 std::cout<<"*************************************\n";
 database.printVectorADT();
 Song *insertThis= new Song("music is this","BTS",dataCount+1);
 database.push_back(insertThis);
 std::cout<<"*************************************\n";
std::cout<<"After push_back, size of Data base  "<<database.size()<<std::endl;
 
//database.printVectorADT();
Song * temp =database.pop();
std::cout<<"The last song is "<<temp->toString()<<std::endl;
temp=database.pop_back();
std::cout<<"After pop_back, size of Data base  "<<database.size()<<std::endl;
//database.printVectorADT();


Song *insertThis2= new Song("fifth place","BTS",5);//chartposition
int insertSteps=database.insert(insertThis2, 5);//will go into 6th position
std::cout<<"inserted song at index 6 "<<insertThis2->toString()<< " Number of insert  adjust steps= "<<insertSteps<<std::endl;
//database.printVectorADT();
 std::cout<<"After insert, size of Data base  "<<database.size()<<std::endl;
Song * removeSong = database.get(4);
std::cout<<"Going to Remove song fifth place at index 4 "<<std::endl;
int removeSteps=database.remove(4);
std::cout<<"removed element at index 4 - Number of remove adjust steps= "<<removeSteps<<std::endl;
std::cout<<"After remove, size of Data base  "<<database.size()<<std::endl;
int searchSteps=0;
std::cout<<"Searching for song by title "<<removeSong->toString()<<"\n";
int found =database.searchByTitle(searchSteps,removeSong);
    // Get starting timepoint
    /*auto start2 = high_resolution_clock::now();
    // Get ending timepoint
    auto stop2 = high_resolution_clock::now();
    
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

        std::cout<<std::endl;
    std::cout<<"Execution time of search is " <<duration2.count()<<"\n";
        std::cout<<std::endl;*/
    
    
if (found >=0) std::cout<<"FOUND - Took Linear Search Steps - "<<searchSteps<<"\n";
else std::cout<<"NOT FOUND - Took Linear Search Steps - "<<searchSteps<<"\n";
std::cout<<"*************************************\n";
}
