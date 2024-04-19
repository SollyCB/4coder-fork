sol_mode_cmd_table DEFAULT_BINDING_TABLE = {
    .normal = {noinput,   noinput,   noinput, noinput, noinput, noinput, noinput, noinput,},
    .insert = {textinput, textinput, noinput, noinput, noinput, noinput, noinput, noinput,},
    .del    = {noinput,   noinput,   noinput, noinput, noinput, noinput, noinput, noinput,},
    .change = {noinput,   noinput,   noinput, noinput, noinput, noinput, noinput, noinput,},
};

bool SOL_IS_BIND_TABLE_INITIALIZED = 0;

sol_mode_cmd_table sol_bind_table[] = {
    {}, // 4ed keys start from 1
    DEFAULT_BINDING_TABLE, /*KeyCode_A*/
    DEFAULT_BINDING_TABLE, /*KeyCode_B*/
    DEFAULT_BINDING_TABLE, /*KeyCode_C*/
    DEFAULT_BINDING_TABLE, /*KeyCode_D*/
    DEFAULT_BINDING_TABLE, /*KeyCode_E*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F*/
    DEFAULT_BINDING_TABLE, /*KeyCode_G*/
    DEFAULT_BINDING_TABLE, /*KeyCode_H*/
    DEFAULT_BINDING_TABLE, /*KeyCode_I*/
    DEFAULT_BINDING_TABLE, /*KeyCode_J*/
    DEFAULT_BINDING_TABLE, /*KeyCode_K*/
    DEFAULT_BINDING_TABLE, /*KeyCode_L*/
    DEFAULT_BINDING_TABLE, /*KeyCode_M*/
    DEFAULT_BINDING_TABLE, /*KeyCode_N*/
    DEFAULT_BINDING_TABLE, /*KeyCode_O*/
    DEFAULT_BINDING_TABLE, /*KeyCode_P*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Q*/
    DEFAULT_BINDING_TABLE, /*KeyCode_R*/
    DEFAULT_BINDING_TABLE, /*KeyCode_S*/
    DEFAULT_BINDING_TABLE, /*KeyCode_T*/
    DEFAULT_BINDING_TABLE, /*KeyCode_U*/
    DEFAULT_BINDING_TABLE, /*KeyCode_V*/
    DEFAULT_BINDING_TABLE, /*KeyCode_W*/
    DEFAULT_BINDING_TABLE, /*KeyCode_X*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Y*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Z*/
    DEFAULT_BINDING_TABLE, /*KeyCode_0*/
    DEFAULT_BINDING_TABLE, /*KeyCode_1*/
    DEFAULT_BINDING_TABLE, /*KeyCode_2*/
    DEFAULT_BINDING_TABLE, /*KeyCode_3*/
    DEFAULT_BINDING_TABLE, /*KeyCode_4*/
    DEFAULT_BINDING_TABLE, /*KeyCode_5*/
    DEFAULT_BINDING_TABLE, /*KeyCode_6*/
    DEFAULT_BINDING_TABLE, /*KeyCode_7*/
    DEFAULT_BINDING_TABLE, /*KeyCode_8*/
    DEFAULT_BINDING_TABLE, /*KeyCode_9*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Space*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Tick*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Minus*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Equal*/
    DEFAULT_BINDING_TABLE, /*KeyCode_LeftBracket*/
    DEFAULT_BINDING_TABLE, /*KeyCode_RightBracket*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Semicolon*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Quote*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Comma*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Period*/
    DEFAULT_BINDING_TABLE, /*KeyCode_ForwardSlash*/
    DEFAULT_BINDING_TABLE, /*KeyCode_BackwardSlash,*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Tab*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Escape*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Pause*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Up*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Down*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Left*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Right*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Backspace*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Return*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Delete*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Insert*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Home*/
    DEFAULT_BINDING_TABLE, /*KeyCode_End*/
    DEFAULT_BINDING_TABLE, /*KeyCode_PageUp*/
    DEFAULT_BINDING_TABLE, /*KeyCode_PageDown*/
    DEFAULT_BINDING_TABLE, /*KeyCode_CapsLock*/
    DEFAULT_BINDING_TABLE, /*KeyCode_NumLock*/
    DEFAULT_BINDING_TABLE, /*KeyCode_ScrollLock*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Menu*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Shift*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Control*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Alt*/
    DEFAULT_BINDING_TABLE, /*KeyCode_Command*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F1*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F2*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F3*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F4*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F5*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F6*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F7*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F8*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F9*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F10*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F11*/
    DEFAULT_BINDING_TABLE, /*KeyCode_F12*/
};
