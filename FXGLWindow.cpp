#include "FXGLWindow.h"

#include <syslog.h>

FXDEFMAP(FXGLWindow) FXGLWindowMap[]=
{
	FXMAPFUNC(SEL_LEFTBUTTONPRESS,0,FXGLWindow::onLeftBtnPress),
};
FXIMPLEMENT(FXGLWindow,FXGLViewer,FXGLWindowMap,ARRAYNUMBER(FXGLWindowMap))

FXGLWindow::FXGLWindow(FXComposite *p, FXGLVisual *vis)
: FXGLViewer(p,vis,NULL,0,LAYOUT_FILL_X|LAYOUT_FILL_Y,0,0,0,0)
{
}

long FXGLWindow::onLeftBtnPress(FXObject* sender,FXSelector sel,void* ptr)
{
	FXGLObject* object = NULL;

	FXEvent* event=(FXEvent*)ptr;
	object=pick(event->click_x,event->click_y);

	if(object)
	{
		auto cyl = dynamic_cast<FXGLCylinder*>(object);
		if(cyl)
		{
			cyl->setRadius(cyl->getRadius() + 1);
			update();
		}
	}

	return 1;
}
