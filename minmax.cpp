#include "othello_cut.h"
using namespace std;
int out = -1;
int alpha;

int minMax(state_t n,int d,bool color, vector<int> pepe) {
  cout << "existo" << endl;
  for (vector<int>::iterator iter =pepe.begin(), limit=pepe.end(); iter != limit; ++iter) cout << *iter << " ";
  cout << endl;

  if (n.terminal() ){
    cout << "terminal" << endl;
    cout << "alpha: " ;
    cout << n.value() << endl;
    cout << endl;
    cout << endl;
    cout << n;
    cout << endl;
    cout << endl;


    return n.value();
  }
  alpha = -2147483647;
  //cout << DIM;
  bool succ= false;

  for( int pos = 0; pos < DIM; ++pos ) {
    cout << "pos " << pos << endl;

    if( (color && n.is_black_move(pos)) || (!color && n.is_white_move(pos)) ) {

      succ=true;
      int aux = alpha;
      pepe.push_back(pos);
      state_t hijo = state_t();
      hijo = n;
      cout << "chao "<< pos << endl;
      alpha= MAX(alpha,-minMax(hijo.move(color,pos),pos,!color, pepe));
      pepe.pop_back();
      if (alpha!=aux){
        out=pos;
      }
    }
  }

  if(!succ){
    cout << "color: " ;
    cout << color << endl ;
    pepe.push_back(36);
    alpha=minMax(n,d,!color, pepe);
    out=36;
    }

  return alpha;

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
  root=root.move(!true,10);
  cout << root;
  root=root.move(true,25);
  cout << root;
  root=root.move(!true,24);
  cout << root;
  root=root.move(true,34);
  cout << root;
  root=root.move(!true,28);
  cout << root;
  root=root.move(true,16);
  cout << root;
  root=root.move(!true,4);
  cout << root;
  root=root.move(true,29);
  cout << root;
   root=root.move(!true,35);
  cout << root;
  root=root.move(true,36);
  cout << root;
  //root=root.move(!true,8);
  cout << root;
  //root=root.move(true,9);
  cout << root;
  cout << "Valor:";
  cout << root.value() << endl;

  vector<int> pepe;
  int v = minMax(root,out,!true, pepe);
  state_t result = state_t(v);
  cout << v << endl;
  cout << out << endl;

  
  
  return 0;
}
