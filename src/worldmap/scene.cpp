#include "scene.hpp"
#include "../AAA.hpp"
#include "../Vec.hpp"
#include "../menu/OptionsMenu.hpp"
#include "playermodel.hpp"
#include "../objectid.hpp"
#include "../system/vblank.hpp"


extern "C" u8 func_ov008_020cda24(u32 world, u32 path, u8 mask)
{
    return mask & WM::worlds[world].paths[path].flag;
}

extern "C" u16 func_ov008_020cda4c(u32 world, u32 node, u16 mask)
{
    return mask & WM::worlds[world].nodes[node].flag;
}

extern "C" u16 func_ov008_020cda7c(u32 world)
{
    return WM::worlds[world].nodeCount;
}

extern "C" WM::NodeLink* func_ov008_020cda94(u32 world, u32 node)
{
    return WM::worlds[world].nodes[node].links;
}

extern "C" bool func_ov008_020cdab8(u32 world)
{
    WM::Node* node = WM::worlds[world].nodes;
    u8 nodeCount = WM::worlds[world].nodeCount;
    u8 nodeID = 0;

    if (nodeCount != 0) {
        do {
            if ((node->flag & WM::NF_Final) != 0) {
                u8 nodeState = save.game.nodeStates[world][nodeID] & WM::NS_Completed;
                if (nodeState != 0) {
                    return true;
                }
            }
            nodeID++;
            node++;
        } while (nodeID < nodeCount);
    }

    return false;
}

extern "C" {
extern u32 data_ov008_020e2d3c[];
extern fx32 data_ov008_020e2d58[][3];
extern fx32 data_ov008_020e2d5c[][3];
extern fx32 data_ov008_020e2d60[][3];
extern u32 data_ov008_020e650c[];
extern u32 data_ov008_020e6714[][2];
extern u32 data_ov008_020e6bf0[][3];
extern u32 data_ov008_020e6bf4[][3];
extern u32 data_ov008_020e6bf8[][3];
extern u32 data_ov008_020e77a4[][2][4];
extern u32 data_ov008_020e77a8[][2][4];
extern u32 data_ov008_020e77ac[][2][4];
extern u32 data_ov008_020e77b0[][2][4];
extern u32 data_ov008_020e8794[][16];
extern u8 data_ov008_020e5cc8[];
extern u8 data_ov008_020ee380;
}

struct WmTextBoxOpaque {};
struct WmTextBoxMessagePrefix { u8 padding000[0x14e]; u8 unk14E; };
extern "C" WmTextBoxOpaque data_ov008_020ee58c;
extern "C" u8 data_ov008_020ee374;
extern "C" int data_ov008_020e64ec[][2];
extern "C" u32 data_ov008_020ee3f4;
extern "C" void func_020144bc(WmTextBoxOpaque*, int, int, int);
extern "C" void func_020145f8(WmTextBoxOpaque*, int, int);
extern "C" WmTextBoxMessagePrefix* func_ov008_020cdc30(int, int, int);

extern "C" u8 data_ov008_020ee378;
extern "C" u8 data_ov008_020ee37c;
extern "C" u8 data_ov008_020ee398;
extern "C" u32 data_ov008_020ee3d0;
extern "C" s32 data_ov008_020ee3e0;
extern "C" u32 data_ov008_020ee3f0;

extern "C" void func_ov008_020cdb44(u32 sceneID, u32 settings)
{
    func_02011e3c(0x1e);
    func_020131fc(sceneID, settings);
}

extern "C" u8 func_ov008_020cdcac(u32 index)
{
    u8* values = &data_ov008_020e5cc8[index * 2];
    return values[data_ov008_020ee380];
}

extern "C" void func_ov008_020cdccc(u32 lastWorld)
{
    u32 world = 0;
    do {
        save.game.worldStates[world] |= 0x3e;
        world++;
    } while (world <= lastWorld);
}

extern "C" u32 func_ov008_020ce0d4(u32 index)
{
    return data_ov008_020e2d3c[index];
}

extern "C" Vec3_32 func_ov008_020ce0e4(u32 index)
{
    Vec3_32 result;
    result.x = data_ov008_020e2d58[index][0];
    result.y = data_ov008_020e2d5c[index][0];
    result.z = data_ov008_020e2d60[index][0];
    return result;
}

extern "C" u32 func_ov008_020ce12c(u32 index)
{
    return data_ov008_020e650c[index];
}

extern "C" u32 func_ov008_020ce13c(u32 index)
{
    return data_ov008_020e6bf8[index][0];
}

extern "C" u32 func_ov008_020ce154(u32 index)
{
    return data_ov008_020e6bf4[index][0];
}

extern "C" u32 func_ov008_020ce16c(u32 index)
{
    return data_ov008_020e6bf0[index][0];
}

extern "C" fx32 func_ov008_020ce1b4(u32 index)
{
    return data_ov008_020e6714[index][0];
}

extern "C" u32 func_ov008_020ce1c4(u32 row, u32 column)
{
    return data_ov008_020e77b0[row][column][0];
}

extern "C" u32 func_ov008_020ce1d8(u32 row, u32 column)
{
    return data_ov008_020e77ac[row][column][0];
}

extern "C" u32 func_ov008_020ce1ec(u32 row, u32 column)
{
    return data_ov008_020e77a8[row][column][0];
}

extern "C" u32 func_ov008_020ce200(u32 row, u32 column)
{
    return data_ov008_020e77a4[row][column][0];
}

extern "C" u32 func_ov008_020ce214(u32 row, u32 column)
{
    return data_ov008_020e8794[row][column];
}

extern "C" void func_ov008_020ce228() {}

extern "C" {
extern u32 data_ov008_020e6718[][2];
extern u32 data_ov008_020ee3d4;
}

extern "C" fx32 func_ov008_020ce184(u32 index)
{
    u32 result = data_ov008_020e6718[index][0];
    if (index != 7) {
        return result;
    }

    u8 nodeState = save.game.nodeStates[7][6] & WM::NS_Completed;
    if (nodeState != 0) {
        result = 0x420000;
    }
    return result;
}

extern "C" void func_ov008_020d0614(u32* value)
{
    *value = 0;
}

extern "C" u32 func_ov008_020d0548(u32* value);

extern "C" u32 func_ov008_020d04fc(WorldmapScene*)
{
    if (!(save.game.completion & (1 << 5))) {
        return 0;
    }
    return func_ov008_020d0548(&data_ov008_020ee3d4);
}

extern "C" void func_ov008_020d0534()
{
    func_ov008_020d0614(&data_ov008_020ee3d4);
}

extern "C" u32 func_ov008_020d0620()
{
    return Input::consoleKeys[Input::localConsoleID][0] & 0x200;
}

extern "C" u32 func_ov008_020d0644()
{
    return Input::consoleKeys[Input::localConsoleID][0] & 0x100;
}

extern "C" u32 func_ov008_020d0668()
{
    return Input::consoleKeys[Input::localConsoleID][0] & 0x400;
}

extern "C" void func_ov008_020cdb70(int mode, int arrowValue)
{
    switch (mode) {
    case 1:
    case 2:
        func_020144bc(&data_ov008_020ee58c, arrowValue, 0, 0);
        break;
    case 3:
        func_02014824(0, 0);
        break;
    }
    func_020145f8(&data_ov008_020ee58c, 0, 0);
}

extern "C" void func_ov008_020cdbd0()
{
    u8 dialogBox = data_ov008_020ee374;
    int boxID = data_ov008_020e64ec[dialogBox][data_ov008_020ee380];
    int dialogFlag = 0;
    if (dialogBox != 0) {
        dialogFlag = 1;
    }
    WmTextBoxMessagePrefix* message = func_ov008_020cdc30(boxID, dialogFlag, data_ov008_020ee3f4);
    if (message != 0) {
        message->unk14E = 0xb;
    }
}

extern "C" u32 func_ov008_020d068c()
{
    return Input::consoleKeys[Input::localConsoleID][0] & 0x800;
}

extern "C" void func_ov008_020d153c() {}
extern "C" void func_ov008_020d1540() {}

extern "C" u8 data_ov008_020ee390;

extern "C" u32 func_ov008_020cddd8()
{
    u32 completed = 0;
    WM::Node* node;
    u32 total = 0;
    u32 cannonCompleted = 0;
    u32 cannonTotal = 0;
    u8 nodeCount;
    u8 world = 0;

    do {
        nodeCount = WM::worlds[world].nodeCount;
        u8 nodeID = 0;
        node = WM::worlds[world].nodes;

        if (nodeCount != 0) {
            do {
                if ((node->flag & WM::NF_StarCoins) != 0) {
                    u8 nodeState = save.game.nodeStates[world][nodeID] & WM::NS_Completed;
                    total++;
                    if (nodeState != 0) {
                        completed++;
                    }
                }

                if (node->type == WM::NT_Cannon) {
                    u8 nodeState = save.game.nodeStates[world][nodeID] & WM::NS_Completed;
                    cannonTotal++;
                    if (nodeState != 0) {
                        cannonCompleted++;
                    }
                }

                nodeID++;
                node++;
            } while (nodeID < nodeCount);
        }
        world++;
    } while (world < 8);

    if (completed != total) {
        return completed;
    }

    u32 completion = save.game.completion | (1 << 0);
    save.game.completion = completion;
    if (cannonCompleted == cannonTotal) {
        completion |= 1 << 8;
        save.game.completion = completion;
    }
    return completed;
}

extern "C" u32 func_ov008_020cdec0()
{
    u32 spent = 0;
    WM::Path* path;
    u32 total = 0;
    u8 pathCount;
    u8 world = 0;

    do {
        pathCount = WM::worlds[world].pathCount;
        u8 pathID = 0;
        path = WM::worlds[world].paths;

        if (pathCount != 0) {
            do {
                if ((path->flag & WM::PF_Sign) != 0) {
                    u8 pathState = save.game.pathStates[world][pathID] & WM::PS_Unlocked;
                    if (pathState != 0) {
                        spent += path->price;
                    }
                    total += path->price;
                }
                pathID++;
                path++;
            } while (pathID < pathCount);
        }

        world++;
    } while (world < 8);

    u32 completion = save.game.completion;
    if ((completion & (1 << 19)) != 0) {
        spent += 20;
    }
    if ((completion & (1 << 20)) != 0) {
        spent += 20;
    }
    if ((completion & (1 << 21)) != 0) {
        spent += 20;
    }
    if ((completion & (1 << 22)) != 0) {
        spent += 20;
    }

    if (spent == total + 80) {
        save.game.completion |= 1 << 4;
    }
    return spent;
}

extern "C" void func_ov008_020ce5ec()
{
    u32 value = data_ov008_020ee3f4;
    data_ov008_020ee3f0 = 3;
    data_ov008_020ee398 = 2;
    data_ov008_020ee3e0 = 0;
    data_ov008_020ee378 = 1;
    data_ov008_020ee37c = 1;
    data_ov008_020ee3d0 = 0;
    func_ov008_020cdc30(7, 1, value);
    func_02012398(0xe6, 0);
}

struct WmInputSequenceEntryLocal {
    u32 (*check)();
    u32 value04;
};
extern "C" WmInputSequenceEntryLocal data_ov008_020e2dfc[];

extern "C" u32 func_ov008_020d0548(u32* value)
{
    if (*value < 8) {
        u32 result = data_ov008_020e2dfc[*value].check();
        if (result != 0) {
            (*value)++;
        } else if (Input::consoleKeys[Input::localConsoleID][0] != 0) {
            func_ov008_020d0614(value);
            return 0;
        }
    }

    if (*value >= 8) {
        if (data_02085a10 == 0) {
            data_02085a10 = 1;
            func_02012398(0x33, 0);
        } else {
            data_02085a10 = 0;
            func_02012398(0xee, 0);
        }

        func_ov008_020d0614(value);
        return 1;
    }

    return 0;
}

void WorldmapScene::func_ov008_020d06b0()
{
    OptionsMenu::menuUnloadWorldmap();
}

void WorldmapScene::func_ov008_020d06bc()
{
    OptionsMenu::menuMain();
}

void WorldmapScene::func_ov008_020d06c8()
{
    if (OptionsMenu::taskID == OptionsMenu::T_SlideIn) {
        OptionsMenu::menuSlideIn();
        return;
    }

    OptionsMenu::menuClose();
}

void WorldmapScene::func_ov008_020d06fc()
{
    OptionsMenu::menuLoad();
}

void WorldmapScene::func_ov008_020d0708()
{
    switch (OptionsMenu::taskID) {
    case OptionsMenu::T_Open:
        OptionsMenu::menuInit();
        return;
    case OptionsMenu::T_ClosePress:
        OptionsMenu::menuClosePress();
        return;
    case OptionsMenu::T_CloseRelease:
        OptionsMenu::menuCloseRelease();
        return;
    case OptionsMenu::T_CloseWait:
        OptionsMenu::menuCloseWait();
        return;
    case OptionsMenu::T_SlideOut:
        OptionsMenu::menuSlideOut();
    }
}


namespace Game {
    u8 getPlayerPowerup(s32 playerID);
}

extern "C" u32 func_ov008_020ce298(u32 nodeType)
{
    u8 powerup = Game::getPlayerPowerup(0);
    u32 result;

    switch (nodeType) {
    case 0:
        result = 1;
        break;
    case 1:
        if (powerup != WmPlayerModel::P_Shell) { result = 2; }
        else { result = 3; }
        break;
    case 2:
        result = 4;
        break;
    case 3:
        result = 4;
        break;
    case 4:
        if (powerup != WmPlayerModel::P_Shell) { result = 5; }
        else { result = 6; }
        break;
    case 5:
        result = 7;
        break;
    case 6:
        result = 7;
        break;
    case 7:
        result = 7;
        break;
    }

    return result;
}

void WorldmapScene::func_ov008_020d0a4c()
{
    OptionsMenu::menuDraw();
}

extern "C" {
extern u16 data_02088c3c[8];
extern u32 data_ov008_020ee3f0;
extern u32 data_ov008_020ee3d0;
}

extern "C" void func_ov008_020ce22c()
{
    u32 world = save.game.currentWorld;
    data_ov008_020ee3f0 = 4;
    data_ov008_020ee3d0 = 0;
    data_02088c3c[world] |= WM::WS_Completed;

    if (world != 7) {
        world = func_ov008_020ce298(world);
    }
    func_ov008_020cdb44(9, world | 0x3000);
}

extern "C" void func_ov008_020cf790() {}

extern "C" bool func_ov008_020cf794()
{
    FS::Cache::clear();
    if (data_0203bd30 != SC_Worldmap) {
        func_02011d40();
    }
    System::resetSubBGVBlank();
    return true;
}

extern "C" u8 data_ov008_020ee49c[];
extern "C" void func_ov008_020d12ac(void*);
extern "C" void func_ov008_020cf12c(WorldmapScene* scene, u32 state)
{
    func_ov008_020d12ac(&data_ov008_020ee49c);
    scene->Scene::postUpdate(state);
}

struct Unk020d1478ConfigLocal {
    s32 value00;
    s32 value04;
    s32 value08;
    s32 value0C;
    s32 padding10;
    u32 mode;
};
extern "C" s8 data_ov008_020e5a2c;
extern "C" u32 data_ov008_020ee414;
extern "C" void func_ov008_020d1478(Unk020d1478ConfigLocal* config, u32 mode)
{
    config->value04 = 0x333;
    config->value00 = 0x1000;
    config->value08 = 0;
    config->value0C = 0x1e;
    config->mode = mode;
    switch (config->mode) {
    case 2:
        config->value0C = 0x32;
        data_ov008_020e5a2c = save.game.currentWorld;
        return;
    case 0:
        data_ov008_020ee414 = 0;
        return;
    default:
        config->value04 = 0x333;
        config->value08 = 0x8000;
        return;
    }
}
