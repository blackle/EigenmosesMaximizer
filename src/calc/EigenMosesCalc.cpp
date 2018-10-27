#include "EigenMosesCalc.h"

arma::fvec EigenMosesCalc::calc(const arma::fmat& coop, uint iters) {
	arma::fmat coopDef = (coop*2.0 - 1.0).t();

	arma::cx_fvec eigenVals;
	arma::cx_fmat eigenVecs;

	// I know I can do the iterative method here, but I want to examine what the other eigenvectors are later
	arma::eig_gen(eigenVals, eigenVecs, coopDef);

	// I'm assuming it's ordered by eigenvalue...
	arma::fvec principal = arma::real(eigenVecs.col(0));
	principal /= arma::sum(principal);

	return principal;
}