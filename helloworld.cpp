#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;

void print_thread_id(int id) {
    std::lock_guard<std::mutex> lock(mtx); // 锁定互斥锁
    std::cout << "Thread ID: " << id << std::endl;
    // 作用域结束时，自动解锁互斥锁
}

int main() {
    const int num_threads = 10;
    std::vector<std::thread> threads;

    for (int i = 1; i <= num_threads; ++i) {
        threads.emplace_back(print_thread_id, i);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}




/*
cd f:\test\c++lern\helloworld
Remove-Item -Recurse -Force .\build
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
*/