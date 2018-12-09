#include "../inc/labass2017.hpp"
#include <vector>
#include<algorithm>

using namespace std;

std::ostream& operator<<(std::ostream& os , item& item){
  return item.print (os);
}

std::ostream& rtct::print (std::ostream& os ) {
  os<<name<<" ("<<amount<<") ["<<authorisor<<"] ";
  return os;
}

std::ostream& urtct::print ( std::ostream& os ) {
  os<<name<<" ("<<amount<<") " ;
  return os;
}



rtct::rtct(std::string name_, int amount_, std::string author){
    name=name_;
    amount=amount_;
    authorisor= author;
}

urtct::urtct(std::string name_, int amount_){
  name= name_;
  amount=amount_;
}
