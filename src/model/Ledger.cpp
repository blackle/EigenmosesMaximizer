#include "Ledger.h"

Ledger::Ledger(uint numBots, uint numRounds)
	: super(numBots, numBots, numRounds)
{
}

Ledger::~Ledger() {
}

Action& Ledger::operator()(uint b1, uint b2, int time) {
	// here we want to do a modifying access, so just defer to super::operator()
	return super::operator()(b1, b2, time);
}

const Action& Ledger::operator()(uint b1, uint b2, int time) const {
	if (super::in_range(b1, b2, time)) {
		return super::at(b1, b2, time);
	} else {
		static const Action undefined = Action::Undefined;
		return undefined;
	}
}

uint Ledger::numRounds() const {
	return super::n_slices;
}

uint Ledger::numBots() const {
	return super::n_rows;
}