__kernel void passing_between(__global int *values,		
  	__global float *out,	
  	int length,	
  	int width)	
{		
	int i;	
	for (i=0; i < 6; i++) {	
		out[i] = i;
	}
	
}		