#include "EigenMosesCalc.h"

arma::fvec EigenMosesCalc::calc(const arma::fmat& coop, uint iters) {
	arma::fmat coopDef = (coop*2.0 - 1.0).t();
	auto n_rows = coopDef.n_rows;

	arma::fvec scores(n_rows, arma::fill::ones);

	for (uint i = 0; i < iters; i++) {
		scores = coopDef * scores;
		scores *= 1.0/arma::sum(scores);
	}

	return scores;
}