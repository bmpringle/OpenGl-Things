#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/GLObjectList.o \
	${OBJECTDIR}/Rect.o \
	${OBJECTDIR}/RegularPolygon.o \
	${OBJECTDIR}/WindowVars.o \
	${OBJECTDIR}/main1.1.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_things

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_things: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl_things ${OBJECTFILES} ${LDLIBSOPTIONS} -framework OpenGL -framework GLUT

${OBJECTDIR}/GLObjectList.o: GLObjectList.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I/System/Library/Frameworks -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GLObjectList.o GLObjectList.cpp

${OBJECTDIR}/Rect.o: Rect.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I/System/Library/Frameworks -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Rect.o Rect.cpp

${OBJECTDIR}/RegularPolygon.o: RegularPolygon.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I/System/Library/Frameworks -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RegularPolygon.o RegularPolygon.cpp

${OBJECTDIR}/WindowVars.o: WindowVars.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I/System/Library/Frameworks -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/WindowVars.o WindowVars.cpp

${OBJECTDIR}/main1.1.o: main1.1.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -w -I/System/Library/Frameworks -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main1.1.o main1.1.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
