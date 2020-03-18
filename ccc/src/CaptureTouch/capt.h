#ifndef __CAPT_H__
#define __CAPT_H__

#define T_BUFF "/dev/input/mice"

#define T_MAX_X 1280
#define T_MAX_Y 1280

#include <linux/input.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>
#include <future>
#include <string.h>
#include <iostream>

struct watch_touch{
	watch_touch(): cur_x(-1),cur_y(-1),og_x(-1),og_y(-1),press(false){}
	int cur_x;
	int cur_y;
	int og_x;
	int og_y;
	bool press;
	std::string cmd;
};
struct watch_touch thetouch;
std::thread init_watch(std::future<void> stop, std::string strcmd);
void exec_watch();
std::string get_cmd(int argc, char *argv[]);
#endif
