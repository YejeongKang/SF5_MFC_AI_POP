#include "pch.h"
#include "MyButton.h"

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
    : m_bgColor(RGB(238, 182, 41)) // �⺻ ���� ���� (���÷� ��Ȳ��)
{
}

CMyButton::~CMyButton()
{
}

BEGIN_MESSAGE_MAP(CMyButton, CButton)
    ON_WM_PAINT()
    ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CMyButton::OnPaint()
{
    CPaintDC dc(this); // device context for painting

    // ��ư�� Ŭ���̾�Ʈ ���� ��������
    CRect rect;
    GetClientRect(rect);

    // ���� ����
    dc.FillSolidRect(rect, m_bgColor); // m_bgColor ������ ����Ͽ� ���� ����

    // �ؽ�Ʈ ��� (�⺻ �ؽ�Ʈ ���)
    CString strText;
    GetWindowText(strText);
    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(RGB(255, 255, 255)); // ��� �ؽ�Ʈ
    dc.DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

BOOL CMyButton::OnEraseBkgnd(CDC* pDC)
{
    // ��� ����� ��Ȱ��ȭ
    return TRUE;
}

void CMyButton::SetBgColor(COLORREF color)
{
    m_bgColor = color;
    Invalidate(); // ��ư�� �ٽ� �׸����� ������ ȣ��
}

void CMyButton::SetBackgroundColor(COLORREF color)
{
    SetBgColor(color);
}
