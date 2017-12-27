define $(_flavor_)_$(_feat_)_MAKE

$(_flavor_)_PROJ_INC+=$($(_flavor_)_$(_feat_)_dir)

endef

include $(PROJ_MAK_DIR)/epilog.mk
