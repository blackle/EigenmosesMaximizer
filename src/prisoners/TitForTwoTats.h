#pragma once

#include "Prisoner.h"

class TitForTwoTats : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
