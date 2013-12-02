################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Hexapod.cpp \
../Joint.cpp \
../Leg.cpp \
../Limb.cpp \
../Motion.cpp \
../Phase.cpp \
../Servo.cpp \
../main.cpp 

OBJS += \
./Hexapod.o \
./Joint.o \
./Leg.o \
./Limb.o \
./Motion.o \
./Phase.o \
./Servo.o \
./main.o 

CPP_DEPS += \
./Hexapod.d \
./Joint.d \
./Leg.d \
./Limb.d \
./Motion.d \
./Phase.d \
./Servo.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


