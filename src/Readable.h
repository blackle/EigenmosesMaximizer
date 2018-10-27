#pragma once

template<typename Type, typename... Indexes>
class Readable {
public:
	virtual Type get(Indexes... indexes) const = 0;
};
