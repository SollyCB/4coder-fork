// Key Bindings
sol_custom_cmd sol_handle_key_a()
{
    sol_mode_cmd_table cmd_table {
        .normal = {
            .none  = insert_char_right,
            .shift = insert_at_eol,
        },
        .insert = {
            .none  = write_text_and_auto_indent,
            .shift = write_text_and_auto_indent,
        },
    };
    sol_cmd_table *mode = (sol_cmd_table*)&cmd_table + sol_current_mode;
    return *((sol_custom_cmd*)mode + sol_collapse_mods());
}
