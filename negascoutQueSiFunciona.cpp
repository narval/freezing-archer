#include "othello_cut.h"
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

int F_(state_t n, int alpha, int beta, bool color);
int G_(state_t n, int alpha, int beta, bool color);

int negascout(state_t n, int alpha, int beta, bool color){
	if (color) {
    return F_(n, alpha, beta, color);
	} else {
    return G_(n, alpha, beta, color);
  }
}

int F_(state_t n, int alpha, int beta, bool color) {
  if (n.terminal()) {
    return n.value();
  }
  
  int m = numeric_limits<signed int>::min();
  vector<int> succ_ = n.succ(color);
  if (succ.size() != 0){
    state_t jugada = n.move(succ_.front(), color);
    succ_.erase(succ_.begin());
    int valor = G_(jugada, alpha, beta, !color);
    m = MAX(m, valor);
    if ( m >= beta) {
      return m;
    }  
    
    for(vector<int>::const_iterator iter=succ_.begin(),limit=succ_.end();iter!=limit;++iter) {
        jugada = n.move(*iter,color);
        int t = G_(jugada,m,m + 1,!color);
        if(t > m) {
          if(t >= beta) {
            m = t;
          }
          else {
            m = G_(jugada,t,beta,!color);
          }
        }
        if(m >= beta) {
          return beta;
        }
    }
  } else {
    state_t jugada = n.move();
  }
  return m;
}

int G_(state_t n, int alpha, int beta, bool color) {
  if (n.terminal()) {
    return n.value();
  }
  
  int m = numeric_limits<signed int>::max();
  vector<int> succ_ = n.succ(color);
  state_t jugada = n.move(succ_.front(), color);
  bool pasar = succ.size() == 0 ? true : false;
  succ_.erase(succ_.begin());
  int valor = G_(jugada, alpha, beta, !color);
  m = MIN(m, valor);
  if ( m <= alpha) {
    return m;
  }  
  
  for(vector<int>::const_iterator iter=succ_.begin(),limit=succ_.end();iter!=limit;++iter) {
      jugada = n.move(*iter,color);
      int t = F_(jugada,m,m + 1,!color);
      if(t <= m) {
        if(t <= alpha) {
          m = t;
        }
        else {
          m = F_(jugada,alpha,t,!color);
        }
      }
      if(m <= alpha) {
        return alpha;
      }
  }  
  return m;
}

int main(){}