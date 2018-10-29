#include "AllDefect.h"

Action AllDefect::decide(const PrisonerKnowledge&) const {
	return Action::Defect;
}
