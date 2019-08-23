// Made by Christopher Williamson

#include "InteractiveObjectInterface.h"

// Add default functionality here for any IInteractiveObjectInterface functions that are not pure virtual.

void IInteractiveObjectInterface::SetState(std::string StateToSet)
{
	state = StateToSet;
	return;
}
