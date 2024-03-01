################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP.c \
../CLCD_Program.c \
../DIO_program.c \
../SSD_Program.c \
../SW_Program.c \
../main.c 

OBJS += \
./APP.o \
./CLCD_Program.o \
./DIO_program.o \
./SSD_Program.o \
./SW_Program.o \
./main.o 

C_DEPS += \
./APP.d \
./CLCD_Program.d \
./DIO_program.d \
./SSD_Program.d \
./SW_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


