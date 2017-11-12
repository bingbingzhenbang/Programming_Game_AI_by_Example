#ifndef ENTITYNAMES_H
#define ENTITYNAMES_H

#include <string>

enum EntityName
{
	Entity_Miner_Bob,
	Entity_Elsa,
};

inline std::string GetNameOfEntity(int id)
{
	switch (id)
	{
	case Entity_Miner_Bob:
		return "Miner Bob";
		break;
	case Entity_Elsa:
		return "Elsa";
		break;
	default:
		return "Unknown";
		break;
	}
	return std::string();
}

#endif // ENTITYNAMES_H