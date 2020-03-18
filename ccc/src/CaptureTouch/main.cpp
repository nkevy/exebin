#include "capt.h"
//
//
//pass a tool to the cmd and then run that tool on click
int main(int argc,char* argv[]){//main thread
	std::string cmd = get_cmd(argc,argv);//print help and handle args
	std::string err = "error";//define error msg
	if (!err.compare(cmd)){return 0;}//fi quit
	std::promise<void> sigterm;//obj to send signal
	std::future<void> futr = sigterm.get_future();//future object helps with memory alloc
	std::thread child = init_watch(std::move(futr),cmd);//initialise thread and give future obj
	usleep(9999999);
	sigterm.set_value();//send the stop signal
	child.join();//wait for child to exit
	std::cout<<"[done]"<<std::endl;
	std::cout<<std::flush;//flush stdout to see full responce
}//main
//eof
