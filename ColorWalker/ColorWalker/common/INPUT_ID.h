#pragma once

enum class INPUT_ID
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	BTN_1,		// Z
	BTN_2,		// X
	BTN_3,		// A
	BTN_4,		// S
	MAX
};

INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);

INPUT_ID operator*(INPUT_ID key);
INPUT_ID operator++(INPUT_ID & key);
INPUT_ID operator--(INPUT_ID & key);
