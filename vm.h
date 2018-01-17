#ifndef VM_H
#define VM_H

#include "utils.h"

namespace VM {

enum BYTE_CODE {
	NOP,
	PUSH_INT,
	ADD_INT,
	PRINT,
	HALT,

};

/**
 * Struct used for debuging the VM and bytecode.
 */
struct DebugByteCode {
	uint64 		byteCode;
	std::string name;

	/**
	 * Constructor.
	 *
	 * @param bCode: The byteCode.
	 * @param n: The name of the byteCode.
	 */
	DebugByteCode(uint64 bCode, std::string n);
	
	/**
	 * Destructor.
	 */
	~DebugByteCode();
};

/**
 * The virtual machine.
 */
struct VM {
	// TODO: replace std::stack
	std::stack<uint64> 		opStack;
	std::vector<uint64> 	code;
	uint64					pc;

	/**
	 * Constructor.
	 *
	 * @param c: The vector containing the bytecode and data.
	 */
	VM(std::vector<uint64> c);

	/**
	 * Destructor.
	 */
	~VM(void);

	/**
	 * Run the VM.
	 */
	void run(void);
};

}


#endif
