#ifndef __CAPT_H__
#define __CAPT_H__

#define T_BUFF "/dev/input/event1"

#define T_MAX_X 1280
#define T_MAX_Y 1280

#include <linux/input.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include <string.h>
#include <iostream>

struct touch{
	touch(): cur_x(-1),cur_y(-1),og_x(-1),og_y(-1),press(false),cmd(""){}
	int cur_x;
	int cur_y;
	int og_x;
	int og_y;
	bool press;
	std::string cmd;
};
inline struct touch thetouch;
void handler();
std::string get_cmd(int argc, char *argv[]);
#endif
