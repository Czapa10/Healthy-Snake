workspace "../"
   configurations { "Debug", "Release" }
   architecture "x86"

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

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"