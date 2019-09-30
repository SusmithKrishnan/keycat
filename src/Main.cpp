#include <random>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

int DELAY = 10000;
std::string U_ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string L_ALPHA = "abcdefghijklmnopqrstuvwxyz";
std::string NUM = "0123456789";
std::string SPECIAL_CHARS = "`~!@#$%^&*()-_=+{}:\"|<>?[];',.";
std::string CHARSET;

int random_num(int max_length){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0,max_length);
	return dist6(rng);
}

void do_loop(int *delay, const std::string& charset){
	while(1){
		usleep(*delay);  
		std::cout <<charset[random_num(charset.length())];
		std::cout.flush();
	}
}

void usage(){
	std::cout<< "KCat v1.0\n"
				"Keboard cat usage:\n"
				"    -d    --delay      Delay between each char in microseconds\n"
				"    -s    --slow       Print in slow mode\n"
				"    -f    --fast       Print in fast mode\n"
				"    -i    --insane     Print in insane mode\n"
				"    -l    --lower-case Include lowercase characters\n"
				"    -u    --upper-case Include uppercase characters\n"
				"    -n    --num        Include numbers\n"
				"    -x    --special    Include special chars\n"
				"    -h    --help       Print this help and exit\n";
	exit(0);			
}
int main(int argc, char** argv) {
	static struct option long_options[] = {
		{"delay", required_argument, NULL, 'd'},
		{"slow", no_argument, NULL, 's'},
		{"fast", no_argument, NULL, 'f'},
		{"insane", no_argument, NULL, 'i'},
		{"lower-case", no_argument, NULL, 'l'},
		{"upper-case", no_argument, NULL, 'u'},
		{"num", no_argument, NULL, 'n'},
		{"special", no_argument, NULL, 'x'},
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};
	
	int c =0;
	while ((c = getopt_long(argc, argv, "d:sfilunxh", long_options, NULL)) != -1)
	switch(c){
		case 'i':
			DELAY = 100;
			break;
		case 'f':
			DELAY = 1000;
			break;
		case 's':
			DELAY = 100000;
			break;
		case 'd':
			 DELAY = (std::atoi(optarg) >9) ? std::atoi(optarg) : 10;
			break;
		case 'l':
			 CHARSET+=L_ALPHA;
			break;
		case 'u':
			 CHARSET+=U_ALPHA;
			break;
		case 'n':
			 CHARSET+=NUM;
			break;
		case 'x':
			 CHARSET+=SPECIAL_CHARS;
			break;
		case 'h':
			 usage();
			break;
		case '?':
			 usage();
			break;
	}
	if(CHARSET.empty()) CHARSET = U_ALPHA+L_ALPHA+NUM+SPECIAL_CHARS; 
	do_loop(&DELAY, CHARSET);
}