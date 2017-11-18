#ifndef RANDOM_H
#define RANDOM_H

#include <random>

inline double RandomDouble()
{
	static std::default_random_engine e;
	static std::uniform_real_distribution<double> u(0.0, 1.0);
	return u(e);
}

#endif // RANDOM_H