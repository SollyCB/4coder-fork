/*
4coder_default_bidings.cpp - Supplies the default bindings used for default 4coder behavior.
*/

// TOP

#if !defined(FCODER_DEFAULT_BINDINGS_CPP)
#define FCODER_DEFAULT_BINDINGS_CPP

#include "4coder_default_include.cpp"

static inline void sol_update_repeat_info()
{
    uint b = maxif(iskeystroke(sol_last_key.kind) && isnumkey(sol_last_key.code));
    sol_do_count *= 10 & b;
    sol_do_count += (sol_last_key.kind - 27) & b;
}

// NOTE(allen): Users can declare their own managed IDs here.

#if !defined(META_PASS)
#include "generated/managed_id_metadata.cpp"
#endif

void
custom_layer_init(Application_Links *app){
    Thread_Context *tctx = get_thread_context(app);
    
    default_framework_init(app);
    
    set_all_default_hooks(app);

    mapping_init(tctx, &framework_mapping);

    String_ID global_map_id = vars_save_string_lit("keys_global");
    String_ID file_map_id = vars_save_string_lit("keys_file");
    String_ID code_map_id = vars_save_string_lit("keys_code");

    // Some binding setup calls are disabled in fn essential, it is not default.
	setup_essential_mapping(&framework_mapping, global_map_id, file_map_id, code_map_id);

    // @Bindings:
    //     rewrite 4coder_lister_base.cpp:run_lister() to add key bindings for
    //     scrolling the view (<c-n> and <c-p>), I think you can only use arrow
    //     keys right now?
    //
    //     delete to char: set mark, search, set mark, delete range.
    //     scroll screen by some amount (go up 20)

    MappingScope();
    SelectMapping(&framework_mapping);

    SelectMap(global_map_id);
    BindCore(default_startup, CoreCode_Startup);
    BindCore(default_try_exit, CoreCode_TryExit);

    Bind(move_left, KeyCode_Left);
    Bind(move_right, KeyCode_Right);
    Bind(move_up, KeyCode_Up);
    Bind(move_down, KeyCode_Down);

    // @Todo Add to shared.
    //    KeyCode_PageUp = 62,
    //    KeyCode_PageDown = 63,
    //    KeyCode_Home = 60,
    //    KeyCode_End = 61,

    // This is to make sure that the default bindings on the buffers will be mapid_normal.
    SelectMap(file_map_id);
    ParentMap(global_map_id);

    SelectMap(code_map_id);
    ParentMap(file_map_id);
}

#endif //FCODER_DEFAULT_BINDINGS

// BOTTOM

