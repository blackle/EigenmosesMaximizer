#pragma once

#include <ostream>

enum class Action {
	Undefined = 0,
	Cooperate = 1,
	Defect = -1,
};

Action operator~(const Action& action);

std::ostream& operator<<(std::ostream& o, const Action& action);
