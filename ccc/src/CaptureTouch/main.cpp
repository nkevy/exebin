#include "capt.h"
//
//
//pass a tool to the cmd and then run that tool on click
int main(int argc,char* argv[]){//main thread
	std::string cmd = get_cmd(argc,argv);//print help and handle args
	std::string err = "error";//define error msg
	if (!err.compare(cmd)){return 0;}//fi quit
	//show the capt tool info
	std::cout<<"[welcome] capt catpures input events. press ctrl+c or space to quit."<<std::endl;
	std::thread child;//create thread
	child = std::thread(handler);//start child thread
	if(child.joinable()){//check thread
		child.join();//wait for child
	}else{//print thread error
		std::cout<<"[thread error] could not join thread, exiting"<<std::endl;
		return 0;
	}//fi
	std::cout<<"[done]"<<std::endl;//show user capt tool is done
	std::cout<<std::flush;//flush stdout to see full responce
	return 0;//exit
}//main
//eof
