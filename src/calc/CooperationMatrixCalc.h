#pragma once

#include <model/ActionLedger.h>
#include <armadillo>

class CooperationMatrixCalc {
public:
	static arma::fmat calc(const ReadableActionLedger* ledger);
};
