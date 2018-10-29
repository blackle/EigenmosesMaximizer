#pragma once

#include <model/Ledger.h>
#include <armadillo>

class CooperationMatrixCalc {
public:
	static arma::fmat calc(const Ledger* ledger);
};
