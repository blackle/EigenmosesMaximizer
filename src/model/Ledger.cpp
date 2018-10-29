#include "Ledger.h"

Ledger::Ledger(uint numBots, uint numRounds)
	: _field(numBots, numBots, numRounds)
{
}

Ledger::~Ledger() {
}

Action& Ledger::operator()(uint b1, uint b2, int time) {
	// here we want to do a modifying access, so just defer to super::operator()
	return _field(b1, b2, time);
}

const Action& Ledger::operator()(uint b1, uint b2, int time) const {
	if (_field.in_range(b1, b2, time)) {
		return _field.at(b1, b2, time);
	} else {
		static const Action undefined = Action::Undefined;
		return undefined;
	}
}

uint Ledger::numRounds() const {
	return _field.n_slices;
}

uint Ledger::numBots() const {
	return _field.n_rows;
}

std::ostream& operator<<(std::ostream& o, const Ledger& ledger) {
	o << ledger._field;
	return o;
}
