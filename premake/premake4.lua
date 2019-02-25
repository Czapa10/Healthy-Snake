solution "../"
   configurations { "Debug", "Release" }

project "Healthy-Snake"
   location "../"
   kind "ConsoleApp"
   language "C++"
   targetdir "../bin/Debug"
   objdir "../obj"

   files {
      "../src/**.h",
      "../src/**.hpp",
      "../src/**.cpp" 
   }

   configuration "Debug"
      defines { "DEBUG" }
      flags { "Symbols" }

    configuration "Release"
      defines { "NDEBUG" }
      flags { "Optimize" }
