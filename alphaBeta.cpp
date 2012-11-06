#include "othello_cut.h"
using namespace std;
int out = -1;

int alpha_beta_prunning(state_t n, int alpha, int beta, bool color){
  if (n.terminal()){
    return n.value();
  }

  vector<int> successors = n.succ(color);
  for (vector<int>::iterator sucesores =successors.begin(), limit=successors.end(); sucesores != limit; ++sucesores) {
    cout << *sucesores << " ";
  }
  
  cout << endl;
  if (successors.size()>0){
  if (color){
    cout << "nooooo, no e asi no eee" << endl;
    for (vector<int>::iterator sucesores =successors.begin(), limit=successors.end(); sucesores != limit;++sucesores){
      cout << "suc: " << *sucesores << endl;
      alpha = MAX(alpha, alpha_beta_prunning(n.move(color, *sucesores), alpha, beta, !color));
      cout << "siii" << endl;
        if (alpha >= beta) { break; }
    }

    return alpha;

  } else {

    cout << "siiii, si e asi si eee" << endl;

    for (vector<int>::iterator sucesores =successors.begin(), limit=successors.end(); sucesores != limit; ++sucesores){
      beta = MIN(beta, alpha_beta_prunning(n.move(color, *sucesores), alpha, beta, !color));
      cout << "nooo" << endl;
        if (alpha >= beta) { break; }
    }

    return beta;
  }
  }else{
    return alpha_beta_prunning(n,alpha,beta, !color);
  }
}


int main(){
  state_t root = state_t();
  root=root.move(true,12);
  cout << root;
  root=root.move(!true,21);
  cout << root;
  root=root.move(true,26);
  cout << root;
  root=root.move(!true,13);
  cout << root;
  root=root.move(true,22);
  cout << root;
  root=root.move(!true,18);
  cout << root;
  root=root.move(true,7);
  cout << root;
  root=root.move(!true,6);
  cout << root;
  root=root.move(true,5);
  cout << root;
  root=root.move(!true,27);
  cout << root;
  root=root.move(true,33);
  cout << root;
  root=root.move(!true,23);
  cout << root;
  root=root.move(true,17);
  cout << root;
  root=root.move(!true,11);
  cout << root;
  root=root.move(true,19);
  cout << root;
  root=root.move(!true,15);
  cout << root;
  root=root.move(true,14);
  cout << root;
  root=root.move(!true,31);
  cout << root;
  root=root.move(true,20);
  cout << root;
  root=root.move(!true,32);
  cout << root;
  root=root.move(true,30);
  cout << root;
  // root=root.move(!true,10);
  cout << root;
  //root=root.move(true,25);
  cout << root;
  //  root=root.move(!true,24);
  cout << root;
  //root=root.move(true,34);
  cout << root;
  //root=root.move(!true,28);
  cout << root;
  // root=root.move(true,16);
  cout << root;
  // root=root.move(!true,4);
  cout << root;
  // root=root.move(true,29);
  cout << root;
  // root=root.move(!true,35);
  cout << root;
  //  root=root.move(true,36);
  cout << root;
  //root=root.move(!true,8);
  cout << root;
  //root=root.move(true,9);
  cout << root;
  cout << "Valor:";
  cout << root.value() << endl;

  vector<int> pepe;
  int v = alpha_beta_prunning(root, -2147483647, 2147483647,!true);
  state_t result = state_t(v);
  cout << v << endl;
  cout << out << endl;

  
  
  return 0;
}
