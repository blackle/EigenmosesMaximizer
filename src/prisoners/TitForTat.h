#pragma once

#include "Prisoner.h"

class TitForTat : public Prisoner {
	Action decide(const PrisonerKnowledge& p) const;
};
