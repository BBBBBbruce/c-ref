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
  if(check_status()){
    os<<" current available"<<endl;
  }
  else{
    os<<" borrowed by "<<bocode<<" until ";
    os<<day<<"/12/2018"<<endl;
  }
  return os;
}

std::ostream& dvds::print ( std::ostream& os ) {
  os<<"dvd: "<<name;
  if(check_status()){
    os<<" current available"<<endl;
  }
  else{
    os<<" borrowed by "<<bocode<<" until ";
    os<<day<<"/12/2018"<<endl;
  }
  return os;
}


item::item(std::string name_) : name(name_){};

books::books(std::string name_):item(name_){};

dvds::dvds(std::string name_) : item(name_){};


void books::borrow(int bor){
  if(!check_status()){
    throw string("not available at the moment");
  }
  status=0;
  change_date();
  bocode=bor;
}

void dvds::borrow(int bor){
  if(!check_status()){
    throw string("not available at the moment");
  }
  status=0;
  change_date();
  bocode=bor;

}

bool item::check_status(){
  if(status == 1 ){
    return true;
  }else{
    return false;
  }
}

int books::change_date(){
  return day=day+14;
}

int dvds::change_date(){
  return day=day+7;
}
// itorator
void printff(std::vector<item*> library){
  cout<<"items:"<<endl;
  std::vector<item*> :: iterator it;
  int i=0;
  for(it = library.begin();it!= library.end();++it){
    cout<<i<<": " ;
    cout<<*library[i];
    i++;
  }

}

void printend( std::vector<item*> library){
  cout<<"saving current state on file:"<<endl;
  std::vector<item*> :: iterator it;
  int i=0;
  for(it = library.begin();it!= library.end();++it ){
    cout<<*library[i];  //cout<<int a=0;
    i++;
  }
}
