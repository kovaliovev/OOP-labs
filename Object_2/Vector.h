#pragma once

#include <string>
#include <vector>

#define CLIPBOARD_SIZE 102400
#define NUMS_START_X 10
#define NUMS_START_Y 0
#define NUMS_IN_ROW 14

using namespace std;

class Vector {
private:
	vector<double> numbers;
public:
	void OnData(HWND hWnd, WPARAM wParam, LPARAM lParam);
	void OnPaint(HWND hWnd, HDC hdc);
	void RandomGenerate(int n, int min, int max);
	char* ConvertToChars();
	int PutToClipboard(HWND hWnd, char* src);
};