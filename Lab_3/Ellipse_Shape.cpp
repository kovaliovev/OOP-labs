#include "framework.h"
#include "Ellipse_Shape.h"

void EllipseShape::Show(HDC hdc) {
	int real_shape_x_1 = shape_x_2 - (2 * (shape_x_2 - shape_x_1));
	int real_shape_y_1 = shape_y_2 - (2 * (shape_y_2 - shape_y_1));

	Arc(hdc, real_shape_x_1, real_shape_y_1, shape_x_2, shape_y_2, 0, 0, 0, 0);
}