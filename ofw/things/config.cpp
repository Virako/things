// Config controls, video, audio, ...

SKeyMap keyMap[8];
keyMap[0].Action = EKA_MOVE_FORWARD;
keyMap[0].KeyCode = KEY_UP;
keyMap[1].Action = EKA_MOVE_FORWARD;
keyMap[1].KeyCode = KEY_KEY_W;

keyMap[2].Action = EKA_MOVE_BACKWARD;
keyMap[2].KeyCode = KEY_DOWN;
keyMap[3].Action = EKA_MOVE_BACKWARD;
keyMap[3].KeyCode = KEY_KEY_S;

keyMap[4].Action = EKA_STRAFE_LEFT;
keyMap[4].KeyCode = KEY_LEFT;
keyMap[5].Action = EKA_STRAFE_LEFT;
keyMap[5].KeyCode = KEY_KEY_A;

keyMap[6].Action = EKA_STRAFE_RIGHT;
keyMap[6].KeyCode = KEY_RIGHT;
keyMap[7].Action = EKA_STRAFE_RIGHT;
keyMap[7].KeyCode = KEY_KEY_D;
