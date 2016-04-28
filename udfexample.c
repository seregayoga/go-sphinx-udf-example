#include "sphinxudf.h"
#include "gopherpow.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _MSC_VER
#define snprintf _snprintf
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

DLLEXPORT int udfexample_ver ()
{
	return SPH_UDF_VERSION;
}


DLLEXPORT void udfexample_reinit ()
{
}


DLLEXPORT int gopher_pow_init ( SPH_UDF_INIT * init, SPH_UDF_ARGS * args, char * error_message )
{
	if ( args->arg_count != 2 )
	{
		snprintf ( error_message, SPH_UDF_ERROR_LEN, "GOPHER_POW() takes 2 arguments" );
		return 1;
	}

	if (
		args->arg_types[0] != SPH_UDF_TYPE_FLOAT ||
		args->arg_types[1] != SPH_UDF_TYPE_FLOAT
	)
	{
		snprintf ( error_message, SPH_UDF_ERROR_LEN, "GOPHER_POW() requires two float arguments" );
		return 1;
	}

	return 0;
}


DLLEXPORT void gopher_pow_deinit ( SPH_UDF_INIT * init )
{	
}


DLLEXPORT double gopher_pow ( SPH_UDF_INIT * init, SPH_UDF_ARGS * args, char * error_flag )
{
	return Pow(
		*(float*)args->arg_values[0],
		*(float*)args->arg_values[1]
	);
}
