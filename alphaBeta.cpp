

int alpha_beta_prunning(state_t n, int d, int alpha, int beta, bool color){
	if (n.terminal() || d == 0){
		return n.value();
	}

	vector<int> successors = succ();
	if (color){
		for (int i; i < successors.size(); ++i){
			alpha = MAX(alpha, alpha_beta_prunning(succesors[i], alpha, beta, 0))
			if (alpha >= beta) { break; }
		}
		return alpha;
	} else {
		for (int i; i < successors.size(); ++i){
			beta = MIN(beta, alpha_beta_prunning(succesors[i], alpha, beta, 1))
			if (alpha >= beta) { break; }
		}
		return beta;
	}

}