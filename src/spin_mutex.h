#ifndef __SPIN_MUTEX__
#define __SPIN_MUTEX__

#include <mutex>
#include <atomic>
namespace SpinZone{
	class SpinMutex{
	public:
		SpinMutex() = default;
		SpinMutex(const SpinMutex&) = delete;
		SpinMutex& operator=(const SpinMutex&) = delete;
		void lock(){
			while(flag.test_and_set(std::memory_order_acquire));
		}
		void unlock(){
			flag.clear(std::memory_order_release);
		}
	private:
		std::atomic_flag flag = ATOMIC_FLAG_INIT;
	};
}
#endif // __SPIN_MUTEX__
