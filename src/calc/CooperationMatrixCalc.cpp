#include "CooperationMatrixCalc.h"

arma::fmat CooperationMatrixCalc::calc(const Ledger* ledger) {
	auto numrounds = ledger->numRounds();
	auto numbots = ledger->numBots();
	arma::fmat coop(numbots, numbots, arma::fill::zeros);

	for (uint b1 = 0; b1 < numbots; b1++) {
		for (uint b2 = 0; b2 < numbots; b2++) {
			for (uint t = 0; t < numrounds; t++) {
				if ((*ledger)(b1, b2, t) == Action::Cooperate) {
					coop(b1, b2) += 1;
				}
			}
		}
	}

	return coop/numrounds;
}
