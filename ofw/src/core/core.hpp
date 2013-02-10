#ifndef __CORE_H
#define __CORE_H

#include <string>
#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;
using namespace std;

// i18n
#include <libintl.h>
#define _(x) gettext(x)


namespace ofw_core {


// TODO: get root_dir from CMake
// static std::string root_dir = ""
static const string root_dir = "/home/virako/ofw/";
static const string LANG_PATH = root_dir + "locale";
static const string PROYECT_NAME = "Open Fantasy Wordl";
static const string PROYECT_NAME_ACRONYM = "ofw";

video::E_DRIVER_TYPE driver_type; // TODO: quiero que se guarde en la conf.


/**
 * Init the internationalization with your computer language.
 */
inline void init_i18n(){
    bind_textdomain_codeset(PROYECT_NAME_ACRONYM.c_str(), "UTF-8");
    setlocale(LC_ALL, "");
    bindtextdomain(PROYECT_NAME_ACRONYM.c_str(), LANG_PATH.c_str());
    textdomain(PROYECT_NAME_ACRONYM.c_str());
}

/**
 * @brief Init Irrlicht device.
 *
 * @param desk_size Size of the window or the video mode in fullscreen mode.
 * @param bits Bits per pixel in fullscreen mode. Ignored if windowed mode.
 * @param fullscreen Should be set to true if the device should run in
 * fullscreen. Otherwise the device runs in windowed mode.
 * @param shadows Set this to true, if you want the engine be able to draw
 * stencil buffer shadows. Note that not all devices are able to use the stencil
 * buffer.
 * @param vsync Specifies vertical syncronisation: If set to true, the driver
 * will wait for the vertical retrace period, otherwise not.
 * @param receiver A user created event receiver.
 *
 * @return Returns pointer to the created IrrlichtDevice or null if the device
 * could not be created.
 */
inline IrrlichtDevice* init_device( core::dimension2d<u32> desk_size=core::dimension2d<u32>(), u32
        bits=32, bool fullscreen=false, bool shadows=true, bool vsync=true, IEventReceiver*
        receiver=NULL){
    if (desk_size == core::dimension2d<u32>()){
        // create null device to detect screen resolution
        IrrlichtDevice *nulldevice = createDevice(video::EDT_NULL);
        desk_size = nulldevice->getVideoModeList()->getDesktopResolution();
    }
    return createDevice(driver_type, desk_size, bits, fullscreen, shadows, vsync, receiver);
    //return device;
}

/**
 * @brief Change driver type. Example: Opengl, DirectX, etc
 */
inline void change_driver() {
    // TODO: change in defaults variables.
    driver_type = driverChoiceConsole();
    // TODO: error?
    //if !(driverType == video::EDT_COUNT)
    //    return -1;
}




}

#endif

