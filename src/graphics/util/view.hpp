#pragma once
#include "../../Bases/Object.hpp"
#include "../../Vec.hpp"

namespace Nitro {
	void Math_func_01ffc378(Mat4x4* matrix);
	void Math_func_01ffbbe0(Mat4x3* matrix);
}

class View : public Object
{
public:

	Mat4x4 unk5C;
	Mat4x3 viewMatrix;

	View() {
		Nitro::Math_func_01ffc378(&unk5C);
		Nitro::Math_func_01ffbbe0(&viewMatrix);
	}

	//020a3abc
	virtual s32 onRender() override;

	//D0:020a3a88
	//D1:020a3a5c
	virtual ~View() {}


};
NTR_SIZE_GUARD(View, 0xCC);
