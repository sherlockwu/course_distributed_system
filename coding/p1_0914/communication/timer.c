#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

void current_utc_time(struct timespec *ts) {

#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
  clock_serv_t cclock;
  mach_timespec_t mts;
  host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
  clock_get_time(cclock, &mts);
  mach_port_deallocate(mach_task_self(), cclock);
  ts->tv_sec = mts.tv_sec;
  ts->tv_nsec = mts.tv_nsec;
#else
  clock_gettime(CLOCK_REALTIME, ts);
#endif

}


int main(int argc, char * argv[]){
    // begin timer
    struct timespec t_start;
    struct timespec t_end;
    double t_diff;
    char * input_file_name;
    char * output_file_name;
    int try = 0;
    char * s = (char *)malloc(1024*1025*sizeof(char));
    //clock_gettime(CLOCK_MONOTONIC, &t_start);

    input_file_name = (char *)malloc(100*sizeof(char));
    output_file_name = (char *)malloc(100*sizeof(char));
    int ret = snprintf(input_file_name, 100, "%s", argv[1]);
    ret = snprintf(output_file_name, 100, "%s", argv[2]);
    int input_file;
    int output_file;
    input_file = open(input_file_name, O_RDONLY);
    output_file = open(output_file_name, O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU);

    current_utc_time(&t_start);

    int rc = read(input_file, s, 1024*1024);

    // current_utc_time(&t_start);

    // do something
    // system("ls");

    //rc = write(output_file, s, 4*1024);
    //try++;
    // cal the time difference (if >0, print out)
    //clock_gettime(CLOCK_MONOTONIC, &t_end);
    current_utc_time(&t_end);


    t_diff = 1e9 * (t_end.tv_sec - t_start.tv_sec) + (t_end.tv_nsec - t_start.tv_nsec);
    printf("time difference: %f ns\n", t_diff);
    return 0;
}
