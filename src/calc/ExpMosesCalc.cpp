#include "ExpMosesCalc.h"

arma::fvec ExpMosesCalc::calc(const arma::fmat& coop) {
	arma::fmat coopDef = (coop*2.0 - 1.0).t();
	arma::fmat expmat = (arma::expmat(coopDef) - arma::eye<arma::fmat>(arma::size(coopDef))) / exp(coop.n_rows);

	return arma::sum(expmat.t(), 1);
}