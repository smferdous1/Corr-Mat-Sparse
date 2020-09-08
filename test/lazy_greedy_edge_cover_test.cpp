#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "graph.h"
#include "edgeCover.h"
#include "matching.h"
#include "input.h"
#include "utility.h"

using namespace std;
int main(int argc,char *argv[])
{
  Input graphInput;
  if(argc!=5)
  {
    cout<<"usage: ./program_name input_file out_prefix(end with a /) nrun b"<<endl;
    exit(1);
  }

  std::string fileName = argv[1];
  std::string out_prefix = argv[2];
  int nRun = atoi(argv[3]);
  int b = atoi(argv[4]);
  std::string outfile;

  std::size_t pos1 = fileName.rfind("/");
  if(pos1 == string::npos)
    pos1 = 0;
  else
    pos1 = pos1 + 1;
  std::size_t pos2 = fileName.rfind(".");

  outfile = out_prefix+fileName.substr(pos1,pos2-pos1)+".edgelist";
  

  std::cout<<outfile<<std::endl;


  LightGraph G;
  graphInput.readMtx(fileName,G,0,5245213,1,100);

  NODE_T n;
  EDGE_T m;

  n = G.numberOfNodes();
  m = G.numberOfEdges();
  
  cout<<n<<" "<<m<<endl;

  /*for(EDGE_T i=0;i<2*m;i++)
  {
    cout<<G.A[i]<<endl;
  }*/
  

  EdgeCover ec;
  WeightEdgeList outPut;
  NODE_T *cV = new NODE_T[n];
  NODE_T *bV = new NODE_T[n];
  
  for(NODE_T i=0;i<n;i++) bV[i] = b;
  
  //weights
  SUM_T totalWeight;
  SUM_T reducedWeight;

  //timeer
  double startTime,endTime;
  

  double totalTime = 0;
  for(int i=0;i<nRun;i++)
  {
    currentTime(startTime);
    ec.lazyGreedyEdgeCover(G,outPut,cV,bV,totalWeight);
    graphInput.wrtMtx(outfile,outPut);
    EDGE_T *deleteMap = new EDGE_T[outPut.size()];
    ec.removeMaximalRedundantEdges(outPut,cV,reducedWeight,deleteMap); 
      
   // cout << std::fixed<<std::setprecision(0)<<totalWeight<< " " <<totalWeight-reducedWeight<<" ";
    currentTime(endTime);
    totalTime = totalTime + endTime-startTime;
  }
  
  cout << std::fixed<<std::setprecision(2)<<totalWeight<< " " <<totalWeight-reducedWeight<<" ";
  cout<<std::setprecision(4)<<totalTime/nRun<<endl;
  return 0;
}
