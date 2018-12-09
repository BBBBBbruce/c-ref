
#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>
#include<string>
#include<cstdlib>
#include "../inc/labass2016.hpp"

using namespace std;

int main() {
  vector<item*>library;
// read from books.txt
  ifstream infile;
  string filename;

  filename="books.txt";
  infile.open(filename.c_str());
  string bookname;
  while(infile>>bookname){
    item* bptr = new books(bookname);
    library.push_back(bptr);
  }
  infile.close();
// read from dvds.txt
  filename="dvds.txt";
  infile.open(filename.c_str());
  string dvdname;
  while(infile>>dvdname){
    item* dptr = new dvds(dvdname);
    library.push_back(dptr);
  }
  infile.close();

  char bor;
  int index;
  int bocode;
  while(bor !='n'){
    printff(library);
    cout<<"to borrow an item please enter its index followed by the borrower's code"<<endl;
    cin>>index>>bocode;
    library[index]->bocode=bocode;

    try {
      library[index]->borrow();
      cout<<index<<" "<<library[index]->bocode<<endl;
    }
    catch (const string & msg){
      cout << msg << endl;
    }

    cout<<"would you like to borrow another item? (y/n)"<<endl;
    cin>>bor;
  }

  printend(library);
  //output librarystate.txt

  ofstream outfile;
  outfile.open ("librarystate.txt");
  vector<item*> :: iterator it;
  int i=0;
  for(it = library.begin();it!= library.end();++it ){
    outfile<<*library[i];
    if(library[i]->status==1){
      outfile<<" current available"<<endl;
    }
    else{
      outfile<<" borrowed by "<<library[i]->bocode<<"until ";
      outfile<<library[i]->day<<"/12/2018"<<endl;
    }
    i++;
  }
  outfile.close();

  i=0;
  for(it = library.begin();it!= library.end();++it ){
    delete library[i];
    i++;
  }




  exit(0);
}
