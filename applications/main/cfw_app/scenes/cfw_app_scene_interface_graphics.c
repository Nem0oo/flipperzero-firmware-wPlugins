// #include "../cfw_app.h"

// enum VarItemListIndex {
    // VarItemListIndexAssetPack,
    // VarItemListIndexAnimSpeed,
    // VarItemListIndexCycleAnims,
    // VarItemListIndexUnlockAnims,
// };

// void cfw_app_scene_interface_graphics_var_item_list_callback(void* context, uint32_t index) {
    // CfwApp* app = context;
    // view_dispatcher_send_custom_event(app->view_dispatcher, index);
// }

// static void cfw_app_scene_interface_graphics_asset_pack_changed(VariableItem* item) {
    // CfwApp* app = variable_item_get_context(item);
    // uint8_t index = variable_item_get_current_value_index(item);
    // variable_item_set_current_value_text(
        // item, index == 0 ? "SFW" : *CharList_get(app->asset_pack_names, index - 1));
    // strlcpy(
        // CFW_SETTINGS()->asset_pack,
        // index == 0 ? "" : *CharList_get(app->asset_pack_names, index - 1),
        // CFW_ASSETS_PACK_NAME_LEN);
    // app->asset_pack_index = index;
    // app->save_settings = true;
    // app->require_reboot = true;
// }

// const char* const anim_speed_names[] =
    // {"25%", "50%", "75%", "100%", "125%", "150%", "175%", "200%", "225%", "250%", "275%", "300%"};
// const int32_t anim_speed_values[COUNT_OF(anim_speed_names)] =
    // {25, 50, 75, 100, 125, 150, 175, 200, 225, 250, 275, 300};
// static void cfw_app_scene_interface_graphics_anim_speed_changed(VariableItem* item) {
    // CfwApp* app = variable_item_get_context(item);
    // uint8_t index = variable_item_get_current_value_index(item);
    // variable_item_set_current_value_text(item, anim_speed_names[index]);
    // CFW_SETTINGS()->anim_speed = anim_speed_values[index];
    // app->save_settings = true;
// }

// const char* const cycle_anims_names[] = {
    // "OFF",
    // "Meta.txt",
    // "30 S",
    // "1 M",
    // "5 M",
    // "10 M",
    // "15 M",
    // "30 M",
    // "1 H",
    // "2 H",
    // "6 H",
    // "12 H",
    // "24 H"};
// const int32_t cycle_anims_values[COUNT_OF(cycle_anims_names)] =
    // {-1, 0, 30, 60, 300, 600, 900, 1800, 3600, 7200, 21600, 43200, 86400};
// static void cfw_app_scene_interface_graphics_cycle_anims_changed(VariableItem* item) {
    // CfwApp* app = variable_item_get_context(item);
    // uint8_t index = variable_item_get_current_value_index(item);
    // variable_item_set_current_value_text(item, cycle_anims_names[index]);
    // CFW_SETTINGS()->cycle_anims = cycle_anims_values[index];
    // app->save_settings = true;
// }

// static void cfw_app_scene_interface_graphics_unlock_anims_changed(VariableItem* item) {
    // CfwApp* app = variable_item_get_context(item);
    // bool value = variable_item_get_current_value_index(item);
    // variable_item_set_current_value_text(item, value ? "ON" : "OFF");
    // CFW_SETTINGS()->unlock_anims = value;
    // app->save_settings = true;
// }

// static void cfw_app_scene_interface_graphics_fallback_anim_changed(VariableItem* item) {
    // CfwApp* app = variable_item_get_context(item);
    // bool value = variable_item_get_current_value_index(item);
    // variable_item_set_current_value_text(item, value ? "ON" : "OFF");
    // CFW_SETTINGS()->fallback_anim = value;
    // app->save_settings = true;
// }

// void cfw_app_scene_interface_graphics_on_enter(void* context) {
    // CfwApp* app = context;
    // CfwSettings* cfw_settings = CFW_SETTINGS();
    // VariableItemList* var_item_list = app->var_item_list;
    // VariableItem* item;
    // uint8_t value_index;

    // item = variable_item_list_add(
        // var_item_list,
        // "Asset Pack",
        // CharList_size(app->asset_pack_names) + 1,
        // cfw_app_scene_interface_graphics_asset_pack_changed,
        // app);
    // variable_item_set_current_value_index(item, app->asset_pack_index);
    // variable_item_set_current_value_text(
        // item,
        // app->asset_pack_index == 0 ?
            // "SFW" :
            // *CharList_get(app->asset_pack_names, app->asset_pack_index - 1));

    // item = variable_item_list_add(
        // var_item_list,
        // "Anim Speed",
        // COUNT_OF(anim_speed_names),
        // cfw_app_scene_interface_graphics_anim_speed_changed,
        // app);
    // value_index = value_index_int32(
        // cfw_settings->anim_speed, anim_speed_values, COUNT_OF(anim_speed_names));
    // variable_item_set_current_value_index(item, value_index);
    // variable_item_set_current_value_text(item, anim_speed_names[value_index]);

    // item = variable_item_list_add(
        // var_item_list,
        // "Cycle Anims",
        // COUNT_OF(cycle_anims_names),
        // cfw_app_scene_interface_graphics_cycle_anims_changed,
        // app);
    // value_index = value_index_int32(
        // cfw_settings->cycle_anims, cycle_anims_values, COUNT_OF(cycle_anims_names));
    // variable_item_set_current_value_index(item, value_index);
    // variable_item_set_current_value_text(item, cycle_anims_names[value_index]);

    // item = variable_item_list_add(
        // var_item_list,
        // "Unlock Anims",
        // 2,
        // cfw_app_scene_interface_graphics_unlock_anims_changed,
        // app);
    // variable_item_set_current_value_index(item, cfw_settings->unlock_anims);
    // variable_item_set_current_value_text(item, cfw_settings->unlock_anims ? "ON" : "OFF");

    // item = variable_item_list_add(
        // var_item_list,
        // "Fallback Anim",
        // 2,
        // cfw_app_scene_interface_graphics_fallback_anim_changed,
        // app);
    // variable_item_set_current_value_index(item, cfw_settings->fallback_anim);
    // variable_item_set_current_value_text(item, cfw_settings->fallback_anim ? "ON" : "OFF");

    // variable_item_list_set_enter_callback(
        // var_item_list, cfw_app_scene_interface_graphics_var_item_list_callback, app);

    // variable_item_list_set_selected_item(
        // var_item_list,
        // scene_manager_get_scene_state(app->scene_manager, CfwAppSceneInterfaceGraphics));

    // view_dispatcher_switch_to_view(app->view_dispatcher, CfwAppViewVarItemList);
// }

// bool cfw_app_scene_interface_graphics_on_event(void* context, SceneManagerEvent event) {
    // CfwApp* app = context;
    // bool consumed = false;

    // if(event.type == SceneManagerEventTypeCustom) {
        // scene_manager_set_scene_state(
            // app->scene_manager, CfwAppSceneInterfaceGraphics, event.event);
        // consumed = true;
        // switch(event.event) {
        // default:
            // break;
        // }
    // }

    // return consumed;
// }

// void cfw_app_scene_interface_graphics_on_exit(void* context) {
    // CfwApp* app = context;
    // variable_item_list_reset(app->var_item_list);
// }
