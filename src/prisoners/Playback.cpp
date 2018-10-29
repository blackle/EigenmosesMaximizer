#include "Playback.h"

Playback::Playback(arma::field<Action> actions)
	: _actions(actions)
{}

Action Playback::decide(const PrisonerKnowledge& p) const {
	return _actions(p.time, p.theirIndex);
}
