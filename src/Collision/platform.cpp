#include "platform.hpp"

Platform* Platform::listHead;
Platform* Platform::listTail;

Platform::Platform()
{
    reset();
    flags = 0;
}

Platform::~Platform()
{
    unlink();
}

void Platform::reset()
{
    prev = nullptr;
    next = nullptr;
    manager = nullptr;
    unk51 = 0;
    linked = false;
}

void Platform::link()
{
    if (linked)
        return;
    prev = listTail;
    listTail = this;
    if (prev == nullptr) {
        next = listHead;
        listHead = this;
    } else {
        next = prev->next;
        prev->next = this;
    }
    linked = true;
}

void Platform::unlink()
{
    if (!linked)
        return;
    if (prev != nullptr)
        prev->next = next;
    else
        listHead = next;
    if (next != nullptr)
        next->prev = prev;
    else
        listTail = prev;
    reset();
}

// Both hooks return immediately in the original A2DE binary.
void Platform::update() {}
void Platform::func5() {}

RotatingPlatform::RotatingPlatform()
{
    type = Rotating;
}

SegmentPlatform::SegmentPlatform()
{
    type = Segment;
}

void RotatingPlatform::setBase(fx32 leftValue, fx32 rightValue)
{
    left = leftValue;
    right = rightValue;
    length = right - left;
}

void RotatingPlatform::setLeft(fx32 value)
{
    left = value;
    length = right - left;
}

void RotatingPlatform::setRight(fx32 value)
{
    right = value;
    length = right - left;
}

void RotatingPlatform::setHeight(fx32 value, fx32 scale)
{
    height = _FixedMul(value, scale);
}
