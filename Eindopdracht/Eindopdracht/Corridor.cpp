#include "Corridor.h"

Corridor::Corridor(char corridorType)
{
	switch (corridorType)
	{
	case 'H':
		horizontal = true;
		break;
	case 'V':
		vertical = true;
		break;
	case 'C':
		collapsed = true;
		break;
	default:
		break;
	}
}

void Corridor::Print()
{
	if (horizontal)
		cout << '-';
	else if (vertical)
		cout << '|';
	else if (collapsed)
		cout << '~';
	else
		cout << ' ';
}