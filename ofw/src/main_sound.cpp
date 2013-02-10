#include <irrlicht.h>
#include "driverChoice.h"
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <omp.h>
#include <AL/alut.h>

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
    //Create character
    character virako;
    bool thread_flag;
    #pragma omp parallel
    {
        #pragma omp sections nowait
        {
            #pragma omp section
            {
                while(true)
                {
                    if(thread_flag)
                    print_data(static_cast<ostringstream*>( &(ostringstream() << virako.get_height()) )->str());
                }
            }
            #pragma omp section
            {
                int fail = -1;
                while(true){
                    sleep(1);
                    if(thread_flag){
                        try{
                            ALCcontext *context;
                            ALCdevice* device;

                            device = alcOpenDevice(NULL);
                            if(device == NULL){
                                throw fail;
                            }
                            //Creating and setting anctual context.
                            context = alcCreateContext(device,NULL);
                            alcMakeContextCurrent(context);

                            alGetError();

                            char*     alBuffer;             //data for the buffer
                            ALenum alFormatBuffer;    //buffer format
                            ALsizei   alFreqBuffer;       //frequency
                            long       alBufferLen;        //bit depth
                            ALboolean    alLoop;         //loop
                            unsigned int alSource;      //source
                            unsigned int alSampleSet;

                            //load the wave file
                            alutLoadWAVFile("applause.wav",&alFormatBuffer, (void **) &alBuffer,(unsigned int *)&alBufferLen, &alFreqBuffer, &alLoop);

                            //create a source
                            alGenSources(1, &alSource);

                            //create  buffer
                            alGenBuffers(1, &alSampleSet);

                            //put the data into our sampleset buffer
                            alBufferData(alSampleSet, alFormatBuffer, alBuffer, alBufferLen, alFreqBuffer);

                            //assign the buffer to this source
                            alSourcei(alSource, AL_BUFFER, alSampleSet);

                            //release the data
                            alutUnloadWAV(alFormatBuffer, alBuffer, alBufferLen, alFreqBuffer);

                            alSourcei(alSource,AL_LOOPING,AL_TRUE);

                            //play
                            alSourcePlay(alSource);

                            alutSleep (10);
                            //to stop
                            //alSourceStop(alSource);
                            //
                            alDeleteSources(1,&alSource);

                            //delete our buffer
                            alDeleteBuffers(1,&alSampleSet);

                            context=alcGetCurrentContext();

                            //Get device for active context
                            device=alcGetContextsDevice(context);

                            //Disable context
                            alcMakeContextCurrent(NULL);

                            //Release context(s)
                            alcDestroyContext(context);

                            //Close device
                            alcCloseDevice(device);

                        }catch(...){
                            cout << "error in sound initialization" << "\n";
                        }
                    }
                }
            }
            #pragma omp section
            {
            }
        }
        #pragma omp single
        {
            try{
                int fail = -1;
                // ask user for driver
                video::E_DRIVER_TYPE driverType=driverChoiceConsole();
                if (driverType == video::EDT_COUNT){
                    throw fail;
                }
                //makes start sound threat;
                thread_flag = true;

                // Create device
                IrrlichtDevice* device = createDevice(driverType,
                        core::dimension2d<u32>(640, 480), 16, false, false, false, NULL);
                if (device == 0){
                    throw fail;// could not create selected driver.
                }else{
                    device->setWindowCaption(L"OFW");
                }
                // Load video, scene and gui
                video::IVideoDriver* driver = device->getVideoDriver();
                scene::ISceneManager* smgr = device->getSceneManager();
                gui::IGUIEnvironment* guienv = device->getGUIEnvironment();

                // SCENE: insert player
                scene::IAnimatedMesh* player = smgr->getMesh("../media/ninja.b3d");
                if (!player){
                    device->drop();
                    throw fail;
                }

                scene::IAnimatedMeshSceneNode* player_ani = smgr->addAnimatedMeshSceneNode(player);
                if (player_ani){
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

                // BUCLE
                while(device->run())
                {
                    if(device->isWindowActive()){
                        driver->beginScene(true, true, video::SColor(255,113,113,133));
                        smgr->drawAll();
                        guienv->drawAll(); // draw the gui environment
                        driver->endScene();
                    }else{
                        device->yield();
                    }
                }
                device->drop();
            }catch(...){
                    cout << "error while initializing " << "\n";
            }
        }
    }
    return 0;
}
