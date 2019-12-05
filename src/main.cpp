#include <iostream>
#include <thread>
#include "spin_mutex.h"
#include <vector>

void funcTask(SpinZone::SpinMutex &mtx, int &num, int id){
	for(int i = 0; i < 100000; ++i){
		std::lock_guard<SpinZone::SpinMutex> lck(mtx);
		++num;
		std::cout<< "thread " << id << " " << num << std::endl;
	}
}

void func(){
	std::vector<int> vec;
	vec.crbegin();

	SpinZone::SpinMutex s;
	s.lock();
}
int main(){
	int num = 0;
	SpinZone::SpinMutex mtx;
	std::thread t1(funcTask, std::ref(mtx), std::ref(num), 1);
	std::thread t2(funcTask, std::ref(mtx), std::ref(num), 2);

	t1.join();
	t2.join();
	std::cout<< "main thread" << std::endl;
	return 0;
}
