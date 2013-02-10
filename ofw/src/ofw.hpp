#ifndef __OFW_H
#define __OFW_H

#include <string>
#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;

// i18n
#include <libintl.h>
#define _(x) gettext(x)

#include "scene/map.hpp"

namespace ofw
{

    namespace audio { }
    namespace config { }
    namespace core { }
    namespace gui { }
    namespace scene { }
    namespace server { }

}

// TODO: get root_dir from CMake
// static std::string root_dir = ""
static const std::string root_dir = "/home/virako/ofw/";
static const std::string LANG_PATH = root_dir + "locale";
static const std::string PROYECT_NAME = "Open Fantasy Wordl";
static const std::string PROYECT_NAME_ACRONYM = "ofw";

class ofw {
    private:
        irr::video::E_DRIVER_TYPE driver_type;
    public:
        //ofw(irr::video::E_DRIVER_TYPE prefered_driver, irr::IrrlichtDevice device);
        //void init();
        /**
         * Init the internationalization with your computer language.
         */
        void init_i18n();

        /**
         * Get the Irrlicht driver and init device.
         * @param type_driver E_DRIVER_TYPE from Irrlicht.
         * @return Irrlicht device.
         */
        irr::IrrlichtDevice init_device(irr::video::E_DRIVER_TYPE
                type_driver=NULL, irr::u32 bits=32, bool fullscreen=true, bool
                shadows=true, bool vsync=true, irr::IEventReceiver
                receiver=NULL);

};

}

#endif
