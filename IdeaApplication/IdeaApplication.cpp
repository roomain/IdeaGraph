#include "IdeaApplication.h"

IdeaApplication::IdeaApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.centralWidget->hide();
    //ui.JsonContent->loadJson("C:/librairies/glTF/extensions/2.0/Vendor/EXT_mesh_gpu_instancing/samples/teapots_galore_id/teapots_galore_id.gltf");
}

IdeaApplication::~IdeaApplication()
{}
