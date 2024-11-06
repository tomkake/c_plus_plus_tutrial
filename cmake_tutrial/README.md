# ファイルの位置関係

```
├── README.md
├── include
│   └── test.h
├── lib
│   └── libShared.so
├── main.cpp
└── test.cpp
```

# 共有ライブラリを作る

lib 配下に libShared.so ができる
`g++ -shared -fPIC -o lib/libShared.so test.cpp -I./include`

# cmakelists.txt を作る(失敗)

```
cmake_minimum_required(VERSION 3.5)
project(cmake_tutrial)
set(SOURCEFILE main.cpp)
set(SHAREDLIB "lib/")
set(SHAREDHEADER "include/")

add_executable(main ${SOURCEFILE})

target_include_directories(main PRIVATE ${SHAREDHEADER})

target_link_libraries(main PRIVATE ${SHAREDLIB})
```

```
cmake -S . -B build/
cmake --build build/
```

```
[ 50%] Building CXX object CMakeFiles/main.dir/main.cpp.o
[100%] Linking CXX executable main
/usr/bin/ld: -llib/ が見つかりません: そのようなファイルやディレクトリはありません
collect2: error: ld returned 1 exit status
gmake[2]: *** [CMakeFiles/main.dir/build.make:97: main] エラー 1
gmake[1]: *** [CMakeFiles/Makefile2:83: CMakeFiles/main.dir/all] エラー 2
gmake: *** [Makefile:91: all] エラー 2
```

# cmakelists.txt を作る(成功)

```
cmake_minimum_required(VERSION 3.5)
project(cmake_tutrial)
set(SOURCEFILE main.cpp)
set(SHAREDLIB "lib")
set(SHAREDHEADER "include/")

add_executable(main ${SOURCEFILE})

target_include_directories(main PRIVATE ${SHAREDHEADER})

target_link_libraries(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${SHAREDLIB}/libShared.so)

```

```
cmake -S . -B build/
cmake --build build/
```

```
./build/main

~/Github/c_plus_plus_tutrial/cmake_tutrial$ ./build/main
bou
```

# 共有ライブラリも cmake で作る

```
cmake_minimum_required(VERSION 3.5)
project(cmake_tutrial)
set(SOURCEFILE main.cpp)
set(SHAREDLIB "lib/")
set(SHAREDHEADER "include/")

add_library(test SHARED test.cpp)  # <-- ここを修正
add_executable(main ${SOURCEFILE})

target_include_directories(test PUBLIC ${SHAREDHEADER}) # <-- ここを修正

target_link_libraries(main PRIVATE test) # <-- ここを修正


```
