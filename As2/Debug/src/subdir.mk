################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/As1.cpp \
../src/BaseApplication.cpp 

OBJS += \
./src/As1.o \
./src/BaseApplication.o 

CPP_DEPS += \
./src/As1.d \
./src/BaseApplication.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/cjgarcia/Desktop/workspace/As1/inc" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


