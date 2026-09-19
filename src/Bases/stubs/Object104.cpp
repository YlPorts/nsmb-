#include "Object104.hpp"
#include "Object103.hpp"
#include "../../ProcessManager.hpp"

// The target still uses the unmangled name for this tile-query helper.
extern "C" u32 func_ov000_020a6d18(u32, u32);

void *Object104::create()
{
	return new Object104();
}

// 0x0218e1f0
ActorProfile Object104_Profile = { Object104::create, 104, 225, NULL };

s32 Object104::onDestroy()
{
	return 1;
}

void Object104::pendingDestroy()
{
}

bool Object104::onUpdate_0()
{
	u32 flags = func_ov000_020a6d18(this->position.x, this->position.y);
	if ((flags & 0x10000) != 0) {
		for (Base *object = ProcessManager::getNextObjectByObjectID(0x67, NULL);
		     object != NULL;
		     object = ProcessManager::getNextObjectByObjectID(0x67, object)) {
			if (this->_3f3 == static_cast<Object103 *>(object)->_4a8) {
				static_cast<Object103 *>(object)->_4a9 = 1;
				this->destroy(false);
				return true;
			}
		}
	}
	this->destroyInactive(0);
	return true;
}

s32 Object104::onCreate()
{
	this->_3f3 = this->settings & 0xF;
	this->visible = false;
	return 1;
}
