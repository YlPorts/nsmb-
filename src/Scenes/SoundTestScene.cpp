#include "SoundTestScene.hpp"

void func_02011b64();
namespace Nitro
{
void func_02061274();
void func_02061260();
void func_0206123c();
void func_02061218();
void func_02061204();
void func_020611f0();
void func_020611dc();
void func_020611c8();
void func_020611b4();
void func_0206118c();
void func_02061164();
void func_02061494(u32);
void func_02061958(u32);
void func_02061474(u32);
void func_02060d78(u32, u32, u32);
void func_02066edc(u32, u32, u32);
u32 func_02062264();
} // namespace Nitro

void *SoundTestScene::create()
{
	return new SoundTestScene();
}

s32 SoundTestScene::onCreate()
{
	Nitro::func_02061274();
	Nitro::func_02061260();
	Nitro::func_0206123c();
	Nitro::func_02061218();
	Nitro::func_02061204();
	Nitro::func_020611f0();
	Nitro::func_020611dc();
	Nitro::func_020611c8();
	Nitro::func_020611b4();
	Nitro::func_0206118c();
	Nitro::func_02061164();
	Nitro::func_02061588(3);
	Nitro::func_02061494(0x10);
	Nitro::func_02061ac4(4);
	Nitro::func_02061958(0x60);
	Nitro::func_02061474(8);
	Nitro::func_02060d78(1, 0, 1);
	data_02085a88 = 0x12;
	// TODO: Turn these into macros?
	REG_DISPCNT &= ~0x7000000;
	REG_DISPCNT = REG_DISPCNT & ~0x38000000 | 0x8000000;
	REG_BG1CNT = (REG_BG1CNT & ~0x3);
	REG_BG1CNT = (REG_BG1CNT & 0x43) | 0x2810;
	REG_BG1CNT &= ~0x40;
	REG_BG1OFS = 0;
	u32 uVar1 = Nitro::func_02062264();
	Nitro::func_02066edc(0, uVar1, 0x800);
	this->_64 = 0;
	this->_68 = 0;
	this->_6c = 0;
	func_02011b64();
	return true;
}

s32 SoundTestScene::onDestroy()
{
	func_02011d40();
	return true;
}
void SoundTestScene::pendingDestroy()
{
}

s32 SoundTestScene::onRender()
{
	return true;
}

// Original helper is currently tracked under its unmangled symbol.
extern "C" bool func_02007cb0(Fader *);

i32 SoundTestScene::onUpdate()
{
	if (!func_02007cb0(&GlobalFader))
		return 1;

	u16 keys = *rcast<u16 *>((u32)&data_02087650 + (Input::localConsoleID << 2));
	if ((u16)(keys & 0xC) == 0xC) {
		func_02011e3c(0x1E);
		func_020131fc(2, 0);
	}

	// These two legacy helpers take addresses in their first ARM register.
	func_0200a42c((u32)&this->_64, 2);
	switch (this->_64) {
	case 0:
		func_0200a3d0((u32)&this->_68, 0x70);
		keys = *rcast<u16 *>((u32)&Input::consoleKeys + (Input::localConsoleID << 2));
		if (keys & 2) {
			func_02011d40();
		} else if (keys & 1) {
			func_02011e7c(this->_68, 0);
		}
		break;
	case 1:
		func_0200a3d0((u32)&this->_6c, 0x1C3);
		keys = *rcast<u16 *>((u32)&Input::consoleKeys + (Input::localConsoleID << 2));
		if (keys & 2) {
			func_02011d40();
		} else if (keys & 1) {
			func_02012398(this->_6c, 0);
		} else if (keys & 0x400) {
			func_02012290(this->_6c, 0);
		}
		break;
	}
	return 1;
}
