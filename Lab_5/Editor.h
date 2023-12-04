#pragma once
#include "Shape.h"
#include "Toolbar.h"

typedef void (*TABLEADD)(LPCWSTR);
typedef void (*TABLECLEAR)();

#define ARRAY_OF_SHAPES_SIZE 111

class Editor {
private:
	static Editor* p_instance;
	Editor() {}
	Editor(const Editor&);
	Editor& operator=(Editor&);
	static Shape* p_shapes[ARRAY_OF_SHAPES_SIZE];
	static int currIndex;
	Shape* currShape;
	Toolbar toolbar;
	bool isDrawing = false;
	POINT point;
public:
	~Editor();
	static Editor* GetInstance();
	void Start(HWND, LPARAM, Shape*);
	void OnLBdown(HWND);
	void OnLBup(HWND, TABLEADD);
	void OnMouseMove(HWND);
	void OnPaint(HWND, int);
	void OnShapeRemove(HWND, int);
	void OnCreate(HWND, HINSTANCE, TABLEADD);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnInitMenuPopup(HWND, WPARAM);
	void OnFileSave(LPCWSTR);
	void OnFileLoad(HWND, LPCWSTR, TABLEADD, TABLECLEAR);
};
