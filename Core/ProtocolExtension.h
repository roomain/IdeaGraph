#pragma once
#include "RTTI_Macros.h"

class ProtocolExtension
{
	DECLARE_RTTI(0, ProtocolExtension)
public:
	ProtocolExtension() = default;
	virtual ~ProtocolExtension() = default;
};