#include <iostream>
#include "src/Action.h"
#include "src/Readable.h"
#include "src/Writable.h"
#include "src/ActionLedger.h"


// class AllCooperate : public Prisoner {
// 	Action decide(const PrisonerKnowledge& p) const;
// };

// Action AllCooperate::decide(const PrisonerKnowledge& p) const {
// 	return Action::Cooperate;
// }

// class AllDefect : public Prisoner {
// 	Action decide(const PrisonerKnowledge& p) const;
// };

// Action AllDefect::decide(const PrisonerKnowledge& p) const {
// 	return Action::Defect;
// }

// class Stochastic : public Prisoner {
// 	Action decide(const PrisonerKnowledge& p) const;
// };

// Action Stochastic::decide(const PrisonerKnowledge& p) const {
// 	//please implement me
// 	return Action::Defect;
// }

// class TitForTat : public Prisoner {
// 	Action decide(const PrisonerKnowledge& p) const;
// };

// Action TitForTat::decide(const PrisonerKnowledge& p) const {
// 	//please implement me
// 	return Action::Defect;
// }


// int main(int argc, char** argv) {
// 	auto ledger = new ActionLedger(5, 5);

// 	ledger->set(Action::Defect, 0, 0, 0);
// 	readFromReadable(ledger);

// 	delete ledger;
// 	return 0;
// }