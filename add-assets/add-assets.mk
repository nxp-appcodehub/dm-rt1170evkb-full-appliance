## SPDX-License-Identifier: MIT
## Copyright 2020 NXP

GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/add-assets/*.c))

DEPPATH += --dep-path $(PRJ_DIR)/add-assets
VPATH += :$(PRJ_DIR)/add-assets

CFLAGS += "-I$(PRJ_DIR)/add-assets"
