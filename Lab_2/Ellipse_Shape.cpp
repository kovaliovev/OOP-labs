#include "framework.h"
#include "Ellipse_Shape.h"

#define COL_WHITE RGB(255, 255, 255)

void EllipseShape::Show(HDC hdc) {
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(COL_WHITE);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, shape_x_1, shape_y_1, shape_x_2, shape_y_2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}