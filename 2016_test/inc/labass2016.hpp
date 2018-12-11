#ifndef LABASS2016_H
#define LABASS2016_H


#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <cstdlib>

class item {
protected:
  std::string name;
  int status=1;
  int day=3;
public:
  int bocode=0;
  item(std::string name_);
  bool check_status();
  virtual int change_date()=0;
  virtual void borrow()=0;
  virtual std::ostream& print(std::ostream& os);
  friend std::ostream& operator<<(std::ostream& os , item& item);
};

class books : public item{
  public:
    books(std::string name_);
    void borrow();
    std :: ostream & print ( std :: ostream & os ) ;
    int change_date();
};


class dvds : public item{
public:
  dvds(std::string name_);
  void borrow();
  std :: ostream & print ( std :: ostream & os ) ;
  int change_date();
};


std :: ostream & operator << (std :: ostream & os , item& item);
void printff(std::vector<item*> library);
void printend( std::vector<item*> library);
#endif
