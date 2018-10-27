#include "Playback.h"

Playback::Playback(ActionLedger* ledger)
	: _ledger(ledger)
{}

Action Playback::decide(const PrisonerKnowledge& p) const {
	return _ledger->get(p.time, p.thisIndex, p.theirIndex);
}
