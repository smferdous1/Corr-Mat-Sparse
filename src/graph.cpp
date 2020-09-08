#include <iostream>
#include "graph.h"

/*This function create an edgeList out of the graph. Remember 
 * the G.A,G.IA and G.JA must be set earlier. if ref=1 then this
 * function also set the references to G.RA
 */
void LightGraph::createEdgeList(WeightEdgeList &outList,bool ref)
{
  //clearing the edgelist. EdgeList is given as a pointer
  //remember you have to give a preallocated address here. 
  outList.clear();
  
  EDGE_T count = 0;
  /*if(ref==1)
  {
    RA = new EDGE_T[2*m];
  }*/
  //scan through the three arrays
  for(NODE_T i=0;i<n;i++)
  {
    for(NODE_T j=IA[i];j<IA[i+1];j++)
    {
      if(i<JA[j])
      {
        WeightEdge we;
        we.e.u = i;
        we.e.v = JA[j];
        we.weight = A[j];
        we.flag = 0;
        outList.push_back(we);
        //create reference entry if ref is set to 1
        /*if(ref==1)
        {
          RA[j] = count;
          //search vertex i on JA[j]'s adjacency list
          for(NODE_T jj=IA[JA[j]];jj<IA[JA[j]+1];jj++)
          {
            if(JA[jj]==i)
            {
              RA[jj] = count;
            }
          }
        }*/
        count++;
      }
    }
  }
}
void LightGraph::createRefArray()
{
  RA = new EDGE_T[2*m];
  for(NODE_T i=0;i<n;i++)
  {
    for(NODE_T j=IA[i];j<IA[i+1];j++)
    {
      if(i<JA[j])
      {
        RA[j] = j;
        for(NODE_T jj=IA[JA[j]];jj<IA[JA[j]+1];jj++)
          {
            if(JA[jj]==i)
            {
              RA[jj] = j;
            }
          }
      }
    }
  }

}
void LightGraph::printGraph(NODE_T offset)
{
  for(NODE_T i=0;i<n;i++)
  {
    for(NODE_T j=IA[i];j<IA[i+1];j++)
    {
      std::cout<<i+offset<<" "<<JA[j]<<" "<<A[j]<<std::endl; 
    }
  }
}
void BptGraph::printGraph()
{
  std::cout<<nA<<" "<<nB<<" "<<m<<std::endl;
  for(NODE_T i=0;i<nA;i++)
  {
    for(NODE_T j=IA[i];j<IA[i+1];j++)
    {
      std::cout<<i<<" "<<JA[j]<<" "<<A[j]<<std::endl; 
    }
  }
}
void LightGraph::printGraph()
{
  for(NODE_T i=0;i<n;i++)
  {
    for(NODE_T j=IA[i];j<IA[i+1];j++)
    {
      std::cout<<i<<" "<<JA[j]<<" "<<A[j]<<std::endl; 
    }
  }
}
