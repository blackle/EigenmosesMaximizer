#pragma once

#include "Action.h"
#include <armadillo>

class Ledger : private arma::field<Action> {
public:
	Ledger(uint numBots, uint numRounds);
	virtual ~Ledger();

	Action& operator()(uint b1, uint b2, int time);
	const Action& operator()(uint b1, uint b2, int time) const;

	uint numRounds() const;
	uint numBots() const;

private:
	typedef arma::field<Action> super;
};