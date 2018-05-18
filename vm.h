#ifndef VM_H
#define VM_H

#include "utils.h"

namespace VM {

enum BYTE_CODE 
{
	NOP,
	PUSH_INT,
	ADD_INT,
	SUB_INT,
	DIV_INT,
	MULT_INT,
	PRINT,
	HALT,
};

/**
 * Struct used for debuging the VM and bytecode.
 */
struct DebugByteCode 
{
	u64 		byteCode;
	std::string name;

	/**
	 * Constructor.
	 *
	 * @param bCode: The byteCode.
	 * @param n: The name of the byteCode.
	 */
	DebugByteCode(u64 bCode, std::string n) : byteCode(bCode), name(n) {} 
	
	/**
	 * Destructor.
	 */
	~DebugByteCode(void) {}
};

/**
 * The virtual machine.
 */
struct VirtualMachine 
{
	// TODO: replace std::stack
	std::stack<u64> 	opStack;
	std::vector<u64> 	code;
	u64					pc;

	/**
	 * Constructor.
	 *
	 * @param c: The vector containing the bytecode and data.
	 */
	VirtualMachine(std::vector<u64> c) : code(c), pc(0) {}

	/**
	 * Destructor.
	 */
	~VirtualMachine(void) {}

	/**
	 * Run the VM.
	 */
	void run(void);
};

}


#endif
