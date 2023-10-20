#pragma once
#include "Shape_Editor.h"

class ShapeObjectsEditor
{	
public:
	ShapeObjectsEditor();
	~ShapeObjectsEditor();
	void StartPointEditor(HWND);
	void StartLineEditor(HWND);
	void StartRectangleEditor(HWND);
	void StartEllipseEditor(HWND);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};