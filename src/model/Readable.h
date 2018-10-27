#pragma once

#include <tuple>

template<typename Type, typename... Indexes>
class Readable {
public:
	virtual Type get(Indexes... indexes) const = 0;
	virtual std::tuple<Indexes...> dim() const = 0;

	template<typename T, typename... I> friend std::ostream& operator<<(std::ostream& os, const Readable<T, I...>& readable);
};

template<typename Type, typename... Indexes>
std::ostream& operator<<(std::ostream& os, const Readable<Type, Indexes...>& ledger) {
	return os;
}
