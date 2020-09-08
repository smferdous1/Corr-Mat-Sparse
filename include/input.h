#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "graph.h"

class Input
{
  std::string fileName;
  public:
  void readMtx(std::string ,LightGraph& ,int=0, long int=0,VAL_T=0,VAL_T=0);
  void readMtxBpt(std::string ,BptGraph& ,int=0, long int=0,VAL_T=0,VAL_T=0);
  //default constructor
  
  void readBinBpt(std::string , BptGraph &);
  void wrtBinBpt(std::string , BptGraph &);
  void readBinGen(std::string , LightGraph &);
  void wrtBinGen(std::string , LightGraph &);
  void wrtMtx(std::string, WeightEdgeList &);
  Input()
  {
  
  }
  
  Input(std::string givenFile)
  {
    fileName = givenFile;
  }
};


#endif
