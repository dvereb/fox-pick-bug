#include "FXGLWindow.h"

#include <fox/fx.h>
#include <fox/fx3d.h>
#include <fox/FXGLCylinder.h>

int main(int argc, char *argv[])
{
	FXApp *app = new FXApp("Test","Test");
	app->init(argc,argv);
	app->create();

	FXMainWindow window(app,"Test",NULL,NULL,DECOR_ALL,0,0,800,600);

	FXHorizontalFrame *hf = new FXHorizontalFrame(&window, LAYOUT_FILL_X|LAYOUT_FILL_Y,
	                                              0,0,0,0, 0,0,0,0, 0,0);
	FXMDIClient *mdiclient = new FXMDIClient(hf,LAYOUT_FILL_X|LAYOUT_FILL_Y);
	FXMDIChild *mdichild = new FXMDIChild(mdiclient,"Test",0,0,MDI_MAXIMIZED);
	FXGLVisual *glvisual = new FXGLVisual(app,VISUAL_DOUBLEBUFFER);
	FXGLViewer *viewer = new FXGLWindow(mdichild,glvisual);
	FXGLGroup *scene = new FXGLGroup;
	viewer->setScene(scene);

	scene->append(new FXGLCylinder(0.0f,0.0f,0.0f,SHADING_SMOOTH|STYLE_SURFACE));
	scene->append(new FXGLCylinder(20.0f,0.0f,0.0f,SHADING_SMOOTH|STYLE_SURFACE));

	window.create();
	window.show();
	app->run();

	return 0;
}
