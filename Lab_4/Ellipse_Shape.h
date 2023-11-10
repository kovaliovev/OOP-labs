#pragma once
#include "Shape.h"

class EllipseShape : public virtual Shape {
public:
	EllipseShape();
	void Show(HDC);
	void OnInitMenuPopup(HWND, WPARAM);
	void DrawRubberTrack(HWND);
	Shape* CreateNew();
};