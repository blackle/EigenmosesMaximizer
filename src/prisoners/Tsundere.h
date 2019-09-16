#pragma once

#include "Prisoner.h"

class Tsundere : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
