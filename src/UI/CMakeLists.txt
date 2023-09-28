SET(SOURCES screens/ui_Index.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    fonts/ui_font_kanit60.c)

add_library(ui ${SOURCES})
