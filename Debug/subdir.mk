################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Hexapod.cpp \
../Joint.cpp \
../Limb.cpp \
../lib.cpp \
../main.cpp 

OBJS += \
./Hexapod.o \
./Joint.o \
./Limb.o \
./lib.o \
./main.o 

CPP_DEPS += \
./Hexapod.d \
./Joint.d \
./Limb.d \
./lib.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


