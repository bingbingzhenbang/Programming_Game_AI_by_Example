#ifndef MESSAGETYPES_H
#define MESSAGETYPES_H

#include <string>

enum MessageType
{
	Message_HiHoneyImHome,
	Message_StewReady,
};

inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case Message_HiHoneyImHome:
		return "HiHoneyImHome";
		break;
	case Message_StewReady:
		return "StewReady";
		break;
	default:
		return "Unknown";
		break;
	}
	return std::string();
}

#endif // MESSAGETYPES_H