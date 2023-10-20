#include "framework.h"
#include "Rectangle_Shape.h"

#define COL_GRAY RGB(192, 192, 192)

void RectangleShape::Show(HDC hdc) {
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(COL_GRAY);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	int real_shape_x_1 = shape_x_2 - (2 * (shape_x_2 - shape_x_1));
	int real_shape_y_1 = shape_y_2 - (2 * (shape_y_2 - shape_y_1));

	Rectangle(hdc, real_shape_x_1, real_shape_y_1, shape_x_2, shape_y_2);
	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}