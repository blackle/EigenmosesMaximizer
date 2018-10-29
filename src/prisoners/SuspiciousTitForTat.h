#pragma once

#include "Prisoner.h"

class SuspiciousTitForTat : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
