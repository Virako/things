#include <iostream>

#include "core/core.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

/**
 * Main.
 */
int main()
{
    ofw_core::init_i18n();

    // Select driver: gui or terminal
    video::E_DRIVER_TYPE driverType=driverChoiceConsole();

    IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(640, 480), 16, false);
    //if (device == 0)
    //  return 1;
    //IrrlichtDevice* device = ofw_core::init_device();

    // init_driver
    //device->setWindowCaption(L"OFW");

    // Load video, scene and gui
    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    smgr->setAmbientLight(video::SColorf(0.3,0.3,0.3,1));

    scene::IAnimatedMesh* mesh = smgr->getMesh("../media/Escenario.obj");
    scene::ISceneNode* node = 0;

    // SCENARIUM
    if (mesh) {
        // The optimization with the Octree is only useful when drawing huge
        // meshes consisting of lots of geometry.
        //node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, 512);
        node = smgr->addMeshSceneNode(mesh->getMesh(0));
    }
    if (node) {
        //node->setScale(core::vector3df(0.2,0.2,0.2));
        cout << "NODESSS: " << node->getMaterialCount() << endl;
        for (u32 j = 0; j < node->getMaterialCount(); ++j){
            cout << &node->getMaterial(j) << endl;
        }
        node->getMaterial(0).setTexture(0, driver->getTexture("../media/Templo_frontal _color.JPG"));
        node->getMaterial(1).setTexture(0, driver->getTexture("../media/Templo_frontal _color.JPG"));
        node->getMaterial(2).setTexture(0, driver->getTexture("../media/Cliffs0016_1_S_wall.jpg"));
        node->getMaterial(3).setTexture(0, driver->getTexture("../media/Cliffs0016_1_S_wall.jpg"));
        node->getMaterial(4).setTexture(0, driver->getTexture("../media/Cliffs0016_1_S_wall.jpg"));
        node->getMaterial(5).setTexture(0, driver->getTexture("../media/Cliffs0454_S_suelo.jpg"));
        node->getMaterial(6).setTexture(0, driver->getTexture("../media/Templo_frontal _color.JPG"));
        //node->setMaterialFlag(video::EMF_LIGHTING, true);
        //node->setMaterialType(video::EMT_SOLID_2_LAYER);
        node->setPosition(core::vector3df(0,0,0));
    }

    // SCENE: insert player
    scene::IAnimatedMesh* player = smgr->getMesh("../media/Gliptodont_Lv1_03.b3d");
    if (!player) {
        device->drop();
        return 1;
    }
    scene::IAnimatedMeshSceneNode* player_ani = smgr->addAnimatedMeshSceneNode(player);
    if (player_ani) {
        player_ani->setMaterialTexture(0, driver->getTexture("../media/Gliptodon_Lv1_Color.jpg"));
        player_ani->setMaterialTexture(1, driver->getTexture("../media/Gliptodon_Lv1_specular.JPG"));
        player_ani->setMaterialFlag(video::EMF_LIGHTING, false);
        //player_ani->getMaterial(1).SpecularColor.set(255,255,255,255);
        //player_ani->setFrameLoop(0, 6000);  // nº frame
        //player_ani->setAnimationSpeed(300); // fps
        //player_ani->setMaterialType(video::EMT_SOLID);
        player_ani->setScale(core::vector3df(6,6,6));
        player_ani->setPosition(core::vector3df(0,20,60));
        player_ani->setRotation(core::vector3df(0,140,0));
    }

    // SCENE: insert weapon
    scene::IAnimatedMesh* weapon = smgr->getMesh("../media/pico.3ds");
    if (!weapon)
    {
        device->drop();
        return 1;
    }
    scene::IAnimatedMeshSceneNode* weapon_ani = smgr->addAnimatedMeshSceneNode(weapon);
    if (weapon_ani)
    {
        weapon_ani->setMaterialTexture(0, driver->getTexture("../media/Pico_color02.PNG"));
        weapon_ani->setMaterialTexture(1, driver->getTexture("../media/Pico_01bump.PNG"));
        weapon_ani->getMaterial(1).Shininess = 20.0f;
        //weapon_ani->setMaterialTexture(1, driver->getTexture("../media/picacode_tex.jpg"));
        weapon_ani->setMaterialFlag(video::EMF_LIGHTING, false);
        //weapon_ani->setMaterialType(video::EMT_NORMAL_MAP_TRANSPARENT_VERTEX_ALPHA);
        //weapon_ani->setMaterialType(video::EMT_REFLECTION_2_LAYER);
        weapon_ani->setScale(core::vector3df(0.2,0.2,0.2));
        //weapon_ani->setPosition(core::vector3df(0,0,0));
        //weapon_ani->setRotation(core::vector3df(0,0,0));
    }
    irr::scene::ISceneNode* hand = player_ani->getJointNode("Gliptodont_Lv1");

    scene::ISkinnedMesh* player_b = (scene::ISkinnedMesh*) smgr->getMesh("../media/Gliptodont_Lv1_04.b3d");
    cout << _("HUESOS") << endl;
    for (int i=0; i < player_ani->getJointCount(); i++)
    {
        cout << _("hello") << endl;
        cout << i << endl;
        cout << player_b->getAllJoints()[i]->Name.c_str() << endl;
    }
    hand->addChild(weapon_ani);

    // SCENE: insert camera
    scene::ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS();
    camera->setPosition(core::vector3df(40,15,40));
    camera->setTarget(player_ani->getPosition() - core::vector3df(0,-15,0));

    //FPS
    int lastFPS = -1;

    // BUCLE
    while(device->run())
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(255,113,113,133));
            smgr->drawAll();
            guienv->drawAll(); // draw the gui environment
            driver->endScene();

            int fps = driver->getFPS();

            if (lastFPS != fps)
            {
                core::stringw str = L"EXAMPLE OFW";
                str += driver->getName();
                str += "] FPS:";
                str += fps;

                device->setWindowCaption(str.c_str());
                lastFPS = fps;
            }
        }
        else
            device->yield();
    }
    device->drop();
    return 0;
}
