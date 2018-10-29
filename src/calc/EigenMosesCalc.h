#pragma once

#include <armadillo>

class EigenMosesCalc {
public:
	static arma::fvec calc(const arma::fmat& coop, uint iters = 10);
};
