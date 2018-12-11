#ifndef LABASS2017_H
#define LABASS2017_H


#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include<algorithm>

class item {
protected:
  std::string name;
  int amount;
public:
  virtual std::ostream& print(std::ostream& os)=0;
  friend std::ostream& operator<<(std::ostream& os , item& item);
  friend bool operator <(const item & a,const item& b);

};

class rtct : public item{
  public:
    rtct(std::string name_, int amount_, std::string author );
    std :: ostream & print ( std :: ostream & os ) ;
  private:
    std::string authorisor;
};


class urtct : public item{
public:
  urtct(std::string name_, int amount_);
  std :: ostream & print ( std :: ostream & os ) ;
};

bool operator <(const item & a,const item& b);
std :: ostream & operator << (std :: ostream & os , item& item);
#endif
