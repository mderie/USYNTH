# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# build with "V=1" for verbose builds
ifeq ($(V), 1)
V_AT =
else
V_AT = @
endif

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DDEBUG=1 -D_DEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama webkit2gtk-4.0 gtk+-x11-3.0) -pthread -I../../JuceLibraryCode -I../../../../library/JUCE/modules $(CPPFLAGS)
  JUCE_CPPFLAGS_CONSOLEAPP := -DJucePlugin_Build_VST=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_Standalone=0
  JUCE_TARGET_CONSOLEAPP := usynth

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0 $(CFLAGS)
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama webkit2gtk-4.0 gtk+-x11-3.0) -lGL -ldl -lpthread -lrt -lncurses $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DNDEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama webkit2gtk-4.0 gtk+-x11-3.0) -pthread -I../../JuceLibraryCode -I../../../../library/JUCE/modules $(CPPFLAGS)
  JUCE_CPPFLAGS_CONSOLEAPP := -DJucePlugin_Build_VST=0 -DJucePlugin_Build_VST3=0 -DJucePlugin_Build_AU=0 -DJucePlugin_Build_AUv3=0 -DJucePlugin_Build_RTAS=0 -DJucePlugin_Build_AAX=0 -DJucePlugin_Build_Standalone=0
  JUCE_TARGET_CONSOLEAPP := usynth

  JUCE_CFLAGS += $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3 $(CFLAGS)
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11 $(CXXFLAGS)
  JUCE_LDFLAGS += $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama webkit2gtk-4.0 gtk+-x11-3.0) -lGL -ldl -lpthread -lrt -lncurses $(LDFLAGS)

  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

OBJECTS_CONSOLEAPP := \
  $(JUCE_OBJDIR)/AudioBuffers_a4803d86.o \
  $(JUCE_OBJDIR)/AudioDevices_85a19130.o \
  $(JUCE_OBJDIR)/AudioModules_9a60a6da.o \
  $(JUCE_OBJDIR)/CommonStuffs_6f412653.o \
  $(JUCE_OBJDIR)/ConfigurationFiles_bf7b082a.o \
  $(JUCE_OBJDIR)/KeywordCommands_36ff4772.o \
  $(JUCE_OBJDIR)/LaunchpadPrimitives_508480ed.o \
  $(JUCE_OBJDIR)/MidiCommands_31a84d2.o \
  $(JUCE_OBJDIR)/MidiNotes_7db48d81.o \
  $(JUCE_OBJDIR)/ThreadedTimers_4d409360.o \
  $(JUCE_OBJDIR)/UIElements_dcf55794.o \
  $(JUCE_OBJDIR)/Main_90ebc5c2.o \
  $(JUCE_OBJDIR)/include_juce_audio_basics_8a4e984a.o \
  $(JUCE_OBJDIR)/include_juce_audio_devices_63111d02.o \
  $(JUCE_OBJDIR)/include_juce_audio_formats_15f82001.o \
  $(JUCE_OBJDIR)/include_juce_audio_processors_10c03666.o \
  $(JUCE_OBJDIR)/include_juce_core_f26d17db.o \
  $(JUCE_OBJDIR)/include_juce_cryptography_8cb807a8.o \
  $(JUCE_OBJDIR)/include_juce_data_structures_7471b1e3.o \
  $(JUCE_OBJDIR)/include_juce_events_fd7d695.o \
  $(JUCE_OBJDIR)/include_juce_graphics_f817e147.o \
  $(JUCE_OBJDIR)/include_juce_gui_basics_e3f79785.o \
  $(JUCE_OBJDIR)/include_juce_gui_extra_6dee1c1a.o \
  $(JUCE_OBJDIR)/include_juce_opengl_a8a032b.o \
  $(JUCE_OBJDIR)/include_juce_video_be78589.o \

.PHONY: clean all

all : $(JUCE_OUTDIR)/$(JUCE_TARGET_CONSOLEAPP)

$(JUCE_OUTDIR)/$(JUCE_TARGET_CONSOLEAPP) : check-pkg-config $(OBJECTS_CONSOLEAPP) $(RESOURCES)
	@echo Linking "usynth - ConsoleApp"
	-$(V_AT)mkdir -p $(JUCE_BINDIR)
	-$(V_AT)mkdir -p $(JUCE_LIBDIR)
	-$(V_AT)mkdir -p $(JUCE_OUTDIR)
	$(V_AT)$(CXX) -o $(JUCE_OUTDIR)/$(JUCE_TARGET_CONSOLEAPP) $(OBJECTS_CONSOLEAPP) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)

$(JUCE_OBJDIR)/AudioBuffers_a4803d86.o: ../../Source/AudioBuffers.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AudioBuffers.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioDevices_85a19130.o: ../../Source/AudioDevices.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AudioDevices.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioModules_9a60a6da.o: ../../Source/AudioModules.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AudioModules.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CommonStuffs_6f412653.o: ../../Source/CommonStuffs.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling CommonStuffs.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ConfigurationFiles_bf7b082a.o: ../../Source/ConfigurationFiles.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling ConfigurationFiles.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/KeywordCommands_36ff4772.o: ../../Source/KeywordCommands.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling KeywordCommands.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/LaunchpadPrimitives_508480ed.o: ../../Source/LaunchpadPrimitives.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling LaunchpadPrimitives.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiCommands_31a84d2.o: ../../Source/MidiCommands.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MidiCommands.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiNotes_7db48d81.o: ../../Source/MidiNotes.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MidiNotes.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ThreadedTimers_4d409360.o: ../../Source/ThreadedTimers.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling ThreadedTimers.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/UIElements_dcf55794.o: ../../Source/UIElements.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling UIElements.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Main.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_basics_8a4e984a.o: ../../JuceLibraryCode/include_juce_audio_basics.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_basics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_devices_63111d02.o: ../../JuceLibraryCode/include_juce_audio_devices.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_devices.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_formats_15f82001.o: ../../JuceLibraryCode/include_juce_audio_formats.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_formats.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_audio_processors_10c03666.o: ../../JuceLibraryCode/include_juce_audio_processors.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_audio_processors.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_core_f26d17db.o: ../../JuceLibraryCode/include_juce_core.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_core.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_cryptography_8cb807a8.o: ../../JuceLibraryCode/include_juce_cryptography.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_cryptography.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_data_structures_7471b1e3.o: ../../JuceLibraryCode/include_juce_data_structures.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_data_structures.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_events_fd7d695.o: ../../JuceLibraryCode/include_juce_events.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_events.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_graphics_f817e147.o: ../../JuceLibraryCode/include_juce_graphics.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_graphics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_basics_e3f79785.o: ../../JuceLibraryCode/include_juce_gui_basics.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_basics.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_gui_extra_6dee1c1a.o: ../../JuceLibraryCode/include_juce_gui_extra.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_gui_extra.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_opengl_a8a032b.o: ../../JuceLibraryCode/include_juce_opengl.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_opengl.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

$(JUCE_OBJDIR)/include_juce_video_be78589.o: ../../JuceLibraryCode/include_juce_video.cpp
	-$(V_AT)mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling include_juce_video.cpp"
	$(V_AT)$(CXX) $(JUCE_CXXFLAGS) $(JUCE_CPPFLAGS_CONSOLEAPP) $(JUCE_CFLAGS_CONSOLEAPP) -o "$@" -c "$<"

check-pkg-config:
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa freetype2 libcurl x11 xext xinerama

clean:
	@echo Cleaning usynth
	$(V_AT)$(CLEANCMD)

strip:
	@echo Stripping usynth
	-$(V_AT)$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

-include $(OBJECTS_CONSOLEAPP:%.o=%.d)
