#include <irrlicht.h>
#include <iostream>
#include "driverChoice.h"
#include "events.hpp"

using namespace std;
using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
// ask user for driver
    video::E_DRIVER_TYPE driverType=driverChoiceConsole();
    if (driverType==video::EDT_COUNT)
        return 1;

    // create device
    MyEventReceiver receiver;

    IrrlichtDevice* device = createDevice(driverType,
            core::dimension2d<u32>(640, 480), 16, false, false, false, &receiver);
    if (device == 0)
        return 1; // could not create selected driver.

    device->setWindowCaption(L"OFW");

    IVideoDriver* driver = device->getVideoDriver();
    ISceneManager* smgr = device->getSceneManager();

    enum
    {
        // I use this ISceneNode ID to indicate a scene node that is
        // not pickable by getSceneNodeAndCollisionPointFromRay()
        ID_IsNotPickable = 0,

        // I use this flag in ISceneNode IDs to indicate that the
        // scene node can be picked by ray selection.
        IDFlag_IsPickable = 1 << 0,

        // I use this flag in ISceneNode IDs to indicate that the
        // scene node can be highlighted.  In this example, the
        // homonids can be highlighted, but the level mesh can't.
        IDFlag_IsHighlightable = 1 << 1
    };

    // MAP
    device->getFileSystem()->addFileArchive("map-20kdm2.pk3");
    scene::IAnimatedMesh* q3levelmesh = smgr->getMesh("20kdm2.bsp");
    scene::IMeshSceneNode* q3node = 0;
    // The Quake mesh is pickable, but doesn't get highlighted.
    if (q3levelmesh)
        q3node = smgr->addOctreeSceneNode(q3levelmesh->getMesh(0), 0, IDFlag_IsPickable);

    // SCENE
    scene::ITriangleSelector* selector = 0;
    if (q3node)
    {
        q3node->setPosition(core::vector3df(-1350,-130,-1400));
        selector = smgr->createOctreeTriangleSelector(q3node->getMesh(), q3node, 128);
        q3node->setTriangleSelector(selector);
        // We're not done with this selector yet, so don't drop it.
    }


    IAnimatedMesh* goat = smgr->getMesh("../media/picacode.obj");
    if (!goat)
    {
        device->drop();
        return 1;
    }
    IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( goat );

    if (node)
    {
        node->setMaterialFlag(EMF_LIGHTING, false);
        //node->setMD2Animation(scene::EMAT_STAND);
        node->setPosition(vector3df(0,0,0));
        node->setScale(vector3df(0.40,0.40,0.40));
        node->setRotation(vector3df(0,180,0));
        node->setMaterialTexture( 0, driver->getTexture("../media/picacode_tex.jpg") );
    }
    if (selector)
    {
        scene::ISceneNodeAnimator* anim2 = smgr->createCollisionResponseAnimator(
            selector, node, core::vector3df(10, 1, 30),
            core::vector3df(0,-10,0), core::vector3df(0,0,0));
        selector->drop(); // As soon as we're done with the selector, drop it.
        node->addAnimator(anim2);
        anim2->drop();  // And likewise, drop the animator when we're done referring to it.
    }

    device->getCursorControl()->setVisible(false);

    scene::ISceneCollisionManager* collMan = smgr->getSceneCollisionManager();

    int lastFPS = -1;

    // In order to do framerate independent movement, we have to know
    // how long it was since the last frame
    u32 then = device->getTimer()->getTime();

    // Set a jump speed of 3 units per second, which gives a fairly realistic jump
    // when used with the gravity of (0, -10, 0) in the collision response animator.
    scene::ICameraSceneNode* camera = smgr->addCameraSceneNode(node);
    camera->setPosition(core::vector3df(3,3,1));
    camera->setTarget(core::vector3df(100,30,30));

    // This is the movemen speed in units per second.
    const f32 MOVEMENT_SPEED = 50.f;
    const f32 JUMP_SPEED = 200.f;

    core::vector3df cameraPosition = camera->getPosition();
    while(device->run())
    {

        // Work out a frame delta time.
        const u32 now = device->getTimer()->getTime();
        const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
        then = now;

        core::vector3df nodePosition = node->getPosition();
        //node->setRotation(cameraPosition.getHorizontalAngle());
        cameraPosition = camera->getPosition();
        core::vector3df cameraTarget = camera->getTarget();
        //cout << "Goat-target: " << nodePosition.X << ", " << nodePosition.Y << ", " <<  nodePosition.Z << endl;
        //cout << "Camera     : " << cameraPosition.X << ", " << cameraPosition.Y << ", " <<  cameraPosition.Z << endl;

        // move goat
        //if(receiver.IsKeyDown(KEY_KEY_W))
        //    nodePosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        //else if(receiver.IsKeyDown(KEY_KEY_S))
        //    nodePosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
        //if(receiver.IsKeyDown(KEY_KEY_A))
        //    nodePosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        //else if(receiver.IsKeyDown(KEY_KEY_D))
        //    nodePosition.X += MOVEMENT_SPEED * frameDeltaTime;
        //if(receiver.IsKeyDown(KEY_SPACE))
        //    nodePosition.Y += JUMP_SPEED * frameDeltaTime;

        // move camera
        //if(receiver.IsMoveMouse(EKA_MOVE_FORWARD))
        //    cameraPosition.Z += MOVEMENT_SPEED * frameDeltaTime;
        //else if(receiver.IsMoveMouse(EKA_MOVE_BACKWARD))
        //    cameraPosition.Z -= MOVEMENT_SPEED * frameDeltaTime;
        //if(receiver.IsMoveMouse(EKA_STRAFE_LEFT))
        //    cameraPosition.X -= MOVEMENT_SPEED * frameDeltaTime;
        //else if(receiver.IsMoveMouse(EKA_STRAFE_RIGHT))
        //    cameraPosition.X += MOVEMENT_SPEED * frameDeltaTime;
        // if(receiver.IsMoveMouse(KEY_PLUS))
        //     cameraPosition.Y += MOVEMENT_SPEED * frameDeltaTime;
        // else if(receiver.IsMoveMouse(KEY_MINUS))
        //     cameraPosition.Y -= MOVEMENT_SPEED * frameDeltaTime;


        node->setPosition(nodePosition); // cambiamos pos de la cabra
        camera->setPosition(cameraPosition + (nodePosition - node->getPosition())); // camara va detrás del muñeco
        //camera->setPosition(cameraPosition);
        camera->setTarget(nodePosition); // punto de referencia es la cabra
        // TODO. mover la cámara con el ratón
        // TODO. girar el muñeco mientras se gira la cámara
        // TODO. mejorar el movimiento. cuestas abajo, escaleras, etc. (if escaleras menor que ... que las suba bien)

        driver->beginScene(true, true, video::SColor(255,113,113,133));

        smgr->drawAll(); // draw the 3d scene
        device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

        driver->endScene();

        int fps = driver->getFPS();
        if (lastFPS != fps)
        {
            core::stringw str = L"OFW [";
            str += driver->getName();
            str += "] FPS:";
            str += fps;

            device->setWindowCaption(str.c_str());
            lastFPS = fps;
        }
        else
            device->yield();
    }

    device->drop();

    return 0;
}
