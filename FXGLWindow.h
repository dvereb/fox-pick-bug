#ifndef FXGLWINDOW_H
#define FXGLWINDOW_H

#include <fox/fx.h>
#include <fox/fx3d.h>

class FXGLWindow:public FXGLViewer
{
	FXDECLARE(FXGLWindow)

public:
	FXGLWindow(FXComposite *p, FXGLVisual *vis);
	long onLeftBtnPress(FXObject* sender,FXSelector sel,void* ptr);

private:
	FXGLWindow(void) { }
};

#endif
