#include <stdio.h>
#include "cl.h"


int main(void)
{
	cl_uint num_of_platforms=0;
	cl_platform_id platform_id;
	cl_device_id device_id;
	cl_uint num_of_devices=0;
	size_t profile_size;
	char* profile = NULL;


	// retreive a list of platforms avaible
	if (clGetPlatformIDs(1, &platform_id, &num_of_platforms)!= CL_SUCCESS)
	{
		printf("Unable to get platform id \n");
		return 1;
	}

	// try to get a supported GPU device
	if (clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &num_of_devices) != CL_SUCCESS)
	{
		printf("Unable to get device id \n");
		return 1;
	}
	
	// get platform profile info
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_PROFILE, NULL, profile, &profile_size)){
	    printf("Unable to get platform info 1 \n");
	    return 1;
	}
	
	profile = (char*) malloc(profile_size);
	
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_PROFILE, profile_size, profile, NULL)){
	    printf("Unable to get platform info 2 \n");
	    return 1;
	}
	
	printf("PLATFORM PROFILE: %s", profile);
	printf("\n");
	
	free(profile);
	profile = NULL;

	// get platform version info
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_VERSION, NULL, profile, &profile_size)){
	    printf("Unable to get platform info 1 \n");
	    return 1;
	}
	
	profile = (char*) malloc(profile_size);
	
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_VERSION, profile_size, profile, NULL)){
	    printf("Unable to get platform info 2 \n");
	    return 1;
	}
	
	printf("PLATFORM VERSION: %s", profile);
	printf("\n");

    free(profile);
	profile = NULL;
	

	// get platform name info
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, NULL, profile, &profile_size)){
	    printf("Unable to get platform info 1 \n");
	    return 1;
	}
	
	profile = (char*) malloc(profile_size);
	
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_NAME, profile_size, profile, NULL)){
	    printf("Unable to get platform info 2 \n");
	    return 1;
	}
	
	printf("PLATFORM NAME: %s", profile);
	printf("\n");

    free(profile);
	profile = NULL;

	// get platform name info
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_VENDOR, NULL, profile, &profile_size)){
	    printf("Unable to get platform info 1 \n");
	    return 1;
	}
	
	profile = (char*) malloc(profile_size);
	
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_VENDOR, profile_size, profile, NULL)){
	    printf("Unable to get platform info 2 \n");
	    return 1;
	}
	
	printf("PLATFORM VENDOR: %s", profile);
	printf("\n");

    free(profile);
	profile = NULL;

	// get platform extension info
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_EXTENSIONS, NULL, profile, &profile_size)){
	    printf("Unable to get platform info 1 \n");
	    return 1;
	}
	
	profile = (char*) malloc(profile_size);
	
	if(clGetPlatformInfo(platform_id, CL_PLATFORM_EXTENSIONS, profile_size, profile, NULL)){
	    printf("Unable to get platform info 2 \n");
	    return 1;
	}
	
	printf("PLATFORM EXTENSIONS: %s", profile);
	printf("\n");


	return 0;
}


