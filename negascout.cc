#include "othello_cut.h"
#include <limits>
#include <vector>
using namespace std;


int negascout(state_t s, int alpha, int beta, bool color) {
  if (s.terminal())
     return s.value();
  int b = beta;
  vector<int> succ_ = s.succ(color);
  for(vector<int>::const_iterator iter=succ_.begin(),limit=succ_.end();iter!=limit;++iter) {
    state_t n = s.move(!color,*iter);
    int score = -negascout(n,-b,-alpha,!color);
	if ((alpha < score) && (score < beta) && (iter!=succ_.begin()))
	  score = -negascout(n,-beta,-alpha,!color);
    alpha = max(alpha,score);
    if (alpha >= beta)
      return alpha;
    b = alpha + 1;	  
  }
  return alpha;
}

int main() {
  state_t root = state_t();
  
  int v = negascout(root,numeric_limits<int>::min(),numeric_limits<int>::max(),true);
  
  cout << v << endl;
}
