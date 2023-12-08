#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Painter {
private:
	vector<double> points;
	int x_start = 50;
	int y_start = 30;
	int x_end = 940;
	int y_end = 700;
	int arrow_size = 8;
	double max_abs_num;
	double d_x;
	double d_y;
	void CalculateScaleFactors();
public:
	void OnStart(HWND hWnd);
	void OnPaint(HDC hdc);
	void GetDataFromClipboard(HWND hWnd, char*dest, int size);
	void ParseVector(char* textVector);
	void DrawAxis(HDC hdc);
	void DrawNumbers(HDC hdc);
	void DrawGraph(HDC hdc);
};