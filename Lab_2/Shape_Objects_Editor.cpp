#include "framework.h"
#include "Shape_Objects_Editor.h"
#include "Shape.h"
#include "Editor.h"
#include "Point_Editor.h"
#include "Line_Editor.h"
#include "Rectangle_Editor.h"
#include "Ellipse_Editor.h"

ShapeEditor* p_shape_editor = NULL;

ShapeObjectsEditor::ShapeObjectsEditor() {
	p_shape_editor = NULL;
}

ShapeObjectsEditor::~ShapeObjectsEditor() {
	delete p_shape_editor;
}

void ShapeObjectsEditor::StartPointEditor(HWND hWnd)
{
	if (p_shape_editor) delete p_shape_editor;
	p_shape_editor = new PointEditor;
	SetWindowText(hWnd, L"DRAWING MODE: POINT");
}

void ShapeObjectsEditor::StartLineEditor(HWND hWnd)
{
	if (p_shape_editor) delete p_shape_editor;
	p_shape_editor = new LineEditor;
	SetWindowText(hWnd, L"DRAWING MODE: LINE");
}

void ShapeObjectsEditor::StartRectangleEditor(HWND hWnd)
{
	if (p_shape_editor) delete p_shape_editor;
	p_shape_editor = new RectangleEditor;
	SetWindowText(hWnd, L"DRAWING MODE: RECTANGLE");
}

void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd)
{
	if (p_shape_editor) delete p_shape_editor;
	p_shape_editor = new EllipseEditor;
	SetWindowText(hWnd, L"DRAWING MODE: ELLIPSE");
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd)
{
	if (p_shape_editor) p_shape_editor->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd)
{
	if (p_shape_editor) p_shape_editor->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd)
{
	if (p_shape_editor) p_shape_editor->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd)
{
	if (p_shape_editor) p_shape_editor->OnPaint(hWnd);
}
