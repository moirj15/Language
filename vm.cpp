#include "vm.h"

namespace VM {

	
/**
 * Constructor.
 *
 * @param bCode: The byteCode.
 * @param n: The name of the byteCode.
 */
DebugByteCode::DebugByteCode(uint64 bCode, std::string n) 
	: byteCode(bCode), name(n) {

}

/**
 * Destructor.
 */
DebugByteCode::~DebugByteCode() {

}


/**
 * Constructor.
 *
 * @param c: The vector containing the bytecode and data.
 */
VM::VM(std::vector<uint64> c) : code(c) {
	//opStack = std::stack<uint64>();
	pc = 0;
}

/**
 * Destructor.
 */
VM::~VM(void) {

}

/**
 * Run the VM.
 */
void VM::run(void) {
	bool running = true;
	while (running) {
		printf("%ld\n", code[pc]);
		switch(code[pc]) {
			
			case NOP:
				pc++;
				break;
			
			case PUSH_INT:
				pc++;
				opStack.push(code[pc]);
				pc++;
				break;

			case ADD_INT: {
				uint64 a = opStack.top();
				opStack.pop();
				uint64 b = opStack.top();
				opStack.pop();
				opStack.push(a + b);
				pc++;
			}	break;

			case PRINT:
				printf("%ld\n", opStack.top());
				opStack.pop();
				pc++;
				break;

			case HALT:
				printf("result: %ld\n", opStack.top());
				running = false;
				pc++;
				break;

			default:
				quit("unknown bytecode");
				break;
		}
	}
}

} // end namespace
