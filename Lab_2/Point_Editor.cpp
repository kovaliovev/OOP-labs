#include "framework.h"
#include "Shape_Editor.h"
#include "Point_Shape.h"
#include "Point_Editor.h"

void PointEditor::OnLBup(HWND hWnd) {
	p_shapes[index] = new PointShape;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	p_shapes[index]->SetEndCords(point.x, point.y);

	InvalidateRect(hWnd, NULL, TRUE);
	index++;
	isDrawing = false;
}

void PointEditor::OnMouseMove(HWND hWnd) {}