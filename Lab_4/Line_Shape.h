#pragma once
#include "Shape.h"

class LineShape : public virtual Shape {
public:
	void Show(HDC);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};