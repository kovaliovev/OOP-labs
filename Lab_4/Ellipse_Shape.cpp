#include "framework.h"
#include "resource.h"
#include "Ellipse_Shape.h"

EllipseShape::EllipseShape() {
	SetColor(COL_GREEN);
}

void EllipseShape::Show(HDC hdc) {
	int real_shape_x_1 = shape_x_2 - (2 * (shape_x_2 - shape_x_1));
	int real_shape_y_1 = shape_y_2 - (2 * (shape_y_2 - shape_y_1));

	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(shape_color);
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Ellipse(hdc, real_shape_x_1, real_shape_y_1, shape_x_2, shape_y_2);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}

void EllipseShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_OLINEO, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_CUBE, MF_UNCHECKED);
	}
};

void EllipseShape::DrawRubberTrack(HWND hWnd) {
	HPEN hPenOld, hPen;
	HDC hdc = GetDC(hWnd);
	SetROP2(hdc, R2_NOTXORPEN);

	hPen = CreatePen(PS_DASH, 1, COL_BLACK);
	hPenOld = (HPEN)SelectObject(hdc, hPen);

	int real_shape_x_1 = shape_x_2 - (2 * (shape_x_2 - shape_x_1));
	int real_shape_y_1 = shape_y_2 - (2 * (shape_y_2 - shape_y_1));

	Ellipse(hdc, real_shape_x_1, real_shape_y_1, shape_x_2, shape_y_2);

	SelectObject(hdc, hPenOld);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
};

Shape* EllipseShape::CreateNew() {
	return new EllipseShape;
};