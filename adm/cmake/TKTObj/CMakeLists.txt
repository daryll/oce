SET(TOOLKIT TKTObj)

SET(TOOLKIT_MODULES
	TObj
)
SET(TOOLKIT_DEPENDS
	TKCDF
	TKernel
	TKMath
	TKLCAF
)

INCLUDE(../BuildToolkit.cmake)

