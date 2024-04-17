// Key Bindings
typedef sol_custom_cmd (*sol_handle_key_cmd)();

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
    return sol_get_cmd_from_mode_cmd_table(&cmd_table);
}
