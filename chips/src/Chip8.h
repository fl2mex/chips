#pragma once
#include "Include.h"

typedef struct {
	uint16_t opcode;	// The full original 16 bit opcode
	uint16_t NNN;		// 12 bit constant (address)
	uint8_t NN;			// 8 bit constant
	uint8_t N;			// 4 bit constant
	uint8_t X;			// 4 bit Register identifier  
	uint8_t Y;			// 4 bit Register identifier
} inst_t;

const uint8_t font[80]
{
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

class Chip8
{
public:
	Chip8();
	~Chip8();

	void Draw();
	uint8_t pixels[64 * 32]; // is there a better way to return an array?
	
	void HandleInstruction();

private:
	bool isRunning = false;
	bool isDebug = false;

	uint8_t ram[4096]{0};

	uint16_t stack[32]{0};
	uint8_t stackPtr{0};

	uint8_t V[16]{0}; // V registers

	uint16_t PC{0}; // Program counter
	uint16_t I{0}; // Index register

	uint8_t displayTimer{0}; // Count down to 0, then update screen
	uint8_t soundTimer{0}; // Count down to 0, then beep

	bool keypad[16]{0}; // States

	inst_t currentInstruction{0};
};