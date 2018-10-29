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
	std::cout << (*ledger);

	auto coop = CooperationMatrixCalc::calc(ledger);
	auto scores = EigenMosesCalc::calc(coop);
	std::cout << coop << std::endl << scores;

	return 0;
}

// TODO:
//  * consider giving the bots state for speed, but keep them const, and pass lambdas that create them into Jailhouse so if we want to reset their state later we can just realloc them
//  * figure out the deal with passing uint vs int into the various places
