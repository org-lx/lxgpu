workspace "lxgpu"
   architecture "x86_64"
   configurations { "Debug", "Release"}

project "lxgpu"
   kind "SharedLib"
   language "C"
   cdialect "c99"
   targetdir "bin"
   includedirs { "include" }
   files { "src/**.c", "include/**.h" }
   
   -- links {  }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
