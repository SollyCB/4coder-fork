/*
4coder_default_include.cpp - Default set of commands and setup used in 4coder.
*/

// TOP

#if !defined(FCODER_DEFAULT_INCLUDE_CPP)
#define FCODER_DEFAULT_INCLUDE_CPP

#if !defined(FCODER_TRANSITION_TO)
#define FCODER_TRANSITION_TO 0
#endif

#include <stdio.h>
#include <stdlib.h>

#include "4coder_base_types.h"
#include "4coder_version.h"
#include "4coder_table.h"
#include "4coder_events.h"
#include "4coder_types.h"
#include "4coder_doc_content_types.h"
#include "4coder_default_colors.h"
#define DYNAMIC_LINK_API
#include "generated/custom_api.h"
#include "4coder_system_types.h"
#define DYNAMIC_LINK_API
#include "generated/system_api.h"
#if !defined(META_PASS)
#include "generated/command_metadata.h"
#endif

#include "4coder_token.h"
#include "generated/lexer_cpp.h"

#include "4coder_variables.h"
#include "4coder_audio.h"
#include "4coder_profile.h"
#include "4coder_async_tasks.h"
#include "4coder_string_match.h"
#include "4coder_helper.h"
#include "4coder_delta_rule.h"
#include "4coder_layout_rule.h"
#include "4coder_code_index.h"
#include "4coder_draw.h"
#include "4coder_insertion.h"
#include "4coder_command_map.h"
#include "4coder_lister_base.h"
#include "4coder_clipboard.h"
#include "4coder_default_framework.h"
#include "4coder_config.h"
#include "4coder_auto_indent.h"
#include "4coder_search.h"
#include "4coder_build_commands.h"
#include "4coder_jumping.h"
#include "4coder_jump_sticky.h"
#include "4coder_jump_lister.h"
#include "4coder_project_commands.h"
#include "4coder_prj_v1.h"
#include "4coder_function_list.h"
#include "4coder_scope_commands.h"
#include "4coder_combined_write_commands.h"
#include "4coder_log_parser.h"
#include "4coder_profile_inspect.h"
#include "4coder_tutorial.h"
#include "4coder_search_list.h"

////////////////////////////////

typedef unsigned int uint;

#define SOL_MAX 0xffffffffffffffff
#define maxif(x) (SOL_MAX + !(x))
#define isnumkey(x) ((x) > 26 && (x) < 37)
#define iskeystroke(x) ((x) == InputEventKind_KeyStroke)

struct sol_custom_cmd {
    void (*cmd)(struct Application_Links *);
};
int sol_do_count = 0; // store the number of times to do key repetition
sol_custom_cmd sol_command = {};

struct sol_key_info {
    Input_Event_Kind kind;
    Key_Code code;
    Input_Modifier_Set mods;
};
sol_key_info sol_last_key;

enum { // these are used to index into below struct
    SOL_MOD_NONE,
    SOL_MOD_SHIFT,
    SOL_MOD_CTRL,
    SOL_MOD_ALT,
    SOL_MOD_CTRL_SHIFT,
    SOL_MOD_ALT_SHIFT,
    SOL_MOD_CTRL_ALT,
    SOL_MOD_CTRL_ALT_SHIFT,
};
struct sol_cmd_table {
    sol_custom_cmd none;
    sol_custom_cmd shift;
    sol_custom_cmd ctrl;
    sol_custom_cmd alt;
    sol_custom_cmd ctrl_shift;
    sol_custom_cmd alt_shift;
    sol_custom_cmd ctrl_alt;
    sol_custom_cmd ctrl_alt_shift;
};

// @CmdTodo
// change mode
// replace mode
enum sol_mode { // these are used to index into below struct
    SOL_MODE_NORMAL,
    SOL_MODE_INSERT,
    SOL_MODE_DELETE,
    SOL_MODE_COUNT,
};
struct sol_mode_cmd_table {
    sol_cmd_table normal;
    sol_cmd_table insert;
    sol_cmd_table del;
};
sol_mode sol_current_mode = SOL_MODE_NORMAL;

inline uint sol_collapse_mods()
{
    bool shift = 0;
    bool ctrl = 0;
    bool alt = 0;
    for(uint i = 0; i < sol_last_key.mods.count; ++i) {
        shift = sol_last_key.mods.mods[i] == KeyCode_Shift || shift;
        ctrl = sol_last_key.mods.mods[i] == KeyCode_Control || ctrl;
        alt = sol_last_key.mods.mods[i] == KeyCode_Alt || alt;
    }
    // @Ugly There is likely a nicer way to do this.
    uint ret = 0;
    ret += (uint)SOL_MOD_SHIFT & maxif(shift && !alt && !ctrl);
    ret += (uint)SOL_MOD_CTRL & maxif(ctrl && !alt && !shift);
    ret += (uint)SOL_MOD_ALT & maxif(alt && !ctrl && !shift);
    ret += (uint)SOL_MOD_CTRL_SHIFT & maxif(ctrl && shift && !alt);
    ret += (uint)SOL_MOD_ALT_SHIFT & maxif(alt && shift && !ctrl);
    ret += (uint)SOL_MOD_CTRL_ALT & maxif(ctrl && alt && !shift);
    ret += (uint)SOL_MOD_CTRL_ALT_SHIFT & maxif(ctrl && alt && shift);
    return ret;
}

typedef sol_custom_cmd (*sol_handle_key_cmd)();

struct sol_4ed_key_mapping {
    uint key_4ed;
    sol_handle_key_cmd cmd;
};
extern sol_4ed_key_mapping sol_4ed_key_maps[KeyCode_COUNT];

static inline sol_custom_cmd sol_update_do_command()
{
    if (sol_last_key.kind == InputEventKind_KeyStroke &&
        sol_4ed_key_maps[sol_last_key.code].cmd)
    {
        return (*sol_4ed_key_maps[sol_last_key.code].cmd)();
    }
    return {};
}

#include "4coder_base_types.cpp"
#include "4coder_stringf.cpp"
#include "4coder_app_links_allocator.cpp"
#include "4coder_system_allocator.cpp"

#include "4coder_file.cpp"

#define DYNAMIC_LINK_API
#include "generated/custom_api.cpp"
#define DYNAMIC_LINK_API
#include "generated/system_api.cpp"
#include "4coder_system_helpers.cpp"
#include "4coder_layout.cpp"
#include "4coder_profile.cpp"
#include "4coder_profile_static_enable.cpp"
#include "4coder_events.cpp"
#include "4coder_custom.cpp"
#include "4coder_log.cpp"
#include "4coder_hash_functions.cpp"
#include "4coder_table.cpp"
#include "4coder_codepoint_map.cpp"
#include "4coder_async_tasks.cpp"
#include "4coder_string_match.cpp"
#include "4coder_buffer_seek_constructors.cpp"
#include "4coder_token.cpp"
#include "4coder_command_map.cpp"

#include "generated/lexer_cpp.cpp"

#include "4coder_default_map.cpp"
#include "4coder_mac_map.cpp"

#include "4coder_default_framework_variables.cpp"
#include "4coder_default_colors.cpp"
#include "4coder_helper.cpp"
#include "4coder_delta_rule.cpp"
#include "4coder_layout_rule.cpp"
#include "4coder_code_index.cpp"
#include "4coder_fancy.cpp"
#include "4coder_draw.cpp"
#include "4coder_font_helper.cpp"
#include "4coder_config.cpp"
#include "4coder_dynamic_bindings.cpp"
#include "4coder_default_framework.cpp"
#include "4coder_clipboard.cpp"
#include "4coder_lister_base.cpp"
#include "4coder_base_commands.cpp"
#include "4coder_insertion.cpp"
#include "4coder_eol.cpp"
#include "4coder_lists.cpp"
#include "4coder_auto_indent.cpp"
#include "4coder_search.cpp"
#include "4coder_jumping.cpp"
#include "4coder_jump_sticky.cpp"
#include "4coder_jump_lister.cpp"
#include "4coder_code_index_listers.cpp"
#include "4coder_log_parser.cpp"
#include "4coder_keyboard_macro.cpp"
#include "4coder_cli_command.cpp"
#include "4coder_build_commands.cpp"
#include "4coder_project_commands.cpp"
#include "4coder_prj_v1.cpp"
#include "4coder_function_list.cpp"
#include "4coder_scope_commands.cpp"
#include "4coder_combined_write_commands.cpp"
#include "4coder_miblo_numbers.cpp"
#include "4coder_profile_inspect.cpp"
#include "4coder_tutorial.cpp"
#include "4coder_doc_content_types.cpp"
#include "4coder_doc_commands.cpp"
#include "4coder_docs.cpp"
#include "4coder_variables.cpp"
#include "4coder_audio.cpp"
#include "4coder_search_list.cpp"

#include "4coder_examples.cpp"

#include "sol_commands.cpp"
#include "sol_bindings.cpp"
#include "sol_bind_tables.cpp"

#include "4coder_default_hooks.cpp"

#endif

// BOTTOM

