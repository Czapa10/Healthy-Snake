workspace "../"
   configurations { "Debug", "Release" }
   architecture "x86"

project "Healthy-Snake"
   location "../"
   kind "ConsoleApp"
   language "C++"
   targetdir "../bin/Debug"
   objdir "../obj"
   includedirs{ "../src" , "../vendor/SFML/include" }
   libdirs{ "../vendor/SFML/lib" }

   files {
      "../src/**.hpp",
      "../src/**.cpp",
      "../src/**.inl", 
      "../src/**.rc" 
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      links { "sfml-graphics-d" }
      links { "sfml-audio-d" }
      links { "sfml-network-d" }
      links { "sfml-window-d" }
      links { "sfml-system-d" }

   filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"
      links { "sfml-graphics" }
      links { "sfml-audio" }
      links { "sfml-network" }
      links { "sfml-window" }
      links { "sfml-system" }