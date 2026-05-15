# Embedded_Fundamentals
The repository shall contain the code to fundamentals like interrupts, communication protocol drivers etc.

Setup the project so that it only has CMSIS but not the HAL.
1. Download the STM32CubeF4( I am using Nucleo F446RE) (Link: https://www.st.com/en/development-tools/stm32-software-development-tools.html#tools-software)
2. Download latest version available for step 1
3. From the download extract it to the location for workspace
4. Keep the structure
   ..\Knowledge_Update\Fundamentals\stm32cubef4-v1-28-0\STM32Cube_FW_F4_V1.28.0\Drivers\CMSIS
   Keep Device and Include

Error and solution:
Please select first the target STM32F4xx device used in your application (in stm32f4xx.h file)
solution: Uncomment line 80 ie #define STM32F446xx in stm32f4xx.h
