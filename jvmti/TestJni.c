#include <jvmti.h>
#include <string.h>

jvmtiEnv *jvmti;
jvmtiCapabilities capa;
jvmtiError error;

void JNICALL
callbackMethodEntry(jvmtiEnv *jvmti_env,
            JNIEnv* jni_env,
            jthread thread,
            jmethodID method)
{
  jthread* thread_ptr;
  jvmtiThreadInfo info_ptr;
  printf(" MethodEntry - Inside this method . \n");
  error = (*jvmti_env)->GetCurrentThread(jvmti_env, &thread_ptr);
  
  if (error == JVMTI_ERROR_NONE) {
    printf(" MethodEntry - No error getting thread. \n");
    (*jvmti)->GetThreadInfo(jvmti_env, thread_ptr, &info_ptr);
    printf(" MethodEntry - thread info -> name: %s \n",info_ptr.name);    
  } else {
    printf(" MethodEntry - Error \n");
  }
}

JNIEXPORT jint JNICALL 
Agent_OnLoad(JavaVM *vm, char *options, void *reserved)
{  
  jvmtiEventCallbacks jvmtiEventCallbacks_;
  jint retGetEnv = (*vm)->GetEnv(vm, &jvmti, JVMTI_VERSION_1_1);
  printf(" executing Agent_OnLoad \n");
  printf("(*vm)->GetEnv value returned is: %d \n", retGetEnv);
  
  error = (*jvmti)->GetPotentialCapabilities(jvmti, &capa);
  if (error == JVMTI_ERROR_NONE) {
    if (capa.can_generate_method_entry_events) {
       printf(" OnLoad - capa.can_generate_method_entry_events: %d \n", capa.can_get_bytecodes);
    } else {
       printf(" OnLoad - capa.can_generate_method_entry_events: %d \n", capa.can_get_bytecodes);  
    }
  }
  
  (void)memset(&capa, 0, sizeof(jvmtiCapabilities));
  error = (*jvmti)->GetCapabilities(jvmti, &capa);
  if (error == JVMTI_ERROR_NONE) {
    printf(" capa.can_generate_method_entry_events: %d \n", capa.can_generate_method_entry_events);
    capa.can_generate_method_entry_events = 1;
    error = (*jvmti)->AddCapabilities(jvmti, &capa);
    if (error == JVMTI_ERROR_NONE) {
      printf(" after - capa.can_generate_method_entry_events: %d \n", capa.can_generate_method_entry_events);
    } else {
      printf("ERROR Adding capabilities \n");
    }
  }
  
  (void)memset(&jvmtiEventCallbacks_, 0, sizeof(jvmtiEventCallbacks));
  jvmtiEventCallbacks_.MethodEntry=callbackMethodEntry;
  error = (*jvmti)->SetEventCallbacks(jvmti, &jvmtiEventCallbacks_, sizeof(jvmtiEventCallbacks));
  if (error == JVMTI_ERROR_NONE) {
    printf("Set event callbacks successful! \n");
  } else {
    printf("ERROR setting event callbacks \n");
  }
    
  
  error = (*jvmti)->SetEventNotificationMode(jvmti, JVMTI_ENABLE, JVMTI_EVENT_METHOD_ENTRY, NULL);
  if (error == JVMTI_ERROR_NONE) {
    printf("Set event notification mode successfully achieved \n");
  } else {
    printf("ERROR setting event notification mode \n");
  }
    
  return JNI_OK; 
}


JNIEXPORT void JNICALL Java_TestJni_printMsg
  (JNIEnv *vm, jclass clazz)
{
  jthread* thread_ptr;
  jvmtiThreadInfo info_ptr;
  error = (*jvmti)->GetCurrentThread(jvmti, &thread_ptr);
  
  if (error == JVMTI_ERROR_NONE) {
    printf(" No error getting thread. \n");
    (*jvmti)->GetThreadInfo(jvmti, thread_ptr, &info_ptr);
    printf("thread info -> name: %s \n",info_ptr.name);    
  } else {
    printf(" Error \n");
  }
}

JNIEXPORT void JNICALL 
Agent_OnUnload(JavaVM *vm)
{
  printf(" executing Agent_OnUnload \n");
}
