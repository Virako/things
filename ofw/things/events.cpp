#include <iostream>

#include "events.hpp"

using namespace std;

MyEventReceiver::MyEventReceiver()
{
    for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
}

MyEventReceiver::~MyEventReceiver(){}

// This is the one method that we have to implement
bool MyEventReceiver::OnEvent(const SEvent& event)
{

    int mousex, mousey, mousez;
    // Keypress
    if (event.EventType == EET_KEY_INPUT_EVENT)
    {
        if (event.KeyInput.Key == KEY_SPACE && event.KeyInput.PressedDown == false)
            cout << "SPACE" << endl;
        if (event.KeyInput.Key == KEY_KEY_W)
            cout << "W" << endl;
        if (event.KeyInput.Key == KEY_KEY_S)
            cout << "S" << endl;
        if (event.KeyInput.Key == KEY_KEY_A)
            cout << "A" << endl;
        if (event.KeyInput.Key == KEY_KEY_D)
            cout << "D" << endl;
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }

    // Mouse
    if(event.EventType == EET_MOUSE_INPUT_EVENT)
    {
        switch (event.MouseInput.Event)
        {
            case irr::EMIE_MOUSE_MOVED          :
                mousex = event.MouseInput.X;
                mousey = event.MouseInput.Y;
                break;
            case irr::EMIE_MOUSE_WHEEL          :
                mousez = event.MouseInput.Wheel;
                break;
        }
    }
    return false;
}
