file(REMOVE_RECURSE
  "libvdpau_va_gl_static.a"
  "libvdpau_va_gl_static.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/vdpau_va_gl_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
