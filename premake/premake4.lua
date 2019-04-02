solution "../"
   configurations { "Debug", "Release" }

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

   configuration "Debug"
      defines { "DEBUG" }
      flags { "Symbols" }
      links { "sfml-graphics-d" }
      links { "sfml-audio-d" }
      links { "sfml-network-d" }
      links { "sfml-window-d" }
      links { "sfml-system-d" }

    configuration "Release"
      defines { "NDEBUG" }
      flags { "Optimize" }
      links { "sfml-graphics" }
      links { "sfml-audio" }
      links { "sfml-network" }
      links { "sfml-window" }
      links { "sfml-system" }