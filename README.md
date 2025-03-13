# C++ HelloWorld 项目

这是一个简单的 C++ HelloWorld 项目，演示了多线程和互斥锁的使用。

## 目录结构

```
helloworld/
├── .vscode/
│   ├── launch.json
│   └── tasks.json
├── build/
├── CMakeLists.txt
├── helloworld.cpp
└── README.md
```

## 先决条件

在开始之前，请确保你已经安装了以下软件：

- [CMake](https://cmake.org/download/)
- [MinGW](http://www.mingw.org/) 或其他兼容的 C++ 编译器

## 编译和运行

1. 打开命令提示符或 PowerShell。
2. 导航到项目目录：

    ```sh
    cd f:\test\c++lern\helloworld
    ```

3. 删除之前的构建目录（如果存在）：

    ```sh
    Remove-Item -Recurse -Force .\build
    ```

4. 创建新的构建目录并进入该目录：

    ```sh
    mkdir build
    cd build
    ```

5. 运行 CMake 以生成构建文件：

    ```sh
    cmake -G "MinGW Makefiles" ..
    ```

6. 使用 MinGW 编译项目：

    ```sh
    mingw32-make
    ```

7. 运行生成的可执行文件：

    ```sh
    .\helloworld.exe
    ```

## 使用 Visual Studio Code 进行调试

1. 确保你的项目目录中包含以下文件：

    - `.vscode/launch.json`
    - `.vscode/tasks.json`

2. 在 Visual Studio Code 中打开项目目录。
3. 按 `F5` 启动调试。

## 代码说明

`helloworld.cpp` 文件包含一个简单的多线程示例，使用互斥锁来确保线程安全地打印线程 ID。

```cpp
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
```

