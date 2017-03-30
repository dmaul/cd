#include <stdio.h>
#include "cl.h"
#\

#define DATA_SIZE 10

const char *KernelSource = 
"__kernel void hello(__global float *input, __global float *output)\n"\
"{\n"\
" size_t id = get_global_id(0);\n"\
" output[id] = input[id] * input[id];\n"\
"}\n"\
"\n";

int main(void) {

  cl_platform_id platform_id;
  cl_uint num_of_platforms;
  cl_device_id device_id;
  cl_uint num_of_devices=0;
  
  if(clGetPlatformIDs(1, &platform_id, &num_of_platforms) != CL_SUCCESS){
    printf("Unable to get platform_id \n");
    return 1;
  }
  
  if(clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_of_devices) != CL_SUCCESS){
    printf("Unable to get device_id \n");
    return 1;    
  }
  
  printf("Returning 0 ... \n");
  return 0;
  //printf(device_id);

}