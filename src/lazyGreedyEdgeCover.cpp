//started but not finished
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <limits>
#include "edgeCover.h"
#include "utility.h"

#define DEBUG 0 

/* Given a graph G this function computes the 3/2 approximation edge cover by primal dual methods
 *
 */


void EdgeCover::lazyGreedyEdgeCover(LightGraph &G,WeightEdgeList &outPut, NODE_T cV[],NODE_T bV[],SUM_T &totalWeight)
{
  
  //number of nodes
  NODE_T n = G.numberOfNodes();
  //number of edges
  EDGE_T m = G.numberOfEdges();
  
  //to retrive the edges
  WeightEdgeList edgeList;
  edgeList.clear();
  edgeList.reserve(m);
   
  //hold the index of the lightest edge in the edgeList
  EDGE_T *mu = new EDGE_T[n];
  
  
  //hold the approximate duals
  VAL_T *price = new VAL_T[n];  
  
  //degree of node v
  NODE_T *dV = new NODE_T[n];

  totalWeight = 0;
  
  //create the edge List
  G.createEdgeList(edgeList);

  ///debug
  if(DEBUG==1)
    std::cout<<edgeList.size()<<std::endl;
  ///end_debug

  //find out the number of vertices with degree 0 and all the degrees
  NODE_T currentCovered = calculateAndDegreek(G,dV,0);

  ///debug
  if(DEBUG==2)
  {
    std::cout << currentCovered<<std::endl;
  }
  ///end_debug
  
  //settle bV values
  for(NODE_T i=0;i<n;i++)
  {
    bV[i] = std::min(bV[i],dV[i]);
  }
  
  
  std::make_heap(edgeList.begin(),edgeList.end(),minHeapCompare);  
  
  //initialize the cV
  for(NODE_T i=0;i<n;i++)
  {
    cV[i] = 0;
  }
  
  if(DEBUG==1)
  {
    for(EDGE_T i=0;i<edgeList.size();i++) std::cout<<edgeList[i].weight<<std::endl;
  }
  outPut.clear();
  
  
  int itn=0;
  while(currentCovered<n)
  {
    //get the least weight element
    WeightEdge we = edgeList.front();
   
    
    std::pop_heap(edgeList.begin(),edgeList.end(),minHeapCompare);
    edgeList.pop_back();
    
    NODE_T u = we.e.u;
    NODE_T v = we.e.v;
    
    int cover=0;
    if(cV[u]<bV[u]) cover++;
    if(cV[v]<bV[v]) cover++;

    if(cover>0)
    {
      if(we.flag==0) we.weight = we.weight*(3-cover);

      WeightEdge weNow = edgeList.front();
      
      if(DEBUG==1)
        std::cout<<weNow.e.u<<" "<<weNow.e.v<< " "<<weNow.weight<<std::endl;
      if(we.weight <= weNow.weight)
      {
        cV[u]++;
        cV[v]++;
        if(cV[u]==bV[u]) currentCovered++;
        if(cV[v]==bV[v]) currentCovered++; 
        if(we.flag==1) we.weight = we.weight/2.0;
        outPut.push_back(we);
        totalWeight = totalWeight + we.weight;
        
        if(DEBUG==1)
          std::cout<<currentCovered<<std::endl;
      }
      else
      {
        we.flag = 1;
        edgeList.push_back(we); 
        push_heap(edgeList.begin(),edgeList.end(),minHeapCompare);
      }
    }
    itn++;
  }

  ///debug
  //if(DEBUG==1) std::cout<<"#of covered "<<currentCovered<<" "<<std::endl;
  ///end_debug
  //std::cout<<currentCovered<<std::endl;
  assert(currentCovered == n);
  
}
