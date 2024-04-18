////////////////////////////////////////////////////////////////////////////////
// Key Bindings

typedef void (*bindfn)();

#define bind(key, mode, mod, new_cmd) sol_bind_table[KeyCode_##key].table.mode.mod.cmd = new_cmd
#define declbindfn(key) void sol_bindfn_##key()
#define refbindfn(key) sol_bindfn_##key

declbindfn(a) {
    bind(A, normal, none,  insert_char_right);
    bind(A, normal, shift, insert_at_bol);
}

declbindfn(i) {
    bind(I, normal, none,  enter_insert_mode);
    bind(I, normal, shift, insert_at_bol);
}

declbindfn(d) {
    bind(D, normal, none,  enter_delete_mode);
    bind(D, normal, shift, delete_line);
}

declbindfn(h) {
    bind(H, normal, none,  move_left);
    bind(H, normal, shift, seek_beginning_of_line);
    bind(H, del,    none,  backspace_char);
    bind(H, del,    shift, backspace_to_bol);
}

declbindfn(j) {
    bind(J, normal, none,  move_down);
    bind(J, normal, shift, move_down_20);
}

declbindfn(k) {
    bind(K, normal, none,  move_up);
    bind(K, normal, shift, move_up_20);
}

declbindfn(l) {
    bind(L, normal, none,  move_right);
    bind(L, normal, shift, seek_end_of_line);
    bind(L, del,    none,  delete_char);
    bind(L, del,    shift, delete_to_eol);
}

declbindfn(escape) {
    bind(Escape, normal, none, enter_normal_mode);
    bind(Escape, del,    none, enter_normal_mode);
}

bindfn sol_bind_fns[] = {
    refbindfn(a),
    refbindfn(i),
    refbindfn(d),
    refbindfn(h),
    refbindfn(j),
    refbindfn(k),
    refbindfn(l),
    refbindfn(escape),
};
