# NXP Application Code Hub
[<img src="https://mcuxpresso.nxp.com/static/icon/nxp-logo-color.svg" width="100"/>](https://www.nxp.com)

## Full Appliance Demo
This is a Full Appliance Demo with LVGL on MIMXRT1170-EVKB with RK055HDMIPI4M 5.5" LCD panel. This Demo shows three appliances, an Oven, an Aircon and a Hood (each appliance has its own animations and can switch between screens), it also has a central dashboard with the status of all appliances.

#### Boards: MIMXRT1170-EVKB
#### Categories: Graphics
#### Peripherals: DISPLAY
#### Toolchains: MCUXpresso IDE

## Table of Contents
1. [Software](#step1)
2. [Hardware](#step2)
3. [Setup](#step3)
4. [Results](#step4)
5. [FAQs](#step5) 
6. [Support](#step6)
7. [Release Notes](#step7)

## 1. Software<a name="step1"></a>
This code has been implemented using [MCUXpresso IDE](https://nxp.com/mcuxpresso) version 11.7.1. [GUI Guider](https://nxp.com/gui-guider) v1.6.0 was used to import the Lottie files and generate the initial design. LVGL (version 8.3.5) and all other software is included in [MCUXpresso SDK](https://mcuxpresso.nxp.com) - version 2.13.1 was used.


## 2. Hardware<a name="step2"></a>
- Purchase supported board:
    - [MIMXRT1170-EVKB](https://www.nxp.com/part/MIMXRT1170-EVKB#/)
    
- Purchase supported display: 
    - [RK055HDMIPI4MA0](https://www.nxp.com/part/RK055HDMIPI4MA0#/)

- Power Adapter

## 3. Setup<a name="step3"></a>

### 3.1 Step 1
Import the project into MCUXpresso IDE by following the noted sections of the "MCUXpresso IDE - User Guide" found in the documentation section of the [MCUXpresso IDE page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE):
### 3.2 Step 2
Connect the LCD panel to connector J48 of i.MX RT1170-EVKB board.
### 3.3 Step 3
Open the MCUXpresso project
### 3.4 Step 4
Download the built project (in release mode instead debug mode) to the board and run the example.

## 4. Results<a name="step4"></a>

When the demo runs correctly, we will see the following interfaces.

![central_dasboard](doc/images/central_dashboard.jpeg)

![aircon](doc/images/aircon.jpeg)

![oven](doc/images/oven.jpeg)

![rangehood](doc/images/rangehood.jpeg)

## 5. FAQs<a name="step5"></a>

## 6. Support<a name="step6"></a>
If you have any questions or feedback on this code please contact NXP support or post on our community at https://community.nxp.com/. You can find forums here for different aspects of this code example, including GUI Guider, MCUXpresso tools and device families.



#### Project Metadata
<!----- Boards ----->
[![Board badge](https://img.shields.io/badge/Board-MIMXRT1170&ndash;EVK-blue)](https://github.com/search?q=org%3Anxp-appcodehub+MIMXRT1170-EVK+in%3Areadme&type=Repositories)

<!----- Categories ----->
[![Category badge](https://img.shields.io/badge/Category-GRAPHICS-yellowgreen)](https://github.com/search?q=org%3Anxp-appcodehub+graphics+in%3Areadme&type=Repositories)

<!----- Peripherals ----->
[![Peripheral badge](https://img.shields.io/badge/Peripheral-DISPLAY-yellow)](https://github.com/search?q=org%3Anxp-appcodehub+display+in%3Areadme&type=Repositories)

<!----- Toolchains ----->
[![Toolchain badge](https://img.shields.io/badge/Toolchain-MCUXPRESSO%20IDE-orange)](https://github.com/search?q=org%3Anxp-appcodehub+mcux+in%3Areadme&type=Repositories)

Questions regarding the content/correctness of this example can be entered as Issues within this GitHub repository.

>**Warning**: For more general technical questions regarding NXP Microcontrollers and the difference in expected funcionality, enter your questions on the [NXP Community Forum](https://community.nxp.com/)

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/@NXP_Semiconductors)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/nxp-semiconductors)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/nxpsemi/)
[![Follow us on Twitter](https://img.shields.io/badge/Twitter-Follow%20us%20on%20Twitter-white.svg)](https://twitter.com/NXP)

## 7. Release Notes<a name="step7"></a>
| Version | Description / Update                           | Date                        |
|:-------:|------------------------------------------------|----------------------------:|
| 1.0     | Initial release on Application Code HUb        |  August 31<sup>rd</sup> 2023 |

