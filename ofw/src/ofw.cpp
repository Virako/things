#include "ofw.hpp"

namespace ofw
{

void ofw::init_i18n(){
    bind_textdomain_codeset(PROYECT_NAME_ACRONYM.c_str(), "UTF-8");
    setlocale(LC_ALL, "");
    bindtextdomain(PROYECT_NAME_ACRONYM.c_str(), LANG_PATH.c_str());
    textdomain(PROYECT_NAME_ACRONYM.c_str());
}

irr::IrrlichtDevice init_device(irr::video::E_DRIVER_TYPE type_driver){
    // Select console
    if (!type_driver)
        irr::video::E_DRIVER_TYPE type_driver = driverChoiceConsole();
    if (type_driver == irr::video::EDT_COUNT){
        // create null device to detect screen resolution
        IrrlichtDevice *nulldevice = createDevice(video::EDT_NULL);
        irr::core::dimension2d<u32> deskres = nulldevice->getVideoModeList()->getDesktopResolution();
    }
    // Create device
    bool SHADOWS = true; // para config
    return createDevice(type_driver, deskres, 32, false, SHADOWS, false, NULL);
}

}
