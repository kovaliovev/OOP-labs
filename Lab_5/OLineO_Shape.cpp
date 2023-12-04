#include "framework.h"
#include "resource.h"
#include "OLineO_Shape.h"

OLineOShape::OLineOShape() {
	SetName(L"OlineO");
}

void OLineOShape::Show(HDC hdc, BOOL isSelected) {
	int x_start = shape_x_1;
	int y_start = shape_y_1;
	int x_end = shape_x_2;
	int y_end = shape_y_2;

	LineShape::SetStartCords(x_start - O_SIZE, y_start - O_SIZE);
	LineShape::SetEndCords(x_end - O_SIZE, y_end - O_SIZE);
	LineShape::Show(hdc, isSelected);

	EllipseShape::SetColor(COL_BLUE);

	EllipseShape::SetStartCords(x_start - O_SIZE, y_start - O_SIZE);
	EllipseShape::SetEndCords(x_start + O_SIZE, y_start + O_SIZE);
	EllipseShape::Show(hdc, isSelected);

	EllipseShape::SetStartCords(x_end - O_SIZE, y_end - O_SIZE);
	EllipseShape::SetEndCords(x_end + O_SIZE, y_end + O_SIZE);
	EllipseShape::Show(hdc, isSelected);

	shape_x_1 = x_start;
	shape_y_1 = y_start;
	shape_x_2 = x_end;
	shape_y_2 = y_end;
}

void OLineOShape::OnInitMenuPopup(HWND hWnd, WPARAM wParam) {
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_OLINEO, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_CUBE, MF_UNCHECKED);
	}
};

void OLineOShape::DrawRubberTrack(HWND hWnd) {
	int x_start = shape_x_1;
	int y_start = shape_y_1;
	int x_end = shape_x_2;
	int y_end = shape_y_2;

	LineShape::SetStartCords(x_start - O_SIZE, y_start - O_SIZE);
	LineShape::SetEndCords(x_end - O_SIZE, y_end - O_SIZE);
	LineShape::DrawRubberTrack(hWnd);

	EllipseShape::SetStartCords(x_start - O_SIZE, y_start - O_SIZE);
	EllipseShape::SetEndCords(x_start + O_SIZE, y_start + O_SIZE);
	EllipseShape::DrawRubberTrack(hWnd);

	EllipseShape::SetStartCords(x_end - O_SIZE, y_end - O_SIZE);
	EllipseShape::SetEndCords(x_end + O_SIZE, y_end + O_SIZE);
	EllipseShape::DrawRubberTrack(hWnd);

	shape_x_1 = x_start;
	shape_y_1 = y_start;
	shape_x_2 = x_end;
	shape_y_2 = y_end;
};

Shape* OLineOShape::CreateNew() {
	return new OLineOShape;
};