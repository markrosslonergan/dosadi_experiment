# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.

add_executable (build_uboone_covar build_microboone_covariance.cxx SBNcovar.cxx)
add_executable (two_dim_test two_dim_test.cxx SBNcovar.cxx)

target_link_libraries (build_uboone_covar SBNfitlib tinyxmllib ${ROOT_LIBRARIES})
target_link_libraries (two_dim_test SBNfitlib tinyxmllib ${ROOT_LIBRARIES})

