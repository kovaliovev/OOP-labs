#include "framework.h"
#include "Point_Shape.h"

#define COL_BLACK RGB(0, 0, 0)

void PointShape::Show(HDC hdc) {
	SetPixel(hdc, shape_x_2, shape_y_2, COL_BLACK);

	SetPixel(hdc, shape_x_2 - 1, shape_y_2 - 1, COL_BLACK);
	SetPixel(hdc, shape_x_2 + 1, shape_y_2 - 1, COL_BLACK);
	SetPixel(hdc, shape_x_2 - 1, shape_y_2 + 1, COL_BLACK);
	SetPixel(hdc, shape_x_2 + 1, shape_y_2 + 1, COL_BLACK);

	SetPixel(hdc, shape_x_2 - 1, shape_y_2, COL_BLACK);
	SetPixel(hdc, shape_x_2 + 1, shape_y_2, COL_BLACK);
	SetPixel(hdc, shape_x_2, shape_y_2 - 1, COL_BLACK);
	SetPixel(hdc, shape_x_2, shape_y_2 + 1, COL_BLACK);
}