#=======================================================================================#
# template_vector.mk
#=======================================================================================#
#  Created on: Oct 3, 2015
#      Author: puch
#=======================================================================================#

#=======================================================================================#
# DEFINE PACKAGE RULE
#=======================================================================================#
define $(_flavor_)_$(_feat_)_MAKE
#=======================================================================================#
# OBJECTS DIRECTORY
# e.g: 
#     $(_flavor_)_$(_feat_)_src_dir=pk_module_N_code/_src
#     or
#     $(_flavor_)_$(_feat_)_src_dir=_src
#=======================================================================================#
$(_flavor_)_PROJ_INC+=$($(_flavor_)_$(_feat_)_dir:%=%/template_vector)
#=======================================================================================#
# END PACKAGE RULE
#=======================================================================================#
endef
#=======================================================================================#
# LOCAL VARIABLES
#=======================================================================================#

#=======================================================================================#
# LOCAL DEFINES 
#=======================================================================================#

#=======================================================================================#
# LOCAL DEFINE EXPANSIONS
#=======================================================================================#

#=======================================================================================#
# LOCAL RULES EXPANSIONS
#=======================================================================================#
$(eval $(call Verbose,$(call $(_flavor_)_$(_feat_)_MAKE)))
#=======================================================================================#
# INCLUDE PK PROJECT UTILITY
#=======================================================================================#

#=======================================================================================#
# template_vector.mk
#=======================================================================================#
# Changes Log
#
#
#=======================================================================================#
