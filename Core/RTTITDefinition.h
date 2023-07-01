#pragma once
#include "RTTIDefinition.h"

template<typename DefinedClass>
class RTTITDefinition : public RTTIDefinition
{
public:
	RTTITDefinition() = delete;
	RTTITDefinition(const std::string_view& a_name, const unsigned short a_version) :
		RTTIDefinition(a_name, a_version) {}
	RTTITDefinition(const std::string_view& a_name, const unsigned short a_version,
		const std::vector<std::shared_ptr<RTTIDefinition>>& a_vParents) :
		RTTIDefinition(a_name, a_version, a_vParents) {}

	/*@brief size of described class*/
	[[nodiscard]] virtual size_t classSize()const noexcept { return sizeof(DefinedClass); }

	/*@brief create class*/
	std::shared_ptr<DefinedClass> create()
	{
		return std::make_shared<DefinedClass>();
	}
};
