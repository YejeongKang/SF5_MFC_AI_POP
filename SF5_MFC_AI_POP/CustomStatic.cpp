// CustomStatic.cpp

#include "pch.h"
#include "CustomStatic.h"

CCustomStatic::CCustomStatic()
{
}

CCustomStatic::~CCustomStatic()
{
}

BEGIN_MESSAGE_MAP(CCustomStatic, CStatic)
    ON_WM_PAINT()
END_MESSAGE_MAP()

void CCustomStatic::OnPaint()
{
    CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ
    CRect rect;
    GetClientRect(&rect);

    // ���� ä���
    dc.FillSolidRect(rect, RGB(0, 0, 0)); // ������ ������� ä��

    // �׵θ� �׸���
    CBrush brushWhite(RGB(64, 70, 76));
    CPen penWhite(PS_SOLID, 2, RGB(255, 255, 255));
    CPen* pOldPen = dc.SelectObject(&penWhite);
    CBrush* pOldBrush = dc.SelectObject(&brushWhite);

    dc.Rectangle(rect);

    dc.SelectObject(pOldPen);
    dc.SelectObject(pOldBrush);
}
