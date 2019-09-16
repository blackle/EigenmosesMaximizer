#pragma once

#include <armadillo>

class ExpMosesCalc {
public:
	static arma::fvec calc(const arma::fmat& coop);
};
