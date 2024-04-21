////////////////////////////////////////////////////////////////////////////////
// Key Bindings

// Binding Todo List:
// arrow keys in insert
// open_line
// delete surrounding pair

typedef void (*bindfn)();

#define bind(key, mode, mod, new_cmd) sol_bind_table[KeyCode_##key].mode.mod.cmd = new_cmd
#define declbindfn(key) void sol_bindfn_##key()
#define refbindfn(key) sol_bindfn_##key

declbindfn(a) {
    bind(A, normal, none,  insert_char_right);
    bind(A, normal, shift, insert_at_eol);
}

declbindfn(i) {
    bind(I, normal, none,  enter_insert_mode);
    bind(I, normal, shift, insert_at_bol);
    
    bind(I, normal, ctrl,       interactive_switch_buffer);
    bind(I, normal, ctrl_shift, interactive_kill_buffer);
}

declbindfn(d) {
    bind(D, normal, none,  enter_delete_mode);
    bind(D, normal, shift, delete_line);
    bind(D, normal, ctrl,  delete_range);
    bind(D, del,    none,  enter_normal_mode);
}

declbindfn(c) {
    bind(C, normal, none,  enter_change_mode);
    bind(C, normal, shift, change_line);
    bind(C, change, none,  enter_normal_mode);
}

declbindfn(h) {
    bind(H, normal, none,  move_left);
    bind(H, normal, shift, seek_beginning_of_line);
    bind(H, del,    none,  backspace_to_bol);
    bind(H, change, none,  change_to_bol);
}

declbindfn(j) {
    bind(J, normal, none,  move_down);
    bind(J, normal, shift, move_down_20);
    bind(J, normal, ctrl,  move_line_down);
}

declbindfn(k) {
    bind(K, normal, none,  move_up);
    bind(K, normal, shift, move_up_20);
    bind(K, normal, ctrl,  move_line_up);
}

declbindfn(l) {
    bind(L, normal, none,  move_right);
    bind(L, normal, shift, seek_end_of_line);
    bind(L, del,    none,  delete_to_eol);
    bind(L, change, none,  change_to_eol);
}

declbindfn(t) {
    bind(T, normal, none,  move_right_token_boundary);
    bind(T, normal, shift, move_left_token_boundary);
    bind(T, normal, ctrl,  search_identifier);
    bind(T, normal, alt,   reverse_search_identifier);
    bind(T, del,    none,  delete_to_token_right);
    bind(T, del,    shift, delete_to_token_left);
    bind(T, change, none,  change_to_token_right);
    bind(T, change, shift, change_to_token_left);
    
    bind(T, normal, ctrl_shift, list_all_locations_of_identifier);
    bind(T, normal, alt_shift,  list_all_locations_of_identifier);
    
    bind(T, normal, ctrl_alt_shift, theme_lister);
}

declbindfn(f) {
    bind(F, normal, ctrl, toggle_filebar);
    
    bind(F, normal, ctrl_shift, list_all_functions_all_buffers);
    bind(F, normal, alt_shift,  list_all_functions_current_buffer);
}

declbindfn(w) {
    bind(W, normal, none,  seek_beginning_of_next_word);
    bind(W, normal, shift, seek_beginning_of_next_whitespace);
    bind(W, del,    shift, delete_to_beginning_of_next_whitespace);
    bind(W, change, shift, change_to_beginning_of_next_whitespace);
    bind(W, del,    none,  delete_to_beginning_of_next_word);
    bind(W, change, none,  change_to_beginning_of_next_word);
}

declbindfn(b) {
    bind(B, normal, none,  seek_beginning_of_last_word);
    bind(B, normal, shift, seek_beginning_of_last_whitespace);
    bind(B, normal, ctrl,  build_in_build_panel);
    
    bind(B, del,    shift, delete_to_beginning_of_last_whitespace);
    bind(B, change, shift, change_to_beginning_of_last_whitespace);
    bind(B, del,    none,  delete_to_beginning_of_last_word);
    bind(B, change, none,  change_to_beginning_of_last_word);
}

declbindfn(o) {
    bind(O, normal, none,  open_line_below); // open_line_<above|below> currently broken
    bind(O, normal, shift, open_line_above);
    bind(O, normal, ctrl,  interactive_open_or_new);
    bind(O, normal, alt,   open_in_other);
}

declbindfn(y) {
    bind(Y, normal, none,  copy);
    bind(Y, normal, shift, duplicate_line);
}

declbindfn(p) {
    bind(P, normal, none, paste);
    bind(P, normal, ctrl, goto_prev_jump);
}

declbindfn(x) {
    bind(X, normal, none,  delete_char);
    bind(X, normal, ctrl,  cut);
    bind(X, normal, shift, duplicate_line);
}

declbindfn(z) {
    bind(Z, normal, none, center_view);
}

declbindfn(q) {
    bind(Q, normal, none,  keyboard_macro_toggle_recording);
    bind(Q, normal, shift, keyboard_macro_replay);
}

declbindfn(u) {
    bind(U, normal, none, undo);
}

declbindfn(r) {
    bind(R, normal, none, replace_in_range);
}

declbindfn(s) {
    bind(S, normal, ctrl, save);
}

declbindfn(m) {
    bind(M, normal, none, set_mark);
    bind(M, normal, ctrl, cursor_mark_swap);
}

declbindfn(n) {
    bind(N, normal, ctrl, goto_next_jump);
}

declbindfn(backspace) {
    bind(Backspace, insert, none, backspace_char);
}

declbindfn(enter) {
    bind(Return, normal, none, textinput);
    bind(Return, normal, none, goto_jump_at_cursor);
}

declbindfn(del) {
    bind(Delete, insert, none, delete_char);
}

declbindfn(escape) {
    bind(Escape, insert, none, enter_normal_mode);
    bind(Escape, del,    none, enter_normal_mode);
    bind(Escape, change, none, enter_normal_mode);
}

declbindfn(semicolon) {
    bind(Semicolon, normal, shift, command_lister);
}

declbindfn(slash) {
    bind(ForwardSlash, normal, none,  search);
    bind(ForwardSlash, normal, shift, reverse_search);
    bind(ForwardSlash, normal, ctrl,  list_all_substring_locations);
}

declbindfn(comma) {
    bind(Comma, normal, none,  toggle_panel);
    bind(Comma, normal, shift, swap_panels);
    bind(Comma, normal, alt,   close_panel);
}

declbindfn(fullstop) {
    bind(Period, normal, none,  change_to_build_panel);
    bind(Period, normal, shift, build_in_build_panel);
    bind(Period, normal, alt,   close_build_panel);
}

declbindfn(openbracket) {
    bind(LeftBracket, normal, none,       move_up_to_blank_line);
    bind(LeftBracket, normal, shift,      select_prev_scope_absolute);
    bind(LeftBracket, normal, ctrl_shift, select_surrounding_scope);
    bind(LeftBracket, del,    shift,      del_delete_current_scope);
    bind(LeftBracket, change, shift,      change_current_scope);
}

declbindfn(closebracket) {
    bind(RightBracket, normal, none,  move_down_to_blank_line);
    bind(RightBracket, normal, shift, select_next_scope_absolute);
}

declbindfn(pagedown) {
    bind(PageDown, normal, none,  page_down);
    bind(PageDown, normal, shift, goto_end_of_file);
    bind(PageDown, insert, none,  page_down);
    bind(PageDown, insert, shift, goto_end_of_file);
}

declbindfn(pageup) {
    bind(PageUp, normal, none,  page_up);
    bind(PageUp, normal, shift, goto_beginning_of_file);
    bind(PageUp, insert, none,  page_up);
    bind(PageUp, insert, shift, goto_beginning_of_file);
}

declbindfn(eight) {
    bind(8, normal, shift, list_all_locations_of_identifier);
}

bindfn sol_bind_fns[] = {
    refbindfn(a),
    refbindfn(i),
    refbindfn(d),
    refbindfn(c),
    refbindfn(h),
    refbindfn(j),
    refbindfn(k),
    refbindfn(l),
    refbindfn(w),
    refbindfn(b),
    refbindfn(o),
    refbindfn(y),
    refbindfn(p),
    refbindfn(q),
    refbindfn(u),
    refbindfn(r),
    refbindfn(s),
    refbindfn(t),
    refbindfn(f),
    refbindfn(m),
    refbindfn(n),
    refbindfn(x),
    refbindfn(z),
    refbindfn(backspace),
    refbindfn(enter),
    refbindfn(del),
    refbindfn(escape),
    refbindfn(semicolon),
    refbindfn(slash),
    refbindfn(comma),
    refbindfn(fullstop),
    refbindfn(openbracket),
    refbindfn(closebracket),
    refbindfn(pagedown),
    refbindfn(pageup),
    refbindfn(eight),
};
