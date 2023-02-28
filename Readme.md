# Oven appliance demo - LVGL + VIT
Oven appliance demo based on the **[RT1170-EVK](https://www.nxp.com/design/development-boards/i-mx-evaluation-and-development-boards/i-mx-rt1170-evaluation-kit:MIMXRT1170-EVK)** board, featuring:

- Voice UI using NXP's [voice intelligent technology (VIT)](https://www.nxp.com/design/software/embedded-software/voice-intelligent-technology:VOICE-INTELLIGENT-TECHNOLOGY?tid=vanvit) and [VoiceSeeker]https://www.nxp.com/design/software/embedded-software/voiceseeker-audio-front-end:VOICESEEKER?tid=vanvoiceseeker).
- Graphics using [LVGL Open-Source library](https://www.nxp.com/design/software/embedded-software/lvgl-open-source-graphics-library:LITTLEVGL-OPEN-SOURCE-GRAPHICS-LIBRARY).

### How to run:

1. Connect USB cable to the board debug port.
2. Flash `evkmimxrt1170_appliance_oven` project.
3. Open a serial terminal.
4. Interact with the GUI via touch or voice commands.

### SW requirements
- MCUXpresso IDE v11.6.0
- RT1170-EVK SDK (SDK_2_12_1_MIMXRT1170-EVK)

### Board tested
- MIMXRT1170-EVKB Rev C1 (3 mic support)

### Voice commands
WakeWord supported : 
    WW_Id  : WW_Name
      1    : HEY OVEN

Voice Commands supported
    Cmd_Id : Cmd_Name
      0    : UNKNOWN
      1    : START
      2    : STOP
      3    : OPEN DOOR
      4    : CLOSE DOOR
      5    : TURN LIGHT ON
      6    : TURN LIGHT OFF
      7    : SET TEMPERATURE TO ONE HUNDRED FIFTY DEGREES
      8    : SET TEMPERATURE TO ONE HUNDRED EIGHTY DEGREES
      9    : SET TEMPERATURE TO TWO HUNDRED TEN DEGREES
      10   : DEFROST MODE
      11   : CHANGE MODE TO THE LEFT
      12   : CHANGE MODE TO THE RIGHT
