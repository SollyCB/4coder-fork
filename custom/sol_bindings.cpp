#define HANDLE_KEY_RETURN() \
    sol_cmd_table *mode = (sol_cmd_table*)&cmd_table + sol_current_mode; \
    return *((sol_custom_cmd*)mode + sol_collapse_mods())

// Key Bindings
sol_custom_cmd sol_handle_key_a()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = insert_char_right,
            .shift = insert_at_eol,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_i()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = enter_insert_mode,
            .shift = insert_at_bol,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_d()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = enter_delete_mode,
            .shift = delete_line,
        },
        .del = {
            .none = nil,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_h()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = move_left,
            .shift = seek_beginning_of_line,
        },
        .del = {
            .none = backspace_char,
            .shift = backspace_to_bol,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_j()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = move_down,
            .shift = move_down_20,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_k()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = move_up,
            .shift = move_up_20,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_l()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = move_right,
            .shift = seek_end_of_line,
        },
    };
    HANDLE_KEY_RETURN();
}

sol_custom_cmd sol_handle_key_esc()
{
    sol_mode_cmd_table cmd_table {
        .insert = {
            .none  = enter_normal_mode,
        },
        .del = {
            .none  = enter_normal_mode,
        },
    };
    HANDLE_KEY_RETURN();
}
