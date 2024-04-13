CSRCS += $(shell find -L $(LVGL_DIR)/ui -name "*.c")

DEPPATH += --dep-path $(LVGL_DIR)/ui
VPATH += :$(LVGL_DIR)/ui
CFLAGS += "-I$(LVGL_DIR)/ui"
