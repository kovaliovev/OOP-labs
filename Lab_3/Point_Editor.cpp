#include "framework.h"
#include "resource.h"
#include "Shape_Editor.h"
#include "Point_Shape.h"
#include "Point_Editor.h"

void PointEditor::OnLBup(HWND hWnd) {
	pp_shapes[index] = new PointShape;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	pp_shapes[index]->SetEndCords(point.x, point.y);

	InvalidateRect(hWnd, NULL, TRUE);
	index++;
	isDrawing = false;
}

void PointEditor::OnMouseMove(HWND hWnd) {}

void PointEditor::OnInitMenuPopup(HWND hWnd, WPARAM wParam)
{
	HMENU hMenu = GetMenu(hWnd);
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	if ((HMENU)wParam == hSubMenu)
	{
		CheckMenuItem(hSubMenu, ID_OBJECTS_POINT, MF_CHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_LINE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_RECTANGLE, MF_UNCHECKED);
		CheckMenuItem(hSubMenu, ID_OBJECTS_ELLIPSE, MF_UNCHECKED);
	}
}