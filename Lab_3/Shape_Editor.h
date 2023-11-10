#pragma once
#include "Editor.h"
#include "Shape.h"

#define ARRAY_OF_SHAPES_SIZE 112

class ShapeEditor : public Editor {
protected:
	static Shape** pp_shapes;
	int x_start, y_start, x_end, y_end;
	int index = 0;
	bool isDrawing = false;
	POINT point;
public:
	ShapeEditor();
	void OnLBdown(HWND);
	void OnPaint(HWND);
	virtual void OnLBup(HWND) = 0;
	virtual void OnMouseMove(HWND) = 0;
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
};