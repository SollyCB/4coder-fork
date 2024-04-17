CUSTOM_COMMAND_SIG(sol_do_command)
{
    View_ID view = get_active_view(app, Access_ReadWriteVisible);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadWriteVisible);

    History_Group group = history_group_begin(app, buffer);

    // I think that this is an unnecessary check because of
    // checks in the calling code.
    if (!sol_command.cmd && sol_do_count) {
        sol_do_count = 0;
        history_group_end(group);
        return;
    }

    for(int i = 0; i < sol_do_count; ++i)
        sol_command.cmd(app);

    sol_do_count = 0;
    sol_command = {};

    history_group_end(group);
}

CUSTOM_COMMAND_SIG(enter_insert_mode)
{
    sol_current_mode = SOL_MODE_INSERT;
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

