#include "framework.h"
#include "resource.h"
#include "Point_Shape.h"

PointShape::PointShape() {
	SetName(L"Point");
}

void PointShape::Show(HDC hdc, BOOL isSelected) {

	COLORREF color = (isSelected ? COL_RED : COL_BLACK);

	SetPixel(hdc, shape_x_2, shape_y_2, color);

	SetPixel(hdc, shape_x_2 - 1, shape_y_2 - 1, color);
	SetPixel(hdc, shape_x_2 + 1, shape_y_2 - 1, color);
	SetPixel(hdc, shape_x_2 - 1, shape_y_2 + 1, color);
	SetPixel(hdc, shape_x_2 + 1, shape_y_2 + 1, color);

	SetPixel(hdc, shape_x_2 - 1, shape_y_2, color);
	SetPixel(hdc, shape_x_2 + 1, shape_y_2, color);
	SetPixel(hdc, shape_x_2, shape_y_2 - 1, color);
	SetPixel(hdc, shape_x_2, shape_y_2 + 1, color);
}

void PointShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_OLINEO, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_CUBE, MF_UNCHECKED);
	}
};

void PointShape::DrawRubberTrack(HWND hWnd) {};

Shape* PointShape::CreateNew() {
	return new PointShape;
} ;