#include <prisoners/Prisoner.h>
#include <prisoners/AllCooperate.h>
#include <prisoners/AllDefect.h>
#include <prisoners/Stochastic.h>
#include <prisoners/TitForTat.h>
#include <prisoners/GrimTrigger.h>
#include <model/Jailhouse.h>
#include <calc/CooperationMatrixCalc.h>
#include <calc/EigenMosesCalc.h>

int main(int, char**) {
	PrisonerList prisoners({
		PrisonerPointer(new AllCooperate()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new Stochastic(0.25)),
		PrisonerPointer(new Stochastic(0.50)),
		PrisonerPointer(new Stochastic(0.75)),
		PrisonerPointer(new TitForTat()),
		PrisonerPointer(new GrimTrigger()),
	});

	Jailhouse jail(&prisoners, 200);
	jail.run();

	auto ledger = jail.ledger();

	auto coop = CooperationMatrixCalc::calc(ledger);
	auto scores = EigenMosesCalc::calc(coop);
	std::cout << coop << std::endl << scores;

	return 0;
}

// TODO:
//  * Calculate eigenmoses/good-partner-ranking and compare against python code