/*
File:		kernel/syscall.c
Contains:	syscall set here 
Auther:		Hu Zicheng
Time:		2019/2/20
Copyright:	(C) 2018-2019 by BookOS developers. All rights reserved.
E-mail:		2323168280@qq.com
*/

#include <sys/syscall.h>
#include <sys/console.h>
#include <sys/memory.h>
#include <sys/keyboard.h>
#include <sys/debug.h>
#include <sys/thread.h>
#include <sys/process.h>
#include <sys/system.h>
#include <sys/clock.h>
#include <sys/graphic.h>
#include <sys/mouse.h>
#include <sys/video.h>
#include <sys/fs.h>

/**
	添加一个系统调用步骤：
	1.sys_call_table中添加函数名
	2.系统调用函数体和头文件
	3.在user的syscall中添加中断调用和头文件
*/

sys_call_t sys_call_table[MAX_SYS_CALLS];

void init_syscall()
{
	sys_call_table[_NR_WRITE] = sys_write_str;
	sys_call_table[_NR_MALLOC] = sys_memory_alloc;
	sys_call_table[_NR_FREE] = sys_memory_free;
	sys_call_table[_NR_EXIT] = sys_exit;
	sys_call_table[_NR_GETCHAR] = sys_get_key;
	sys_call_table[_NR_PUTCHAR] = sys_writ_char;
	sys_call_table[_NR_EXECV] = sys_execv;
	sys_call_table[_NR_WAIT] = sys_wait;
	sys_call_table[_NR_CLEAR] = sys_clean_screen;
	sys_call_table[_NR_PS] = print_threads;
	
	sys_call_table[_NR_FOPEN] = fs.open;
	sys_call_table[_NR_FCLOSE] = fs.close;
	sys_call_table[_NR_FREAD] = fs.read;
	sys_call_table[_NR_FWRITE] = fs.write;
	sys_call_table[_NR_LSEEK] = fs.lseek;
	sys_call_table[_NR_FSTAT] = fs.stat;
	sys_call_table[_NR_UNLINK] = fs.unlink;
	sys_call_table[_NR_OPENDIR] = fs.opendir;
	sys_call_table[_NR_CLOSEDIR] = fs.closedir;
	sys_call_table[_NR_READDIR] = fs.readdir;
	sys_call_table[_NR_REWINDDIR] = fs.rewinddir;
	sys_call_table[_NR_MKDIR] = fs.mkdir;
	sys_call_table[_NR_RMDIR] = fs.rmdir;
	sys_call_table[_NR_CHDIR] = fs.chdir;
	sys_call_table[_NR_GETCWD] = fs.getcwd;
	sys_call_table[_NR_RENAME] = fs.rename;
	sys_call_table[_NR_COPY] = fs.copy;
	sys_call_table[_NR_MOVE] = fs.move;
	sys_call_table[_NR_ACCESS] = fs.access;
	sys_call_table[_NR_LSDIR] = fs.lsdir;

	
	sys_call_table[_NR_REBOOT] = sys_reboot;
	sys_call_table[_NR_GETTIME] = sys_gettime;
	sys_call_table[_NR_GET_MOUSE_POS] = sys_get_mouse_position;
	sys_call_table[_NR_GET_MOUSE_BTN] = sys_get_mouse_button;
	sys_call_table[_NR_GET_SCREEN] = sys_get_screen;
	sys_call_table[_NR_GET_MEMORY] = sys_get_memory;
	sys_call_table[_NR_GET_PID] = sys_get_pid;
	sys_call_table[_NR_GET_TICKS] = sys_get_ticks;
	sys_call_table[_NR_SLEEP] = msec_sleep;
	sys_call_table[_NR_LSDISK] = fs.lsdisk;
	
	sys_call_table[_NR_INIT_GRAPHIC] = sys_init_graphic;
	sys_call_table[_NR_GRAPH_POINT] = sys_graph_point;
	sys_call_table[_NR_GRAPH_REFRESH] = sys_graph_refresh;
	sys_call_table[_NR_GRAPH_LINE] = sys_graph_line;
	sys_call_table[_NR_GRAPH_RECT] = sys_graph_rect;
	sys_call_table[_NR_GRAPH_TEXT] = sys_graph_text;
	sys_call_table[_NR_GRAPHIC_EXIT] = sys_graphic_exit;
	sys_call_table[_NR_GRAP_BUFFER] = sys_graph_buffer;
	sys_call_table[_NR_GRAP_WORD] = sys_graph_char;

	
	
	
}
