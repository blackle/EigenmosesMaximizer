#pragma once

#include "Prisoner.h"

class TitForTat : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
