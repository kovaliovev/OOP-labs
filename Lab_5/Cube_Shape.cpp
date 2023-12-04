#include "framework.h"
#include "resource.h"
#include "Cube_Shape.h"

CubeShape::CubeShape() {
	SetName(L"Cube");
}

void CubeShape::Show(HDC hdc, BOOL isSelected) {
	int x_start = shape_x_1;
	int y_start = shape_y_1;
	int x_end = shape_x_2;
	int y_end = shape_y_2;

	RectangleShape::SetColor(COL_WHITE);
	RectangleShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_start, y_start);
	LineShape::SetEndCords(x_start + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_start + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_end, y_start);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_end, y_end);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_end + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_start, y_end);
	LineShape::SetEndCords(x_start + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_start + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	LineShape::SetStartCords(x_start + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::SetEndCords(x_start + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::Show(hdc, isSelected);

	shape_x_1 = x_start;
	shape_y_1 = y_start;
	shape_x_2 = x_end;
	shape_y_2 = y_end;
}

void CubeShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_OLINEO, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_CUBE, MF_CHECKED);
	}
};

void CubeShape::DrawRubberTrack(HWND hWnd) {
	int x_start = shape_x_1;
	int y_start = shape_y_1;
	int x_end = shape_x_2;
	int y_end = shape_y_2;

	RectangleShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_start, y_start);
	LineShape::SetEndCords(x_start + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_start + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_end, y_start);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_end, y_end);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_end + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_start, y_end);
	LineShape::SetEndCords(x_start + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_start + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::SetEndCords(x_end + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	LineShape::SetStartCords(x_start + CUBE_SIZE, y_start - CUBE_SIZE);
	LineShape::SetEndCords(x_start + CUBE_SIZE, y_end - CUBE_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	shape_x_1 = x_start;
	shape_y_1 = y_start;
	shape_x_2 = x_end;
	shape_y_2 = y_end;
};

Shape* CubeShape::CreateNew() {
	return new CubeShape;
};