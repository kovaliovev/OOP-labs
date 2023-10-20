#include "framework.h"
#include "Shape_Editor.h"

Shape* p_shapes[ARRAY_OF_SHAPES_SIZE];

ShapeEditor::ShapeEditor() { 
	for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++) {
		if (!p_shapes[i]) {
			index = i;
			break;
		}
	}
}

void ShapeEditor::OnLBdown(HWND hWnd) {
	isDrawing = true;
	GetCursorPos(&point);
	ScreenToClient(hWnd, &point);
	x_start = x_end = point.x;
	y_start = y_end = point.y;
}

void ShapeEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < ARRAY_OF_SHAPES_SIZE; i++)
	{
		if (p_shapes[i]) p_shapes[i]->Show(hdc);
	}
	EndPaint(hWnd, &ps);
}