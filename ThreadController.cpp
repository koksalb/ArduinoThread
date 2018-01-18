#include "Thread.h"
#include "ThreadController.h"
#include <time.h>
ThreadController::ThreadController(unsigned long _interval): Thread(){
	cached_size = 0;
	srand (time(NULL));
	clear();
	setInterval(_interval);

	#ifdef USE_THREAD_NAMES
		// Overrides name
		ThreadName = "ThreadController ";
		ThreadName = ThreadName + ThreadID;
	#endif
}

/*
	ThreadController run() (cool stuf)
*/

void ThreadController::run(){
	// Run this thread before
	if(_onRun != NULL)
		_onRun();

	unsigned long time = millis();
	int checks = 0;
	for(int i = 0; i < MAX_THREADS && checks <= cached_size; i++){
		// Object exists? Is enabled? Timeout exceeded?
		if(thread[i]){
			checks++;
			if(thread[i]->shouldRun(time)){
				thread[i]->run();
			}
		}
	}

	// ThreadController extends Thread, so we should flag as runned thread
	runned();
}

bool IsItThere(int list[], int element)
{
	for(int i = 0; i < sizeof(list);i++)
	{
		if(list[i] == element){return true;}
		
	}
	return false;
}
void ThreadController::runRandomly(){
	 	 
	// Run this thread before
	if(_onRun != NULL)
		_onRun();

	unsigned long time = millis();
	int checks = 0;
	int list[sizeof(thread)];
	for(int i = 0; i < MAX_THREADS && checks <= cached_size; i++){
		int randomnumber = rand() % MAX_THREADS;
		while(!thread[randomnumber] && IsItThere(list,randomnumber))
		{
			randomnumber = rand() % MAX_THREADS;
		}
		list[i] = randomnumber;
		// Object exists? Is enabled? Timeout exceeded?
		if(thread[randomnumber]){
			checks++;
			if(thread[randomnumber]->shouldRun(time)){
				thread[randomnumber]->run();
			}
		}
	}

	// ThreadController extends Thread, so we should flag as runned thread
	runned();
}



/*
	List controller (boring part)
*/
bool ThreadController::add(Thread* _thread){
	// Check if the Thread already exists on the array
	for(int i = 0; i < MAX_THREADS; i++){
		if(thread[i] != NULL && thread[i]->ThreadID == _thread->ThreadID)
			return true;
	}

	// Find an empty slot
	for(int i = 0; i < MAX_THREADS; i++){
		
		if(!thread[i]){
			// Found a empty slot, now add Thread
			thread[i] = _thread;
			cached_size++;
			return true;
		}
	}

	// Array is full
	return false;
}

void ThreadController::remove(int id){
	// Find Threads with the id, and removes
	bool found = false;
	for(int i = 0; i < MAX_THREADS; i++){
		if(thread[i]->ThreadID == id){
			thread[i] = NULL;
			cached_size--;
			return;
		}
	}
}

void ThreadController::remove(Thread* _thread){
	remove(_thread->ThreadID);
}

void ThreadController::clear(){
	for(int i = 0; i < MAX_THREADS; i++){
		thread[i] = NULL;
	}
	cached_size = 0;
}

int ThreadController::size(bool cached){
	if(cached)
		return cached_size;

	int size = 0;
	for(int i = 0; i < MAX_THREADS; i++){
		if(thread[i])
			size++;
	}
	cached_size = size;

	return cached_size;
}

Thread* ThreadController::get(int index){
	int pos = -1;
	for(int i = 0; i < MAX_THREADS; i++){
		if(thread[i] != NULL){
			pos++;

			if(pos == index)
				return thread[i];
		}
	}

	return NULL;
}
