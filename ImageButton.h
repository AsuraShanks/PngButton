#pragma once

#include <atlimage.h>
#include <GdiPlus.h>
#pragma comment(lib, "gdiplus.lib")
// CImageButton

class CImageButton : public CButton
{
	DECLARE_DYNAMIC(CImageButton)

public:
	CImageButton();
	virtual ~CImageButton();

public:
    //Gdiplus::Image m_btnImage;
    CImage      m_btnImage;
    COLORREF    m_bkColor;
    bool        m_bAdjustSize;

protected:
	DECLARE_MESSAGE_MAP()


public:
    void SetBtnImage(CString ImagePath);        //����ͼƬ
    void SetBkColor(COLORREF bgColor);          //���ñ�����ɫ
    void PngTransparent(CImage* image);         //PNG͸��ͼת��
    void SetAutoAdjustSize(bool bAdjust);       //�Ƿ��Զ�������ť��СΪͼƬ��С
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


