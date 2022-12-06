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
    void SetBtnImage(CString ImagePath);        //设置图片
    void SetBkColor(COLORREF bgColor);          //设置背景颜色
    void PngTransparent(CImage* image);         //PNG透明图转换
    void SetAutoAdjustSize(bool bAdjust);       //是否自动调整按钮大小为图片大小
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


