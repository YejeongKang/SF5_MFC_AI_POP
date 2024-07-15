#include "pch.h"
#include "MyButton.h"

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
    : m_bgColor(RGB(64, 70, 76)) // �⺻ ���� ����
{
    SetButtonFont(_T("����������"), 10);
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

    // ��Ʈ ���� ����
    dc.SelectObject(&m_font);

    // �ؽ�Ʈ ���
    dc.SetBkMode(TRANSPARENT);
    dc.SetTextColor(RGB(255, 255, 255)); // ��� �ؽ�Ʈ
    dc.DrawText(strText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    // �׵θ� �׸���
    dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT); // ���÷� �׵θ� ��Ÿ���� RAISED�� ����
}

BOOL CMyButton::OnEraseBkgnd(CDC* pDC)
{
    // ��� ����� ��Ȱ��ȭ
    return TRUE;
}

void CMyButton::SetBackgroundColor(COLORREF color)
{
    m_bgColor = color;
    Invalidate(); // ��ư�� �ٽ� �׸����� ������ ȣ��
}

void CMyButton::SetButtonFont(const CString& fontName, int fontSize)
{
    m_font.DeleteObject();
    m_font.CreatePointFont(fontSize * 10, fontName); // ��Ʈ ����
}
