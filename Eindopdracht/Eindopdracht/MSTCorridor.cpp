#include "MSTCorridor.h"

MSTCorridor::MSTCorridor(Room* start, Room* end)
{
	startRoom = start;
	endRoom = end;
}

MSTCorridor::~MSTCorridor()
{
}

int MSTCorridor::GetWeight() const
{
	return endRoom->GetWeight();
}

Room* MSTCorridor::GetEndRoom() const
{
	return endRoom;
}
