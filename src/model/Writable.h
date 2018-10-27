#pragma once

template<typename Type, typename... Indexes>
class Writable {
public:
	virtual bool set(Type val, Indexes... indexes) = 0;
};
