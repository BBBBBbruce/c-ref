
#include<iostream>
#include<list>
#include<math.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include<algorithm>
#include "../inc/labass2017.hpp"

using namespace std;

bool compres( item* & a,  item* & b){
   return *a < *b ;
}



int main() {
  list <item*> restrict;

  list <item*> unrestrict;
// +++++++++++++++++++++++++ read from restricted.txt +++++++++++++++++

  ifstream infile;
  string filename;

  filename="restricted.txt";
  infile.open(filename.c_str());
  string resname;
  int resamount;
  string author;
  while(infile>>resname>>resamount>>author){
    item* rptr = new rtct(resname, resamount, author);
    restrict.push_back(rptr);
  }
  infile.close();

// ++++++++++++++++++++++++++++ read from unrestricted.txt +++++++++++++++++

  filename="unrestricted.txt";
  infile.open(filename.c_str());
  string ursname;
  int ursamount;
  while(infile>>ursname>>ursamount){
    item* uptr = new urtct(ursname, ursamount);
    unrestrict.push_back(uptr);
  }
  infile.close();

// ++++++++++++++++++++++++++ PRINT ALL STUF +++++++++++++++++++++
list<item*> :: iterator it;

cout<<"restricted items: "<<endl;
for(it = restrict.begin();it!= restrict.end();++it ){
  cout<<*(*it)<<endl;
}

cout<<endl;

cout<<"unrestricted items: "<<endl;
for(it = unrestrict.begin();it!= unrestrict.end();++it ){
  cout<<*(*it)<<endl;
}

//+++++++++++++++++++++++ sorted print +++++++++++++++++++
cout<<endl;

restrict.sort(compres);
unrestrict.sort(compres);

cout<<"sorted restricted items: "<<endl;
for(it = restrict.begin();it!= restrict.end();++it ){
  cout<<*(*it)<<endl;
}

cout<<endl;

cout<<"sorted unrestricted items: "<<endl;
for(it = unrestrict.begin();it!= unrestrict.end();++it ){
  cout<<*(*it)<<endl;
}


//+++++++++++++++++++++++ print the lowest quantity++++++++

cout<<endl;

if(*restrict.begin()< *unrestrict.begin()){
  cout<<**restrict.begin()<<"is the item with the lowest quantity"<<endl;
}else{
  cout<<**unrestrict.begin()<<"is the item with the lowest quantity"<<endl;
}

//+++++++++++++++++++++++++++ DELETE TWO LISTS+++++++++++++++++++++
  int i=0;
  for(it = restrict.begin();it!= restrict.end();++it ){
    delete *it;
    i++;
  }

  for(it = unrestrict.begin();it!= unrestrict.end();++it ){
    delete *it;
  }

  exit(0);
}
