#pragma once

#include "Prisoner.h"
#include <armadillo>

class Playback : public Prisoner {
public:
	explicit Playback(const arma::field<Action>& actions);
	Action decide(const PrisonerKnowledge& p) const;
private:
	const arma::field<Action> _actions;
};
