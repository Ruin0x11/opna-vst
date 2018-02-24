/**
 * @file	nevent.h
 * @brief	Interface of the event
 */

#pragma once

enum
{
	NEVENT_MAXCLOCK		= 0x400000,
};

/**
 * NEvent ID
 */
enum tagNEventId
{
	NEVENT_FLAMES		= 0,
	NEVENT_ITIMER		= 1,
	NEVENT_BEEP			= 2,
	NEVENT_RS232C		= 3,
	NEVENT_MUSICGEN		= 4,
	NEVENT_FMTIMERA		= 5,
	NEVENT_FMTIMERB		= 6,
	NEVENT_FMTIMER2A	= 7,
	NEVENT_FMTIMER2B	= 8,
	//	NEVENT_FMTIMER3A	= 9,
	//	NEVENT_FMTIMER3B	= 10,
	//	NEVENT_FMTIMER4A	= 11,
	//	NEVENT_FMTIMER4B	= 12,
	NEVENT_MOUSE		= 13,
	NEVENT_KEYBOARD		= 14,
	NEVENT_MIDIWAIT		= 15,
	NEVENT_MIDIINT		= 16,
	NEVENT_PICMASK		= 17,
	NEVENT_S98TIMER		= 18,
	NEVENT_CS4231		= 19,
	NEVENT_GDCSLAVE		= 20,
	NEVENT_FDBIOSBUSY	= 21,
	NEVENT_FDCINT		= 22,
	NEVENT_PC9861CH1	= 23,
	NEVENT_PC9861CH2	= 24,
	NEVENT_86PCM		= 25,
	NEVENT_SASIIO		= 26,
	NEVENT_SCSIIO		= 27,
	/* ---- */
	NEVENT_MAXEVENTS	= 32
};
typedef enum tagNEventId NEVENTID;

/**
 * event position
 */
enum tagNEventPosition
{
	NEVENT_RELATIVE		= 0,		/*!< relative */
	NEVENT_ABSOLUTE		= 1			/*!< absolute */
};
typedef enum tagNEventPosition NEVENTPOSITION;		/*!< the defines of position */

struct _neventitem;
typedef	struct _neventitem	_NEVENTITEM;
typedef	struct _neventitem	*NEVENTITEM;
typedef void (*NEVENTCB)(NEVENTITEM item);

struct _neventitem
{
	SINT32		clock;
	NEVENTCB	proc;
	INTPTR		userData;
};

typedef struct {
	UINT		readyevents;
	NEVENTID	level[NEVENT_MAXEVENTS];
	_NEVENTITEM	item[NEVENT_MAXEVENTS];
} _NEVENT, *NEVENT;


#ifdef __cplusplus
extern "C" {
#endif

extern	_NEVENT		g_nevent;

#ifdef __cplusplus
}
#endif
