#pragma once
#include "Editor.h"
#include "Shape.h"

#define ARRAY_OF_SHAPES_SIZE 111

extern Shape* p_shapes[ARRAY_OF_SHAPES_SIZE];

class ShapeEditor : public Editor{
protected:
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
};