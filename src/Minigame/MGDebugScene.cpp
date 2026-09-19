#include "MGDebugScene.hpp"

extern "C" void func_ov130_02126fc8(MGDebugScene *);
extern "C" void func_ov130_021271d0(MGDebugScene *);

bool MGDebugScene::preCreate()
{
	MGScene::preCreate();
}

bool MGDebugScene::preUpdate()
{
	bool a = MGScene::preUpdate();
	if (a != 0) {
		func_ov130_02126fc8(this);
		func_ov130_021271d0(this);
		return true;
	}
	return false;
}
