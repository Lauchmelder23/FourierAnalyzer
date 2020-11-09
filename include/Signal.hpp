#pragma once

#include <complex>
#include <deque>

typedef std::complex<double> CmplxDouble;

typedef struct {
	double t;
	CmplxDouble val;
	bool valid = true;
} Sample;

static const Sample invalidSample{ 0.f, 0.f, false };

class Signal
{
public:
	Signal() = default;
	~Signal() = default;

	friend Signal& operator<<(Signal& sig, const Sample& sample);
	friend Signal& operator>>(Signal& sig, Sample& sample);

private:
	std::deque<Sample> buffer;
};