#pragma once
#include "Shape.h"

class LineShape : public Shape {
public:
	~LineShape();
	void Show(HDC);
};