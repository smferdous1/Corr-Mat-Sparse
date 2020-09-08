#include <assert.h>
#include "edgeCover.h"
#include "graph.h"
#include <algorithm>

bool Compare(WeightEdge &a,WeightEdge &b)
{
  return a.weight>b.weight;
}

void EdgeCover::removeMaximalRedundantEdges(WeightEdgeList& outPut,NODE_T cV[],SUM_T& reducedWeight, EDGE_T deleteMap[])
{
  
  

  EDGE_T m = outPut.size();

  reducedWeight = 0;
  //scan through the edges in the output
  for(EDGE_T i=0;i<m;i++)
  {
    WeightEdge we = outPut[i];

    NODE_T u = we.e.u;
    NODE_T v = we.e.v;
    VAL_T w = we.weight;
    //initializing as non deleting
    deleteMap[i]=0;
    //find a redundant edge
    if(cV[u]>1 && cV[v]>1)
    {
      deleteMap[i] = 1;
      reducedWeight = reducedWeight + w;
      cV[u] = cV[u]-1;
      cV[v] = cV[v]-1;
    }
  }
}

void EdgeCover::removeMaximalRedundantEdges(WeightEdgeList& outPut,NODE_T cV[],NODE_T bV[], SUM_T& reducedWeight, EDGE_T deleteMap[])
{
  
  

  EDGE_T m = outPut.size();

  reducedWeight = 0;
  //scan through the edges in the output
  for(EDGE_T i=0;i<m;i++)
  {
    WeightEdge we = outPut[i];

    NODE_T u = we.e.u;
    NODE_T v = we.e.v;
    VAL_T w = we.weight;
    //initializing as non deleting
    deleteMap[i]=0;
    //find a redundant edge
    if(cV[u]>bV[u] && cV[v]>bV[v])
    {
      deleteMap[i] = 1;
      reducedWeight = reducedWeight + w;
      cV[u] = cV[u]-1;
      cV[v] = cV[v]-1;
    }
  }
}

void EdgeCover::removeMaximalRedundantbEdges(WeightEdgeList& outPut,NODE_T cV[], SUM_T& reducedWeight, EDGE_T deleteMap[])
{
  
  

  EDGE_T m = outPut.size();

  reducedWeight = 0;
  //scan through the edges in the output
  for(EDGE_T i=0;i<m;i++)
  {
    WeightEdge we = outPut[i];

    NODE_T u = we.e.u;
    NODE_T v = we.e.v;
    VAL_T w = we.weight;
    //initializing as non deleting
    deleteMap[i]=0;
    //find a redundant edge
    if(cV[u]<0 && cV[v]<0)
    {
      deleteMap[i] = 1;
      reducedWeight = reducedWeight + w;
      cV[u] = cV[u]+1;
      cV[v] = cV[v]+1;
    }
  }
}
void EdgeCover::removeGreedyRedundantbEdges(WeightEdgeList& outPut,NODE_T cV[],SUM_T& reducedWeight, EDGE_T deleteMap[])
{
    
  std::sort(outPut.begin(),outPut.end(),Compare);
  reducedWeight = 0;
  //scan through the edges in the output
  EDGE_T m = outPut.size();
  for(EDGE_T i=0;i<m;i++)
  {
    WeightEdge we = outPut[i];

    NODE_T u = we.e.u;
    NODE_T v = we.e.v;
    VAL_T w = we.weight;
    //initializing as non deleting
    deleteMap[i]=0;
    //find a redundant edge
    if(cV[u]<0 && cV[v]<0)
    {
      deleteMap[i] = 1;
      reducedWeight = reducedWeight + w;
      cV[u] = cV[u]+1;
      cV[v] = cV[v]+1;
    }
  }
  
}
void EdgeCover::addCheapestEdges(NODE_T n, NODE_T cV[],NODE_T dV[],EDGE_T mu[],WeightEdgeList &edgeList, WeightEdgeList &outPut, SUM_T &totalWeight, NODE_T &currentCovered)
{
  //add the cheapest edge for what left
  for(NODE_T i = 0;i<n;i++)
  {
    if(cV[i]<1 && dV[i]>0)
    {
      assert(mu[i]>=0);
      NODE_T u = edgeList[mu[i]].e.u;
      NODE_T v = edgeList[mu[i]].e.v;
      VAL_T w = edgeList[mu[i]].weight;
      
      cV[u]++;
      if(cV[u]==1) currentCovered = currentCovered +1;
      
      cV[v]++;

      if(cV[v]==1) currentCovered = currentCovered + 1;
      outPut.push_back(edgeList[mu[i]]);
      totalWeight = totalWeight + w ;

    }
  }

}

void EdgeCover::addCheapestbEdges(NODE_T n, NODE_T cV[],NODE_T bV[],EDGE_T mu[],WeightEdgeList &edgeList, WeightEdgeList &outPut, SUM_T &totalWeight, NODE_T &currentCovered)
{
  
  EDGE_T m = edgeList.size();


  for(EDGE_T i=0;i<m;i++)
  {
    WeightEdge we = edgeList[i];
    NODE_T u = we.e.u;
    NODE_T v = we.e.v;
    VAL_T weight = we.weight;

    VAL_T limit_u = edgeList[mu[u]].weight;
    VAL_T limit_v = edgeList[mu[v]].weight;

    if(cV[u]>0 && weight<=limit_u)
    {
      cV[u]--;
      if(cV[u]==0) currentCovered = currentCovered + 1;
      cV[v]--;
      if(cV[v]==0) currentCovered = currentCovered + 1;
      
      outPut.push_back(we);
      totalWeight = totalWeight + weight;
    
    }

    else if(cV[v]>0 && weight<=limit_v)
    {
      cV[u]--;
      if(cV[u]==0) currentCovered = currentCovered + 1;
      cV[v]--;
      if(cV[v]==0) currentCovered = currentCovered + 1;
      
      outPut.push_back(we);
      totalWeight = totalWeight + weight;
      
    
    }
  }

}
