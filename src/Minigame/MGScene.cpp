#include "MGScene.hpp"

extern u8 data_0208b578;
extern u32 data_ov130_02139700;
extern u8 data_0203d2ac;
extern u32 data_0208b658;
extern u8 data_020887e0;
extern MGScene *data_0208b61c;
extern u32 data_0208b5e0;
extern "C" void func_ov130_02122ba8(u32 *);
extern "C" void func_ov130_021229d4();
extern "C" void func_ov130_02122db8();
extern "C" void func_0200e61c();
extern "C" void func_0200e944(u32, u32, u32);
extern "C" void func_0200e874(u32, u32, u32);

#pragma thumb on

MGScene::MGScene()
{
	this->skipFlags |= 1;
	this->skipFlags |= 4;
}

bool MGScene::preCreate()
{
	if (!func_02024e50())
		return false;
	func_02024e94();
	_5c = 0x3ff;
	_60 = 0xf;
	return true;
}

void MGScene::postCreate(u32 result)
{
	func_0200e944(_5c, _60, 0);
	Object::postCreate(result);
}

bool MGScene::preDestroy()
{
	if (!Base::preDestroy())
		return false;
	if (data_0208b578)
		func_ov130_02122ba8(&data_ov130_02139700);
	return true;
}
void MGScene::postDestroy(u32 result)
{
	if (result == 2)
		data_0203d2ac = 0;
	if (object_id == 0x146)
		func_02024ad0(&data_0208b658);
	if (data_020887e0) {
		func_ov130_021229d4();
		func_0200e61c();
	}
	Base::postDestroy(result);
}
bool MGScene::preUpdate()
{
}
void MGScene::postUpdate(u32 result)
{
	Base::postUpdate(result);
}
bool MGScene::preRender()
{
	if (!Base::preRender())
		return false;
	func_0200e874(_5c, _60, 0);
	return true;
}
void MGScene::postRender(u32 result)
{
	Base::postRender(result);
}

bool MGScene::func_02024e50()
{
	data_0208b61c = this;
	if (!Base::preCreate())
		return false;
	func_02024ad0(&data_0208b658);
	data_0208b5e0 = 0;
	if (data_0208b578)
		func_ov130_02122db8();
	return true;
}

#pragma thumb off
