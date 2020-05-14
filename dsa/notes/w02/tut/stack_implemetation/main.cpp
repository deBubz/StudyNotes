#include "./aStack.cpp"

// things be running here
int main() {
	AStack* st = new AStack();


	for(int i = 3; i < 10; i++){
		if(i <= 5){
			st->push(i);
		} else {
		  st->pop();
		}
	}

	st->display();

	delete st;      // deallocate before exiting
}