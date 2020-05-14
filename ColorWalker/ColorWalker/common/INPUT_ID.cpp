#include "INPUT_ID.h"
#include <type_traits>

INPUT_ID begin(INPUT_ID)
{
	return INPUT_ID::LEFT;
}

INPUT_ID end(INPUT_ID)
{
	return INPUT_ID::MAX;
}

INPUT_ID operator*(INPUT_ID key)
{
	return static_cast<INPUT_ID>(key);
}

INPUT_ID operator++(INPUT_ID & key)
{
	return key = INPUT_ID(std::underlying_type<INPUT_ID>::type(key) + 1);
}

INPUT_ID operator--(INPUT_ID & key)
{
	return key = INPUT_ID(std::underlying_type<INPUT_ID>::type(key) - 1);
}
