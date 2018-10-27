#include <prisoners/Prisoner.h>
#include <prisoners/AllCooperate.h>
#include <prisoners/AllDefect.h>
#include <model/Jailhouse.h>

int main(int argc, char** argv) {
	PrisonerList prisoners({
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new AllCooperate()),
		PrisonerPointer(new AllCooperate()),
		PrisonerPointer(new AllCooperate()),
		PrisonerPointer(new AllCooperate()),
	});

	Jailhouse jail(&prisoners, 10);
	jail.run();

	auto ledger = jail.ledger();
	std::cout << *ledger;

	return 0;
}