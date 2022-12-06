// ImageButton.cpp : 实现文件
//

#include "stdafx.h"
#include "testMfc.h"
#include "ImageButton.h"


// CImageButton

IMPLEMENT_DYNAMIC(CImageButton, CButton)

CImageButton::CImageButton()
{
    m_bkColor = RGB(255,255,255);
    m_bAdjustSize = false;
}

CImageButton::~CImageButton()
{
}


BEGIN_MESSAGE_MAP(CImageButton, CButton)
END_MESSAGE_MAP()



// CImageButton 消息处理程序


void CImageButton::SetBtnImage(CString ImagePath)
{
    m_btnImage.Load(ImagePath.GetBuffer());
    PngTransparent(&m_btnImage);
    ImagePath.ReleaseBuffer();
    Invalidate();
}

void CImageButton::SetBkColor(COLORREF bkColor)
{
    m_bkColor = bkColor;
    Invalidate();
}

void CImageButton::SetAutoAdjustSize(bool bAdjust)
{
    m_bAdjustSize = bAdjust;
    Invalidate();
}

void CImageButton::PngTransparent(CImage* image)
{
    for (int i = 0; i <image->GetWidth(); i++)  				//遍历像素处理
    {
        for (int j = 0; j <image->GetHeight(); j++)
        {
            byte * pucColor = (byte *)(image->GetPixelAddress(i, j));
            pucColor[0] = pucColor[0] * pucColor[3] / 255;
            pucColor[1] = pucColor[1] * pucColor[3] / 255;
            pucColor[2] = pucColor[2] * pucColor[3] / 255;
        }
    }
}

void CImageButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
    CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
    CRect rc;
    GetClientRect(&rc);
    CBrush brush(m_bkColor);
    pDC->FillRect(rc, &brush);
    if (m_btnImage)
    {
        m_btnImage.Draw(pDC->m_hDC, 0, 0, m_btnImage.GetWidth(), m_btnImage.GetHeight()); 
    }
    if (m_bAdjustSize)
    {
        this->SetWindowPos(NULL, 0, 0, m_btnImage.GetWidth(), m_btnImage.GetHeight(), SWP_NOMOVE);
    }
}
