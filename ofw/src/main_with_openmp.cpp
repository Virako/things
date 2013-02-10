#include <irrlicht.h>
#include "driverChoice.h"
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <omp.h>

#include "character.hpp"
#include "cte.hpp"

using namespace irr;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

void print_data(string data){
    sleep(1);
    cout << "DATA: " << data << "\n";
}

int main()
{
    // ask user for driver
    video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    if (driverType==video::EDT_COUNT)
        return 1;

    // Create device
    IrrlichtDevice* device = createDevice(driverType,
            core::dimension2d<u32>(640, 480), 16, false, false, false, NULL);
    if (device == 0)
        return 1; // could not create selected driver.
    device->setWindowCaption(L"OFW");

    // Load video, scene and gui
    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

    // SCENE: insert player
    scene::IAnimatedMesh* player = smgr->getMesh("../media/ninja.b3d");
    if (!player)
    {
        device->drop();
        return 1;
    }
    scene::IAnimatedMeshSceneNode* player_ani = smgr->addAnimatedMeshSceneNode(player);
    if (player_ani)
    {
        player_ani->setMaterialFlag(video::EMF_LIGHTING, false);
        player_ani->setFrameLoop(0, 13);  // nº frame
        player_ani->setAnimationSpeed(10); // fps
        player_ani->setMaterialTexture(0, driver->getTexture("../media/ninja.jpg"));
        player_ani->setScale(core::vector3df(1,1,1));
        player_ani->setPosition(core::vector3df(0,0,0));
        player_ani->setRotation(core::vector3df(0,0,0));
    }

    // SCENE: insert camera
    scene::ICameraSceneNode* camera = smgr->addCameraSceneNode(player_ani);
    camera->setPosition(core::vector3df(0, 15, 20));
    camera->setTarget(player_ani->getPosition());

    // Create character
    character virako;

    #pragma omp parallel
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                #pragma omp critical
                {
                    // BUCLE
                    while(device->run())
                    {
                        //virako.height_dec();
                        driver->beginScene(true, true, video::SColor(255,113,113,133));
                        smgr->drawAll();
                        guienv->drawAll(); // draw the gui environment
                        driver->endScene();
                    }
                    device->drop();
                }
            }
            #pragma omp section
            {
                while(true)
                {
                    print_data(static_cast<ostringstream*>( &(ostringstream() << virako.get_height()) )->str());
                }
            }
        }
    }
    return 0;
}
