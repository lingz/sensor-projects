/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.21
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#if defined(__GNUC__)
    typedef long long __int64; /*For gcc on Windows */
#endif
#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" } };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "CCSensorDevice.h"

char *SensorConfig_getSensorParam(SensorConfig *self,char *key){
		int i;
		for(i=0; i < self->numSensorParams; i++) {
			SensorParam * param = (self->sensorParams) + i;
			if(!strcmp(param->key, key)) {
				return param->value;
			}
		}
		
		return NULL;
	}
SensorConfig *ExperimentConfig_getSensorConfig(ExperimentConfig *self,int i){
		return (self->sensorConfigArray) + i;
	}
void ExperimentConfig_createSensorConfigArray(ExperimentConfig *self,int size){
		self->sensorConfigArray = malloc(sizeof(SensorConfig)*size);
	}
void ExperimentConfig_setSensorConfig(ExperimentConfig *self,SensorConfig *sConfig,int i){
		self->sensorConfigArray[i] = *sConfig;
	}


ExperimentConfig *getCurrentConfigHelper(SENSOR_DEVICE_HANDLE hDevice)
{
	ExperimentConfig *currentConfig;
	int err = SensDev_getCurrentConfig(hDevice, &currentConfig);
	if(err) {
		return 0;  // NULL
	}
	return currentConfig;
}

ExperimentConfig *configureHelper(SENSOR_DEVICE_HANDLE hDevice, ExperimentConfig *request)
{
	ExperimentConfig *response;
	response = NULL;
	int err = SensDev_configure(hDevice, request,&response);
	if(err) {
		return 0;  // NULL
	}
	return response;	
}



static float *new_floatArray(int nelements) { 
  return (float *) calloc(nelements,sizeof(float)); 
}

static void delete_floatArray(float *ary) { 
  free(ary); 
}

static float floatArray_getitem(float *ary, int index) {
    return ary[index];
}
static void floatArray_setitem(float *ary, int index, float value) {
    ary[index] = value;
}


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorParam_1key(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    SensorParam *arg1 = (SensorParam *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorParam **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg1->key) free((char*)arg1->key);
        if (arg2) {
            arg1->key = (char *) malloc(strlen(arg2)+1);
            strcpy((char*)arg1->key,arg2);
        } else {
            arg1->key = 0;
        }
    }
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorParam_1key(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    SensorParam *arg1 = (SensorParam *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorParam **)&jarg1; 
    result = (char *) ((arg1)->key);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorParam_1value(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    SensorParam *arg1 = (SensorParam *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorParam **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg1->value) free((char*)arg1->value);
        if (arg2) {
            arg1->value = (char *) malloc(strlen(arg2)+1);
            strcpy((char*)arg1->value,arg2);
        } else {
            arg1->value = 0;
        }
    }
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorParam_1value(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    SensorParam *arg1 = (SensorParam *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorParam **)&jarg1; 
    result = (char *) ((arg1)->value);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_new_1SensorParam(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    SensorParam *result;
    
    (void)jenv;
    (void)jcls;
    result = (SensorParam *)(SensorParam *) calloc(1, sizeof(SensorParam));
    
    *(SensorParam **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_delete_1SensorParam(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    SensorParam *arg1 = (SensorParam *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorParam **)&jarg1; 
    free((char *) arg1);
    
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1confirmed(JNIEnv *jenv, jclass jcls, jlong jarg1, jshort jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    unsigned char arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (unsigned char)jarg2; 
    if (arg1) (arg1)->confirmed = arg2;
    
}


JNIEXPORT jshort JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1confirmed(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jshort jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    unsigned char result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (unsigned char) ((arg1)->confirmed);
    
    jresult = (jshort)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1type(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    int arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (int)jarg2; 
    if (arg1) (arg1)->type = arg2;
    
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1type(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (int) ((arg1)->type);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1stepSize(JNIEnv *jenv, jclass jcls, jlong jarg1, jfloat jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    float arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (float)jarg2; 
    if (arg1) (arg1)->stepSize = arg2;
    
}


JNIEXPORT jfloat JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1stepSize(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jfloat jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    float result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (float) ((arg1)->stepSize);
    
    jresult = (jfloat)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1requiredMax(JNIEnv *jenv, jclass jcls, jlong jarg1, jfloat jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    float arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (float)jarg2; 
    if (arg1) (arg1)->requiredMax = arg2;
    
}


JNIEXPORT jfloat JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1requiredMax(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jfloat jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    float result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (float) ((arg1)->requiredMax);
    
    jresult = (jfloat)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1requiredMin(JNIEnv *jenv, jclass jcls, jlong jarg1, jfloat jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    float arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (float)jarg2; 
    if (arg1) (arg1)->requiredMin = arg2;
    
}


JNIEXPORT jfloat JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1requiredMin(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jfloat jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    float result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (float) ((arg1)->requiredMin);
    
    jresult = (jfloat)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1port(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    int arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (int)jarg2; 
    if (arg1) (arg1)->port = arg2;
    
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1port(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (int) ((arg1)->port);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1portName(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg2) strncpy(arg1->portName,arg2,64);
        else arg1->portName[0] = 0;
    }
    
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1portName(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (char *)(char *) ((arg1)->portName);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1name(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg2) strncpy(arg1->name,arg2,64);
        else arg1->name[0] = 0;
    }
    
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1name(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (char *)(char *) ((arg1)->name);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1unitStr(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg2) strncpy(arg1->unitStr,arg2,32);
        else arg1->unitStr[0] = 0;
    }
    
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1unitStr(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (char *)(char *) ((arg1)->unitStr);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1numSensorParams(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    int arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = (int)jarg2; 
    if (arg1) (arg1)->numSensorParams = arg2;
    
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1numSensorParams(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (int) ((arg1)->numSensorParams);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1SensorConfig_1sensorParams(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    SensorParam *arg2 = (SensorParam *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    arg2 = *(SensorParam **)&jarg2; 
    if (arg1) (arg1)->sensorParams = arg2;
    
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1SensorConfig_1sensorParams(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    SensorParam *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    result = (SensorParam *) ((arg1)->sensorParams);
    
    *(SensorParam **)&jresult = result; 
    return jresult;
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_SensorConfig_1getSensorParam(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    jstring jresult = 0 ;
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    char *arg2 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return 0;
        }
    }
    result = (char *)SensorConfig_getSensorParam(arg1,arg2);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_new_1SensorConfig(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    SensorConfig *result;
    
    (void)jenv;
    (void)jcls;
    result = (SensorConfig *)(SensorConfig *) calloc(1, sizeof(SensorConfig));
    
    *(SensorConfig **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_delete_1SensorConfig(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    SensorConfig *arg1 = (SensorConfig *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SensorConfig **)&jarg1; 
    free((char *) arg1);
    
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1valid(JNIEnv *jenv, jclass jcls, jlong jarg1, jshort jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    unsigned char arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (unsigned char)jarg2; 
    if (arg1) (arg1)->valid = arg2;
    
}


JNIEXPORT jshort JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1valid(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jshort jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    unsigned char result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (unsigned char) ((arg1)->valid);
    
    jresult = (jshort)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1invalidReason(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg1->invalidReason) free((char*)arg1->invalidReason);
        if (arg2) {
            arg1->invalidReason = (char *) malloc(strlen(arg2)+1);
            strcpy((char*)arg1->invalidReason,arg2);
        } else {
            arg1->invalidReason = 0;
        }
    }
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1invalidReason(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (char *) ((arg1)->invalidReason);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1period(JNIEnv *jenv, jclass jcls, jlong jarg1, jfloat jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    float arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (float)jarg2; 
    if (arg1) (arg1)->period = arg2;
    
}


JNIEXPORT jfloat JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1period(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jfloat jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    float result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (float) ((arg1)->period);
    
    jresult = (jfloat)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1exactPeriodUChar(JNIEnv *jenv, jclass jcls, jlong jarg1, jshort jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    unsigned char arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (unsigned char)jarg2; 
    if (arg1) (arg1)->exactPeriod = arg2;
    
}


JNIEXPORT jshort JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1exactPeriodUChar(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jshort jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    unsigned char result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (unsigned char) ((arg1)->exactPeriod);
    
    jresult = (jshort)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1numberOfSamples(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    long arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (long)jarg2; 
    if (arg1) (arg1)->numberOfSamples = arg2;
    
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1numberOfSamples(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    long result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (long) ((arg1)->numberOfSamples);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1dataReadPeriod(JNIEnv *jenv, jclass jcls, jlong jarg1, jfloat jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    float arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (float)jarg2; 
    if (arg1) (arg1)->dataReadPeriod = arg2;
    
}


JNIEXPORT jfloat JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1dataReadPeriod(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jfloat jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    float result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (float) ((arg1)->dataReadPeriod);
    
    jresult = (jfloat)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1deviceName(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    char *arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    {
        arg2 = 0;
        if (jarg2) {
            arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
            if (!arg2) return ;
        }
    }
    {
        if (arg2) strncpy(arg1->deviceName,arg2,64);
        else arg1->deviceName[0] = 0;
    }
    
    {
        if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, arg2); 
    }
}


JNIEXPORT jstring JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1deviceName(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jstring jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    char *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (char *)(char *) ((arg1)->deviceName);
    
    {
        if(result) jresult = (*jenv)->NewStringUTF(jenv, result); 
    }
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1numSensorConfigs(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    int arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (int)jarg2; 
    if (arg1) (arg1)->numSensorConfigs = arg2;
    
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1numSensorConfigs(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (int) ((arg1)->numSensorConfigs);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_set_1ExperimentConfig_1sensorConfigArray(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    SensorConfig *arg2 = (SensorConfig *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = *(SensorConfig **)&jarg2; 
    if (arg1) (arg1)->sensorConfigArray = arg2;
    
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1ExperimentConfig_1sensorConfigArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    SensorConfig *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    result = (SensorConfig *) ((arg1)->sensorConfigArray);
    
    *(SensorConfig **)&jresult = result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_ExperimentConfig_1getSensorConfig(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    jlong jresult = 0 ;
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    int arg2 ;
    SensorConfig *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (int)jarg2; 
    result = (SensorConfig *)ExperimentConfig_getSensorConfig(arg1,arg2);
    
    *(SensorConfig **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_ExperimentConfig_1createSensorConfigArray(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    int arg2 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = (int)jarg2; 
    ExperimentConfig_createSensorConfigArray(arg1,arg2);
    
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_ExperimentConfig_1setSensorConfig(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jint jarg3) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    SensorConfig *arg2 = (SensorConfig *) 0 ;
    int arg3 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    arg2 = *(SensorConfig **)&jarg2; 
    arg3 = (int)jarg3; 
    ExperimentConfig_setSensorConfig(arg1,arg2,arg3);
    
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_new_1ExperimentConfig(JNIEnv *jenv, jclass jcls) {
    jlong jresult = 0 ;
    ExperimentConfig *result;
    
    (void)jenv;
    (void)jcls;
    result = (ExperimentConfig *)(ExperimentConfig *) calloc(1, sizeof(ExperimentConfig));
    
    *(ExperimentConfig **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_delete_1ExperimentConfig(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(ExperimentConfig **)&jarg1; 
    free((char *) arg1);
    
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1UNKNOWN(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_UNKNOWN;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1TEMPERATURE(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_TEMPERATURE;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1TEMPERATURE_1WAND(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_TEMPERATURE_WAND;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1LIGHT(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_LIGHT;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1GAS_1PRESSURE(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_GAS_PRESSURE;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1VOLTAGE(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_VOLTAGE;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1FORCE(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_FORCE;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1VELOCITY(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_VELOCITY;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1RELATIVE_1HUMIDITY(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_RELATIVE_HUMIDITY;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1ACCELERATION(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_ACCELERATION;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1PULSE_1RATE(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_PULSE_RATE;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1CURRENT(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_CURRENT;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1POWER(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_POWER;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1ENERGY(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_ENERGY;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1DISTANCE(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_DISTANCE;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1SOUND_1INTENSITY(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_SOUND_INTENSITY;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1COMPASS(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_COMPASS;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1ANGULAR_1VELOCITY(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_ANGULAR_VELOCITY;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_get_1QUANTITY_1WIND_1SPEED(JNIEnv *jenv, jclass jcls) {
    jint jresult = 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    result = (int)QUANTITY_WIND_SPEED;
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1open(JNIEnv *jenv, jclass jcls, jstring jarg1) {
    jlong jresult = 0 ;
    char *arg1 ;
    SENSOR_DEVICE_HANDLE result;
    
    (void)jenv;
    (void)jcls;
    {
        arg1 = 0;
        if (jarg1) {
            arg1 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg1, 0);
            if (!arg1) return 0;
        }
    }
    result = (SENSOR_DEVICE_HANDLE)SensDev_open(arg1);
    
    *(SENSOR_DEVICE_HANDLE *)&jresult = result; 
    {
        if (arg1) (*jenv)->ReleaseStringUTFChars(jenv, jarg1, arg1); 
    }
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1close(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    result = (int)SensDev_close(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1isAttached(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    result = (int)SensDev_isAttached(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1configure(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    ExperimentConfig *arg2 = (ExperimentConfig *) 0 ;
    ExperimentConfig **arg3 = (ExperimentConfig **) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    arg2 = *(ExperimentConfig **)&jarg2; 
    arg3 = *(ExperimentConfig ***)&jarg3; 
    result = (int)SensDev_configure(arg1,arg2,arg3);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1canDetectSensors(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    result = (int)SensDev_canDetectSensors(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1getCurrentConfig(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    ExperimentConfig **arg2 = (ExperimentConfig **) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    arg2 = *(ExperimentConfig ***)&jarg2; 
    result = (int)SensDev_getCurrentConfig(arg1,arg2);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1start(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    result = (int)SensDev_start(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1stop(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    result = (int)SensDev_stop(arg1);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jint JNICALL Java_ccsd_ti_NativeBridgeJNI_SensDev_1read(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jint jarg4) {
    jint jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    float *arg2 = (float *) 0 ;
    float *arg3 = (float *) 0 ;
    int arg4 ;
    int result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    arg2 = *(float **)&jarg2; 
    arg3 = *(float **)&jarg3; 
    arg4 = (int)jarg4; 
    result = (int)SensDev_read(arg1,arg2,arg3,arg4);
    
    jresult = (jint)result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_getCurrentConfigHelper(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    jlong jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    ExperimentConfig *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    result = (ExperimentConfig *)getCurrentConfigHelper(arg1);
    
    *(ExperimentConfig **)&jresult = result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_configureHelper(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
    jlong jresult = 0 ;
    SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
    ExperimentConfig *arg2 = (ExperimentConfig *) 0 ;
    ExperimentConfig *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
    arg2 = *(ExperimentConfig **)&jarg2; 
    result = (ExperimentConfig *)configureHelper(arg1,arg2);
    
    *(ExperimentConfig **)&jresult = result; 
    return jresult;
}


JNIEXPORT jlong JNICALL Java_ccsd_ti_NativeBridgeJNI_new_1floatArray(JNIEnv *jenv, jclass jcls, jint jarg1) {
    jlong jresult = 0 ;
    int arg1 ;
    float *result;
    
    (void)jenv;
    (void)jcls;
    arg1 = (int)jarg1; 
    result = (float *)new_floatArray(arg1);
    
    *(float **)&jresult = result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_delete_1floatArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
    float *arg1 = (float *) 0 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(float **)&jarg1; 
    delete_floatArray(arg1);
    
}


JNIEXPORT jfloat JNICALL Java_ccsd_ti_NativeBridgeJNI_floatArray_1getitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
    jfloat jresult = 0 ;
    float *arg1 = (float *) 0 ;
    int arg2 ;
    float result;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(float **)&jarg1; 
    arg2 = (int)jarg2; 
    result = (float)floatArray_getitem(arg1,arg2);
    
    jresult = (jfloat)result; 
    return jresult;
}


JNIEXPORT void JNICALL Java_ccsd_ti_NativeBridgeJNI_floatArray_1setitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2, jfloat jarg3) {
    float *arg1 = (float *) 0 ;
    int arg2 ;
    float arg3 ;
    
    (void)jenv;
    (void)jcls;
    arg1 = *(float **)&jarg1; 
    arg2 = (int)jarg2; 
    arg3 = (float)jarg3; 
    floatArray_setitem(arg1,arg2,arg3);
    
}


#ifdef __cplusplus
}
#endif
