#include "vm.h"

namespace VM {

/**
 * Run the VM.
 */
void VirtualMachine::run(void) {
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
				u64 a = opStack.top();
				opStack.pop();
				u64 b = opStack.top();
				opStack.pop();
				opStack.push(a + b);
				pc++;
			}	break;

			case SUB_INT: {

			} 	break;

			case DIV_INT: {

			} 	break;

			case MULT_INT: {

			} 	break;

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
