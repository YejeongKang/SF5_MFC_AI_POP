#pragma once

class CMyButton : public CButton
{
    DECLARE_DYNAMIC(CMyButton)

public:
    CMyButton();
    virtual ~CMyButton();

protected:
    afx_msg void OnPaint();
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    DECLARE_MESSAGE_MAP()

private:
    COLORREF m_bgColor; // ������ ������ ����
    CFont m_font; // ��ư�� ������ ��Ʈ

    void SetBgColor(COLORREF color); // ���� ���� �Լ�

public:
    void SetBackgroundColor(COLORREF color); // ���� ������ ���� ���� �Լ�
};
