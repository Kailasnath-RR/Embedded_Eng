#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../AdctoPwm.X/mcc_generated_files/clock.c ../AdctoPwm.X/mcc_generated_files/interrupt_manager.c ../AdctoPwm.X/mcc_generated_files/mcc.c ../AdctoPwm.X/mcc_generated_files/pin_manager.c ../AdctoPwm.X/mcc_generated_files/pwm.c ../AdctoPwm.X/mcc_generated_files/reset.c ../AdctoPwm.X/mcc_generated_files/system.c ../AdctoPwm.X/mcc_generated_files/traps.c main.c adc.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/728126550/clock.o ${OBJECTDIR}/_ext/728126550/interrupt_manager.o ${OBJECTDIR}/_ext/728126550/mcc.o ${OBJECTDIR}/_ext/728126550/pin_manager.o ${OBJECTDIR}/_ext/728126550/pwm.o ${OBJECTDIR}/_ext/728126550/reset.o ${OBJECTDIR}/_ext/728126550/system.o ${OBJECTDIR}/_ext/728126550/traps.o ${OBJECTDIR}/main.o ${OBJECTDIR}/adc.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/728126550/clock.o.d ${OBJECTDIR}/_ext/728126550/interrupt_manager.o.d ${OBJECTDIR}/_ext/728126550/mcc.o.d ${OBJECTDIR}/_ext/728126550/pin_manager.o.d ${OBJECTDIR}/_ext/728126550/pwm.o.d ${OBJECTDIR}/_ext/728126550/reset.o.d ${OBJECTDIR}/_ext/728126550/system.o.d ${OBJECTDIR}/_ext/728126550/traps.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/adc.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/728126550/clock.o ${OBJECTDIR}/_ext/728126550/interrupt_manager.o ${OBJECTDIR}/_ext/728126550/mcc.o ${OBJECTDIR}/_ext/728126550/pin_manager.o ${OBJECTDIR}/_ext/728126550/pwm.o ${OBJECTDIR}/_ext/728126550/reset.o ${OBJECTDIR}/_ext/728126550/system.o ${OBJECTDIR}/_ext/728126550/traps.o ${OBJECTDIR}/main.o ${OBJECTDIR}/adc.o

# Source Files
SOURCEFILES=../AdctoPwm.X/mcc_generated_files/clock.c ../AdctoPwm.X/mcc_generated_files/interrupt_manager.c ../AdctoPwm.X/mcc_generated_files/mcc.c ../AdctoPwm.X/mcc_generated_files/pin_manager.c ../AdctoPwm.X/mcc_generated_files/pwm.c ../AdctoPwm.X/mcc_generated_files/reset.c ../AdctoPwm.X/mcc_generated_files/system.c ../AdctoPwm.X/mcc_generated_files/traps.c main.c adc.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512GM710
MP_LINKER_FILE_OPTION=,--script=p33EP512GM710.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/728126550/clock.o: ../AdctoPwm.X/mcc_generated_files/clock.c  .generated_files/flags/default/160df427e3d013fb3f0c7b07a70f97692acab457 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/clock.c  -o ${OBJECTDIR}/_ext/728126550/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/clock.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/interrupt_manager.o: ../AdctoPwm.X/mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/761891ad84a7f3f07cd542e3e2119dc5483acfbf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/_ext/728126550/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/interrupt_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/mcc.o: ../AdctoPwm.X/mcc_generated_files/mcc.c  .generated_files/flags/default/303987a7b6711f20a911c5836e4bc363dd808cba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/mcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/mcc.c  -o ${OBJECTDIR}/_ext/728126550/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/mcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/pin_manager.o: ../AdctoPwm.X/mcc_generated_files/pin_manager.c  .generated_files/flags/default/8088558d880f467625c17e41c54aaf9c89d118a2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/_ext/728126550/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/pin_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/pwm.o: ../AdctoPwm.X/mcc_generated_files/pwm.c  .generated_files/flags/default/9047cf85c9ebc3e4af282d227429120133823ae5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/pwm.c  -o ${OBJECTDIR}/_ext/728126550/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/pwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/reset.o: ../AdctoPwm.X/mcc_generated_files/reset.c  .generated_files/flags/default/8af4174b619353200170e9159f6b427b61cb339d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/reset.c  -o ${OBJECTDIR}/_ext/728126550/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/reset.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/system.o: ../AdctoPwm.X/mcc_generated_files/system.c  .generated_files/flags/default/af6c098d3a850e98f63c6108dfd7f2403d89934d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/system.c  -o ${OBJECTDIR}/_ext/728126550/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/traps.o: ../AdctoPwm.X/mcc_generated_files/traps.c  .generated_files/flags/default/bb37d89738115908d62953a6ec2aea18c6e5df9a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/traps.c  -o ${OBJECTDIR}/_ext/728126550/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/traps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a6b2db5991c3a8920cfda571a068a947a1bef622 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/default/aa540e35b06f857b0af868028a732a2bf00894 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/728126550/clock.o: ../AdctoPwm.X/mcc_generated_files/clock.c  .generated_files/flags/default/359f9a14b30d15140c4c992b72360385f076b9b4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/clock.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/clock.c  -o ${OBJECTDIR}/_ext/728126550/clock.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/clock.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/interrupt_manager.o: ../AdctoPwm.X/mcc_generated_files/interrupt_manager.c  .generated_files/flags/default/342f164a368999657b0ea2f3e9e14d8d2f98c80 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/interrupt_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/interrupt_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/interrupt_manager.c  -o ${OBJECTDIR}/_ext/728126550/interrupt_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/interrupt_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/mcc.o: ../AdctoPwm.X/mcc_generated_files/mcc.c  .generated_files/flags/default/3a700c0a146e0dc82357901e4b9352d196008ac7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/mcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/mcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/mcc.c  -o ${OBJECTDIR}/_ext/728126550/mcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/mcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/pin_manager.o: ../AdctoPwm.X/mcc_generated_files/pin_manager.c  .generated_files/flags/default/426d7851397dd76057fa8aa6f3dc44dd9cbbecab .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/_ext/728126550/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/pwm.o: ../AdctoPwm.X/mcc_generated_files/pwm.c  .generated_files/flags/default/88680721aa915176630f16ee39b9992131a8c627 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/pwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/pwm.c  -o ${OBJECTDIR}/_ext/728126550/pwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/pwm.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/reset.o: ../AdctoPwm.X/mcc_generated_files/reset.c  .generated_files/flags/default/a3e0bd562dd5414163ef479532dcc0cb8d224f01 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/reset.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/reset.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/reset.c  -o ${OBJECTDIR}/_ext/728126550/reset.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/reset.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/system.o: ../AdctoPwm.X/mcc_generated_files/system.c  .generated_files/flags/default/db19ed9d9fa9bd99b2a486c2a053ce960f0b0385 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/system.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/system.c  -o ${OBJECTDIR}/_ext/728126550/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/728126550/traps.o: ../AdctoPwm.X/mcc_generated_files/traps.c  .generated_files/flags/default/2cc2bb22178fbbbef9c0ab96b3445c3f3ed40e37 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/728126550" 
	@${RM} ${OBJECTDIR}/_ext/728126550/traps.o.d 
	@${RM} ${OBJECTDIR}/_ext/728126550/traps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../AdctoPwm.X/mcc_generated_files/traps.c  -o ${OBJECTDIR}/_ext/728126550/traps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/728126550/traps.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/27caea55bdbc073f98e17faccb0dba903f0abff8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/adc.o: adc.c  .generated_files/flags/default/b344ec622f3061a34142fbc864f6890656c8f9ae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/adc.o.d 
	@${RM} ${OBJECTDIR}/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  adc.c  -o ${OBJECTDIR}/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/AdctoPwm.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
