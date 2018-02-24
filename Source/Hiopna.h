#pragma once

#include "np2/win9x/compiler.h"
#include "np2/sound/opna.h"

#define INTERMEDIATE_BUF_SAMPLES		100000
#define INTERMEDIATE_BUF_N	4

class Hiopna
{
public:
	Hiopna();
	~Hiopna();
	void Reset();
	void Restore();

	void Generate(int length, float* buffer);
	void ExtendChannel(bool enable);
	void KeyOn(long freq);
	void KeyOff();
private: 
	OPNA opna;
	int intermediateBufIdx;
	SINT32 intermediateBuf[INTERMEDIATE_BUF_N][INTERMEDIATE_BUF_SAMPLES];
	UINT16 fNumBlocks[13];
};

