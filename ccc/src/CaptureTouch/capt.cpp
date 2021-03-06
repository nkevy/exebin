#include "capt.h"
//
void handler(){// read from T_BUFF and run thetouch.cmd
	int buf = open(T_BUFF,O_RDONLY|O_NONBLOCK);//open buffer read only
	if(buf<0){//check for error
		std::cout<<"error: cant open input buffer"<<std::endl;
	}//fi
	struct input_event inev;//struct for buffer read
	while(1){//stops on signal
		read(buf,&inev,sizeof(struct input_event));//read /dev/input into input event struct
		if (inev.type==EV_REL){//touch event 
			std::cout<<"code:"<<inev.code<<std::endl;
			std::cout<<"value:"<<inev.value<<std::endl;
			if(inev.code==REL_X){//x
				thetouch.cur_x=inev.value;//save coordinate
				if(thetouch.og_x==-1){//first touch?
					thetouch.og_x=inev.value;//no longer -1
				}//fi
				system(thetouch.cmd.c_str());
			}//fi
			if(inev.code==REL_Y){//y
				thetouch.cur_y=inev.value;//save coordinate
				if(thetouch.og_y==-1){//first touch?
					thetouch.og_y=inev.value;//no longer -1
				}//fi
				system(thetouch.cmd.c_str());
			}//fi
			if(inev.code==BTN_LEFT&&inev.value>0){//down
				thetouch.press=true;//down touch event 
				thetouch.og_x=-1;//reset the x coordinate
				thetouch.og_y=-1;//reset the y coordinate
				system(thetouch.cmd.c_str());
			}//fi
			if(inev.code==BTN_LEFT&&inev.value==-1){//up
				thetouch.press=false;//up touch event
			}//fi
			if(inev.code==KEY_SPACE){//space bar to kill
				system(thetouch.cmd.c_str());
				break;
			}
		}//fi
	}//while(end_flag)
}//watch_touch_handler
//
std::string get_cmd(int argc,char *argv[]){//print the help screen and get cmd for system(cmd)
	std::string h="-h";//help code 
	std::string help="--help";//help code
	if (2<=argc){
		std::string arg(argv[1]);
		if (!h.compare(arg)){//compare
			std::cout<<"usage: capt <other cmd> <other cmd arg1> <other cmd arg2> <etc>"<<std::endl;
			return "error";
		}//fi
		if (!help.compare(arg)){//compare
			std::cout<<"usage: capt <other cmd> <other cmd arg1> <other cmd arg2> <etc>"<<std::endl;
			return "error";
		}//fi
	}//fi
	std::string cmd="";//string to collect cmd in argv
	for(int i=1;i<argc;i++){//iterate over argv
		std::string temp = argv[i];//convert to str
		cmd=cmd+temp+" ";//contatinate
	}//rof
	thetouch.cmd=cmd;//add str cmd to struct used by handler
	return cmd;//return string command
}//get_cmd
//
//eof
