#include "framework.h"
#include "Line_Shape.h"

void LineShape::Show(HDC hdc) {
	MoveToEx(hdc, shape_x_1, shape_y_1, NULL);
	LineTo(hdc, shape_x_2, shape_y_2);
}