#include "../inc/labass2016.hpp"
#include <vector>

using namespace std;

std::ostream& operator<<(std::ostream& os , item& item){
  return item.print (os);
}

std::ostream& item::print(std::ostream& os){
  os << name;
  return os;
}


std::ostream& books::print (std::ostream& os ) {
  os<<"book: "<<name;
  return os;
}

std::ostream& dvds::print ( std::ostream& os ) {
  os<<"dvd: "<<name;
  return os;
}


item::item(std::string name_) : name(name_){};

books::books(std::string name_):item(name_){};

dvds::dvds(std::string name_) : item(name_){};


void books::borrow(){
  if(status==0){
    throw string("not available at the moment");
  }
  status=0;
  day=day+loan_length;

}

void dvds::borrow(){
  if(status==0){
    throw string("not available at the moment");
  }
  status=0;
  day=day+loan_length;

}

// itorator
void printff(std::vector<item*> library){
  cout<<"items:"<<endl;
  std::vector<item*> :: iterator it;
  int i=0;
  for(it = library.begin();it!= library.end();++it){
    cout<<i<<": " ;
    cout<<*library[i];
    if(library[i]->status==1){
      cout<<" current available"<<endl;
    }
    else{
      cout<<" borrowed by "<<library[i]->bocode<<" until ";
      cout<<library[i]->day<<"/12/2018"<<endl;
    }
    i++;
  }

}

void printend( std::vector<item*> library){
  cout<<"saving current state on file:"<<endl;
  std::vector<item*> :: iterator it;
  int i=0;
  for(it = library.begin();it!= library.end();++it ){
    cout<<*library[i];  //cout<<int a=0;
    if(library[i]->status==1){
      cout<<" current available"<<endl;
    }
    else{
      cout<<" borrowed by "<<library[i]->bocode<<" until ";
      cout<<library[i]->day<<"/12/2018"<<endl;
    }
    i++;
  }
}
