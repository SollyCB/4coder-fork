// @CommandsTodo
// move_to_<top|bottom>_of_view

void sol_do_command(Application_Links *app, sol_custom_cmd cmd)
{
    View_ID view = get_active_view(app, Access_ReadWriteVisible);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadWriteVisible);

    History_Group group = history_group_begin(app, buffer);

    // I think that this is an unnecessary check because of
    // checks in the calling code.
    if (!cmd.cmd && sol_do_count) {
        sol_do_count = 0;
        history_group_end(group);
        return;
    }

    // @Todo
//    for(int i = 0; i < sol_do_count; ++i)
//        sol_command.cmd(app);
    cmd.cmd(app);

    sol_do_count = 0;

    history_group_end(group);
}

CUSTOM_COMMAND_SIG(noinput) {
    sol_current_mode = sol_current_mode;
}

CUSTOM_COMMAND_SIG(textinput) 
{
    leave_current_input_unhandled(app);
}

CUSTOM_COMMAND_SIG(enter_normal_mode)
{
    sol_current_mode = SOL_MODE_NORMAL;
    active_color_table.arrays[defcolor_cursor].vals[0] = 0xff000000;
}

CUSTOM_COMMAND_SIG(enter_insert_mode)
{
    sol_current_mode = SOL_MODE_INSERT;
    active_color_table.arrays[defcolor_cursor].vals[0] = 0xffaaaaaa;
}

CUSTOM_COMMAND_SIG(enter_delete_mode)
{
    sol_current_mode = SOL_MODE_DELETE;
    active_color_table.arrays[defcolor_cursor].vals[0] = 0xffff0000;
}

CUSTOM_COMMAND_SIG(enter_change_mode)
{
    sol_current_mode = SOL_MODE_CHANGE;
    active_color_table.arrays[defcolor_cursor].vals[0] = 0xffff0000;
}

CUSTOM_COMMAND_SIG(insert_char_right)
{
    move_right(app);
    enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(insert_at_eol)
{
    seek_end_of_line(app);
    enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(insert_at_bol)
{
    seek_beginning_of_line(app);
    enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(backspace_to_bol)
{
    set_mark(app);
    seek_beginning_of_line(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(delete_to_eol)
{
    set_mark(app);
    seek_end_of_line(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_bol)
{
    set_mark(app);
    seek_beginning_of_line(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_eol)
{
    set_mark(app);
    seek_end_of_line(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(change_line)
{
    seek_beginning_of_line(app);
    set_mark(app);
    seek_end_of_line(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}


CUSTOM_COMMAND_SIG(seek_beginning_of_next_word)
{
    move_right_alpha_numeric_boundary(app);
}

CUSTOM_COMMAND_SIG(seek_beginning_of_next_whitespace)
{
    move_right_whitespace_boundary(app);
}

CUSTOM_COMMAND_SIG(delete_to_beginning_of_next_whitespace)
{
    set_mark(app);
    move_right_whitespace_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_beginning_of_next_whitespace)
{
    set_mark(app);
    move_right_whitespace_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(delete_to_beginning_of_next_word)
{
    set_mark(app);
    move_right_alpha_numeric_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_beginning_of_next_word)
{
    set_mark(app);
    move_right_alpha_numeric_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(seek_beginning_of_last_word)
{
    move_left_alpha_numeric_boundary(app);
}

CUSTOM_COMMAND_SIG(seek_beginning_of_last_whitespace)
{
    move_left_whitespace_boundary(app);
}

CUSTOM_COMMAND_SIG(delete_to_beginning_of_last_whitespace)
{
    set_mark(app);
    move_left_whitespace_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_beginning_of_last_whitespace)
{
    set_mark(app);
    move_left_whitespace_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(delete_to_beginning_of_last_word)
{
    set_mark(app);
    move_left_alpha_numeric_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_beginning_of_last_word)
{
    set_mark(app);
    move_left_alpha_numeric_boundary(app);
    delete_range(app);

    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

// @Todo Cannot figure out how to do this yet without being
// able to sort of project keys. Would be easy if I could
// say "insert an enter key now"
CUSTOM_COMMAND_SIG(open_line_below) {}
CUSTOM_COMMAND_SIG(open_line_above) {}

CUSTOM_COMMAND_SIG(copy_line)
{
    seek_beginning_of_line(app);
    set_mark(app);
    seek_end_of_line(app);
    copy(app);
}

bool sol_panel_toggle = 0;
CUSTOM_COMMAND_SIG(toggle_panel)
{
    if (sol_panel_toggle)
        change_active_panel(app);
    else
        change_active_panel_backwards(app);
    sol_panel_toggle = !sol_panel_toggle;
}

// @Todo Look at the macro code, it plays weird with undo. I tried putting the
// history wrapper in the keyboard_macro_play function in _macro.cpp, but still
// zilch...
CUSTOM_COMMAND_SIG(keyboard_macro_play)
{
    keyboard_macro_replay(app);
}

bool sol_recording_macro = 0;
CUSTOM_COMMAND_SIG(keyboard_macro_toggle_recording)
{
    if (sol_recording_macro) {
        keyboard_macro_finish_recording(app);
    } else {
        keyboard_macro_start_recording(app);
    }
    sol_recording_macro = !sol_recording_macro;
}

CUSTOM_COMMAND_SIG(del_delete_current_scope)
{
    select_surrounding_scope(app);
    delete_current_scope(app);
    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_current_scope)
{
    select_surrounding_scope(app);
    delete_current_scope(app);
    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(delete_to_token_right)
{
    set_mark(app);
    move_right_token_boundary(app);
    delete_range(app);
    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(delete_to_token_left)
{
    set_mark(app);
    move_left_token_boundary(app);
    delete_range(app);
    if (sol_current_mode == SOL_MODE_DELETE)
        enter_normal_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_token_right)
{
    set_mark(app);
    move_right_token_boundary(app);
    delete_range(app);
    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(change_to_token_left)
{
    set_mark(app);
    move_left_token_boundary(app);
    delete_range(app);
    if (sol_current_mode == SOL_MODE_CHANGE)
        enter_insert_mode(app);
}

CUSTOM_COMMAND_SIG(move_down_20)
{
    move_down_10(app);
    move_down_10(app);
}

CUSTOM_COMMAND_SIG(move_up_20)
{
    move_up_10(app);
    move_up_10(app);
}
