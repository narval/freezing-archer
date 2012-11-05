

int minMax(n,d, color) {
	if (n.terminal() || d == 0){
		return n.value();
	}

	std::vector<int> valid_moves;
        for( int pos = 0; pos < DIM; ++pos ) {
            if( (color && is_black_move(pos)) || (!color && is_white_move(pos)) ) {
                valid_moves.push_back(pos);
            }
        }

		for (int i; i < successors.size(); ++i){
			alpha = MAX(alpha, minMax(succesors[i], d-1, color))
		}
		return alpha;
}