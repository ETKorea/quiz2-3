
// quiz2-3View.cpp: Cquiz23View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "quiz2-3.h"
#endif

#include "quiz2-3Doc.h"
#include "quiz2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cquiz23View

IMPLEMENT_DYNCREATE(Cquiz23View, CView)

BEGIN_MESSAGE_MAP(Cquiz23View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cquiz23View 생성/소멸

Cquiz23View::Cquiz23View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cquiz23View::~Cquiz23View()
{
}

BOOL Cquiz23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cquiz23View 그리기
CPoint pnt;
void Cquiz23View::OnDraw(CDC* pDC)
{
	Cquiz23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->Rectangle(pnt.x - 50, pnt.y - 50, pnt.x + 50, pnt.y + 50);
	pDC->Ellipse(pnt.x - 50, pnt.y - 50, pnt.x + 50, pnt.y + 50);
	pDC->TextOutW(pnt.x - 30, pnt.y, L"HELLO ANU");
}


// Cquiz23View 인쇄

BOOL Cquiz23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cquiz23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cquiz23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cquiz23View 진단

#ifdef _DEBUG
void Cquiz23View::AssertValid() const
{
	CView::AssertValid();
}

void Cquiz23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cquiz23Doc* Cquiz23View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cquiz23Doc)));
	return (Cquiz23Doc*)m_pDocument;
}
#endif //_DEBUG


// Cquiz23View 메시지 처리기


void Cquiz23View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pnt = point;
	Invalidate(true);
	CView::OnMouseMove(nFlags, point);
}
