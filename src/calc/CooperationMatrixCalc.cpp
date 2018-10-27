#include "CooperationMatrixCalc.h"

arma::fmat CooperationMatrixCalc::calc(const ReadableActionLedger* ledger) {
	auto dim = ledger->dim();
	auto numrounds = std::get<0>(dim);
	auto numbots = std::get<1>(dim);
	arma::fmat coop(numbots, numbots, arma::fill::zeros);

	for (uint b1 = 0; b1 < numbots; b1++) {
		for (uint b2 = 0; b2 < numbots; b2++) {
			for (uint t = 0; t < numrounds; t++) {
				if (ledger->get(t, b1, b2) == Action::Cooperate) {
					coop(b1, b2) += 1;
				}
			}
		}
	}

	return coop/numrounds;
}
