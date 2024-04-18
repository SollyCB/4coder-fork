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
    active_color_table.arrays[defcolor_cursor].vals[0] = 0xff00ff00;
}

CUSTOM_COMMAND_SIG(enter_insert_mode)
{
    sol_current_mode = SOL_MODE_INSERT;
    active_color_table.arrays[defcolor_cursor].vals[0] = 0xff0000ff;
}

CUSTOM_COMMAND_SIG(enter_delete_mode)
{
    sol_current_mode = SOL_MODE_DELETE;
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
}

CUSTOM_COMMAND_SIG(delete_to_eol)
{
    set_mark(app);
    seek_end_of_line(app);
    delete_range(app);
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
