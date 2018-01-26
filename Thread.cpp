#include "Thread.h"
#include <time.h>
Thread::Thread(void (*callback)(void), unsigned long _interval){
	enabled = true;
	onRun(callback);
	_cached_next_run = 0;
	last_run = millis();

	ThreadID = (int)this;
	#ifdef USE_THREAD_NAMES
		ThreadName = "Thread ";
		ThreadName = ThreadName + ThreadID;
	#endif
	ThreadState = 0;
	TimeLimitation = 0;
	setInterval(_interval);
};

void Thread::runned(unsigned long time){
	// Saves last_run
	last_run = time;

	// Cache next run
	_cached_next_run = last_run + interval;
}



void Thread::setInterval(unsigned long _interval){
	// Save interval
	interval = _interval;

	// Cache the next run based on the last_run
	_cached_next_run = last_run + interval;
}

void Thread::waitFor(int a, int b)
{
	TimeLimitation = millis() + (rand() % (b-a+1)) + a ;
}

bool Thread::shouldRun(unsigned long time){
	
	if(millis() < TimeLimitation){ return false;}
	
	// If the "sign" bit is set the signed difference would be negative
	bool time_remaining = (time - _cached_next_run) & 0x80000000;

	// Exceeded the time limit, AND is enabled? Then should run...
	return !time_remaining && enabled;
}

void Thread::onRun(void (*callback)(void)){
	if(millis() < TimeLimitation){ return;}
	
	_onRun = callback;
}

void Thread::run(){
	if(millis() < TimeLimitation){ return;}
	
	if(_onRun != NULL)
		_onRun();

	// Update last_run and _cached_next_run
	runned();
}
