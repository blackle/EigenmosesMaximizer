#include "Playback.h"

Playback::Playback(const arma::field<Action>& actions)
	: _actions(actions)
{}

Action Playback::decide(const PrisonerKnowledge& p) const {
	return _actions(p.time, p.theirIndex);
}
