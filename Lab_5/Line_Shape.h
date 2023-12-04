#pragma once
#include "Shape.h"

class LineShape : public virtual Shape {
public:
	LineShape();
	void Show(HDC, BOOL);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};