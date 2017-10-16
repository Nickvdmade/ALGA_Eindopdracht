#pragma once

#include "Room.h"

class MSTCorridor
{
private:
	Room* startRoom;
	Room* endRoom;

public:
	MSTCorridor(Room*, Room*);
	~MSTCorridor();
	int GetWeight() const;
	Room* GetEndRoom() const;
	void Collapse() const;
};

