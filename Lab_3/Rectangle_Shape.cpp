#include "framework.h"
#include "Rectangle_Shape.h"

#define COL_YELLOW RGB(255, 255, 0)

void RectangleShape::Show(HDC hdc) {
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(COL_YELLOW);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, shape_x_1, shape_y_1, shape_x_2, shape_y_2);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}