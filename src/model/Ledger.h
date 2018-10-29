#pragma once

#include "Action.h"
#include <armadillo>

class Ledger {
public:
	Ledger(uint numBots, uint numRounds);
	virtual ~Ledger();

	Action& operator()(uint b1, uint b2, int time);
	const Action& operator()(uint b1, uint b2, int time) const;

	uint numRounds() const;
	uint numBots() const;

	friend std::ostream& operator<<(std::ostream& o, const Ledger& ledger);

private:
	typedef arma::field<Action> super;

	arma::field<Action> _field;
};