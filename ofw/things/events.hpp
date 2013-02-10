#ifndef __EVENTS_H
#define __EVENTS_H

#include <irrlicht.h>

using namespace irr;

class MyEventReceiver : public IEventReceiver
{
    public:
        MyEventReceiver();
        ~MyEventReceiver();
        virtual bool OnEvent(const SEvent& event);
        int mousex, mousey, mousez;

    private:
        // We use this array to store the current state of each key
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
};

#endif
