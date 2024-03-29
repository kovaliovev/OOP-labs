#pragma once

#define COL_BLACK RGB(0, 0, 0)
#define COL_WHITE RGB(255, 255, 255)
#define COL_YELLOW RGB(255, 255, 0)
#define COL_GREEN RGB(51, 255, 51)
#define COL_BLUE RGB(51, 51, 255)
#define COL_RED RGB(255, 0, 0)

class Shape {
protected:
	int shape_x_1;
	int shape_y_1;
	int shape_x_2;
	int shape_y_2;
	COLORREF shape_color;
	LPCWSTR shape_name;
public:
	virtual ~Shape();
	void SetStartCords(int, int);
	void SetEndCords(int, int);
	void SetColor(COLORREF);
	void GetInfo(WCHAR*);
	void SetName(LPCWSTR);
	LPCWSTR GetName();
	virtual void Show(HDC, BOOL) = 0;
	virtual void OnInitMenuPopup(HWND, WPARAM) = 0;
	virtual void DrawRubberTrack(HWND) = 0;
	virtual Shape* CreateNew() = 0;
};