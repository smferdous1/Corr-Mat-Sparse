#ifndef GRAPH_H
#define GRAPH_H


#include<vector>
//defining types. 
//
//Change this to float/double if the weight of the graph is real  
typedef double VAL_T;
//Change this to long if number of nodes does not fit into integer
typedef int NODE_T;
//Change this to long if number of edges does not fit into integer
typedef int EDGE_T;
typedef double SUM_T;

struct Edge
{
  NODE_T u;
  NODE_T v;
};


struct WeightEdge
{

  Edge e;
  VAL_T weight;
  bool flag;
};

struct RefEdge
{
  WeightEdge we;
  EDGE_T ref;
};

//to hold list of edges.
typedef std::vector<Edge> EdgeList;
typedef std::vector<WeightEdge> WeightEdgeList;
typedef std::vector<VAL_T> WeightList;

class LightGraph
{
  
  //number of nodes in the graph
  NODE_T n; 
  //number of edges in the graph
  EDGE_T m;
  
  public:  
  //default constructor
  LightGraph()
  {
  
  }
  //constructor
  LightGraph(NODE_T n1, EDGE_T m1)
  {
    n = n1;
    m = m1;

    //allocate memory for A,IA and JA
    //graph is recorded as symmetric matrix. thats why we need 2*m
    A = new VAL_T[2*m+5];
    IA = new NODE_T[n+5];
    JA = new EDGE_T[2*m];
    //RA is a reference array. Given a undirected graph as an edgeList. it create the references needed to go back and forth to the three arrays and edgeList.
    RA = new EDGE_T[2*m];
  }
  //delete the graph
  ~LightGraph()
  {
    n = 0;
    m = 0;
    delete []A;
    delete []IA;
    delete []JA;
  }
  
  
  //Graph is always in CSR format
  VAL_T *A;
  NODE_T *IA;
  EDGE_T *JA;
  EDGE_T *RA;
  void setNumberEdges(EDGE_T m1)
  {
    m = m1;
  }
  EDGE_T numberOfEdges()
  {
    return m;
  }
 

  void setNumberNodes(NODE_T n1)
  {
    n = n1;
  }
  NODE_T numberOfNodes()
  {
    return n;
  }
  
  //void createEdgeList(EdgeList &);
  //this create edgelist and if bool=1 it also create the G.RA array
  void createEdgeList(WeightEdgeList &,bool=0);
  
};






#endif
