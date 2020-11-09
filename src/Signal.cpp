#include "Signal.hpp"

Signal& operator<<(Signal& sig, const Sample& sample)
{
	sig.buffer.push_back(sample);
	return sig;
}

Signal& operator>>(Signal& sig, Sample& sample)
{
	if (sig.buffer.size() == 0)
		sample = invalidSample;
	else
	{
		sample = sig.buffer[0];
		sig.buffer.pop_front();
	}

	return sig;
}