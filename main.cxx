#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

namespace{

struct node_t{
  int value;
  vector<node_t*> neighbors;
}Node;

} // namespace



bool isRoute(node_t *start, node_t *end);

int main(){

  node_t a,b,c,d,e,f,g,h,i,j,k;

  node_t start;
  start.value = -1;
  start.neighbors.push_back(&a);
  start.neighbors.push_back(&b);
  start.neighbors.push_back(&c);

  a.neighbors.push_back(&start);
  a.value = -1;

  b.neighbors.push_back(&a);
  b.neighbors.push_back(&b);
  b.neighbors.push_back(&c);
  b.neighbors.push_back(&d);
  b.neighbors.push_back(&e);
  b.value = -1;

  c.neighbors.push_back(&e);
  c.neighbors.push_back(&f);
  c.neighbors.push_back(&g);
  c.value = -1;

  f.neighbors.push_back(&h);
  f.neighbors.push_back(&i);
  f.neighbors.push_back(&a);
  f.value = -1;

  i.neighbors.push_back(&j);
  i.value = -1;

  j.neighbors.push_back(&start);
  j.value = -1;

  // cyclic graph


  // do they have a route?

  cout << "start and j" <<endl;
  if(isRoute(&start, &j)){
    cout << "yes, they have a route" << endl;
  }else{
    cout << "sorry, no route" << endl;
  }

  cout << "i and j" <<endl;
  if(isRoute(&i, &j)){
    cout << "yes, they have a route" << endl;
  }else{
    cout << "sorry, no route" << endl;
  }

  cout << "a and k" <<endl;
  if(isRoute(&a, &k)){
    cout << "yes, they have a route" << endl;
  }else{
    cout << "sorry, no route" << endl;
  }

  return EXIT_SUCCESS;
}

bool isRoute(node_t *start, node_t *end){

  if( !start ){
    return false;
  }
  if( start == end ){
    return true;
  }

  // to avoid cyclic graphs, mark a node dirty after we've seen it
  start->value = 1;

  for(unsigned int i=0; i < start->neighbors.size(); ++i){
    node_t *node = start->neighbors[i];
    if( node && node->value != 1 && isRoute(node, end) ){
      return true;
    }
  }
  return false;
}
