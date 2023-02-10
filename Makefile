a.out: main.cpp
	g++ -O0 -g -std=c++17 main.cpp FXGLWindow.cpp -fsanitize=address -fno-omit-frame-pointer -lFOX-1.6
