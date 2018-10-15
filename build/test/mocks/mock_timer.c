/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_timer.h"

static const char* CMockString_period = "period";
static const char* CMockString_timerId = "timerId";
static const char* CMockString_timerInit = "timerInit";
static const char* CMockString_timerStart = "timerStart";
static const char* CMockString_timerStop = "timerStop";

typedef struct _CMOCK_timerInit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;
  int CallOrder;
  uint16_t Expected_period;
  uint8_t* Expected_timerId;
  int ReturnThruPtr_timerId_Used;
  uint8_t* ReturnThruPtr_timerId_Val;
  int ReturnThruPtr_timerId_Size;
  int IgnoreArg_period;
  int IgnoreArg_timerId;

} CMOCK_timerInit_CALL_INSTANCE;

typedef struct _CMOCK_timerStart_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;
  int CallOrder;
  uint8_t Expected_timerId;
  int IgnoreArg_timerId;

} CMOCK_timerStart_CALL_INSTANCE;

typedef struct _CMOCK_timerStop_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;
  int CallOrder;
  uint8_t Expected_timerId;
  int IgnoreArg_timerId;

} CMOCK_timerStop_CALL_INSTANCE;

static struct mock_timerInstance
{
  int timerInit_IgnoreBool;
  uint8_t timerInit_FinalReturn;
  CMOCK_timerInit_CALLBACK timerInit_CallbackFunctionPointer;
  int timerInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE timerInit_CallInstance;
  int timerStart_IgnoreBool;
  uint8_t timerStart_FinalReturn;
  CMOCK_timerStart_CALLBACK timerStart_CallbackFunctionPointer;
  int timerStart_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE timerStart_CallInstance;
  int timerStop_IgnoreBool;
  uint8_t timerStop_FinalReturn;
  CMOCK_timerStop_CALLBACK timerStop_CallbackFunctionPointer;
  int timerStop_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE timerStop_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_timer_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.timerInit_IgnoreBool)
    Mock.timerInit_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_timerInit);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.timerInit_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.timerInit_CallbackFunctionPointer != NULL)
    Mock.timerInit_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.timerStart_IgnoreBool)
    Mock.timerStart_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_timerStart);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.timerStart_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.timerStart_CallbackFunctionPointer != NULL)
    Mock.timerStart_CallInstance = CMOCK_GUTS_NONE;
  if (Mock.timerStop_IgnoreBool)
    Mock.timerStop_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_timerStop);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.timerStop_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.timerStop_CallbackFunctionPointer != NULL)
    Mock.timerStop_CallInstance = CMOCK_GUTS_NONE;
}

void mock_timer_Init(void)
{
  mock_timer_Destroy();
}

void mock_timer_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.timerInit_CallbackFunctionPointer = NULL;
  Mock.timerInit_CallbackCalls = 0;
  Mock.timerStart_CallbackFunctionPointer = NULL;
  Mock.timerStart_CallbackCalls = 0;
  Mock.timerStop_CallbackFunctionPointer = NULL;
  Mock.timerStop_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint8_t timerInit(uint16_t period, uint8_t* timerId)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_timerInit);
  cmock_call_instance = (CMOCK_timerInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.timerInit_CallInstance);
  Mock.timerInit_CallInstance = CMock_Guts_MemNext(Mock.timerInit_CallInstance);
  if (Mock.timerInit_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.timerInit_FinalReturn;
    Mock.timerInit_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.timerInit_CallbackFunctionPointer != NULL)
  {
    return Mock.timerInit_CallbackFunctionPointer(period, timerId, Mock.timerInit_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_period)
  {
    UNITY_SET_DETAILS(CMockString_timerInit,CMockString_period);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_period, period, cmock_line, CMockStringMismatch);
  }
  if (!cmock_call_instance->IgnoreArg_timerId)
  {
    UNITY_SET_DETAILS(CMockString_timerInit,CMockString_timerId);
    if (cmock_call_instance->Expected_timerId == NULL)
      { UNITY_TEST_ASSERT_NULL(timerId, cmock_line, CMockStringExpNULL); }
    else
      { UNITY_TEST_ASSERT_EQUAL_HEX8_ARRAY(cmock_call_instance->Expected_timerId, timerId, 1, cmock_line, CMockStringMismatch); }
  }
  if (cmock_call_instance->ReturnThruPtr_timerId_Used)
  {
    UNITY_TEST_ASSERT_NOT_NULL(timerId, cmock_line, CMockStringPtrIsNULL);
    memcpy((void*)timerId, (void*)cmock_call_instance->ReturnThruPtr_timerId_Val,
      cmock_call_instance->ReturnThruPtr_timerId_Size);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_timerInit(CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance, uint16_t period, uint8_t* timerId)
{
  cmock_call_instance->Expected_period = period;
  cmock_call_instance->IgnoreArg_period = 0;
  cmock_call_instance->Expected_timerId = timerId;
  cmock_call_instance->IgnoreArg_timerId = 0;
  cmock_call_instance->ReturnThruPtr_timerId_Used = 0;
}

void timerInit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_timerInit_CALL_INSTANCE));
  CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.timerInit_CallInstance = CMock_Guts_MemChain(Mock.timerInit_CallInstance, cmock_guts_index);
  Mock.timerInit_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.timerInit_IgnoreBool = (int)1;
}

void timerInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint16_t period, uint8_t* timerId, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_timerInit_CALL_INSTANCE));
  CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.timerInit_CallInstance = CMock_Guts_MemChain(Mock.timerInit_CallInstance, cmock_guts_index);
  Mock.timerInit_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_timerInit(cmock_call_instance, period, timerId);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void timerInit_StubWithCallback(CMOCK_timerInit_CALLBACK Callback)
{
  Mock.timerInit_IgnoreBool = (int)0;
  Mock.timerInit_CallbackFunctionPointer = Callback;
}

void timerInit_CMockReturnMemThruPtr_timerId(UNITY_LINE_TYPE cmock_line, uint8_t* timerId, int cmock_size)
{
  CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.timerInit_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringPtrPreExp);
  cmock_call_instance->ReturnThruPtr_timerId_Used = 1;
  cmock_call_instance->ReturnThruPtr_timerId_Val = timerId;
  cmock_call_instance->ReturnThruPtr_timerId_Size = cmock_size;
}

void timerInit_CMockIgnoreArg_period(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.timerInit_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_period = 1;
}

void timerInit_CMockIgnoreArg_timerId(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_timerInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.timerInit_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_timerId = 1;
}

uint8_t timerStart(uint8_t timerId)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_timerStart_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_timerStart);
  cmock_call_instance = (CMOCK_timerStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.timerStart_CallInstance);
  Mock.timerStart_CallInstance = CMock_Guts_MemNext(Mock.timerStart_CallInstance);
  if (Mock.timerStart_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.timerStart_FinalReturn;
    Mock.timerStart_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.timerStart_CallbackFunctionPointer != NULL)
  {
    return Mock.timerStart_CallbackFunctionPointer(timerId, Mock.timerStart_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_timerId)
  {
    UNITY_SET_DETAILS(CMockString_timerStart,CMockString_timerId);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_timerId, timerId, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_timerStart(CMOCK_timerStart_CALL_INSTANCE* cmock_call_instance, uint8_t timerId)
{
  cmock_call_instance->Expected_timerId = timerId;
  cmock_call_instance->IgnoreArg_timerId = 0;
}

void timerStart_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_timerStart_CALL_INSTANCE));
  CMOCK_timerStart_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.timerStart_CallInstance = CMock_Guts_MemChain(Mock.timerStart_CallInstance, cmock_guts_index);
  Mock.timerStart_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.timerStart_IgnoreBool = (int)1;
}

void timerStart_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t timerId, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_timerStart_CALL_INSTANCE));
  CMOCK_timerStart_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.timerStart_CallInstance = CMock_Guts_MemChain(Mock.timerStart_CallInstance, cmock_guts_index);
  Mock.timerStart_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_timerStart(cmock_call_instance, timerId);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void timerStart_StubWithCallback(CMOCK_timerStart_CALLBACK Callback)
{
  Mock.timerStart_IgnoreBool = (int)0;
  Mock.timerStart_CallbackFunctionPointer = Callback;
}

void timerStart_CMockIgnoreArg_timerId(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_timerStart_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerStart_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.timerStart_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_timerId = 1;
}

uint8_t timerStop(uint8_t timerId)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_timerStop_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_timerStop);
  cmock_call_instance = (CMOCK_timerStop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.timerStop_CallInstance);
  Mock.timerStop_CallInstance = CMock_Guts_MemNext(Mock.timerStop_CallInstance);
  if (Mock.timerStop_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.timerStop_FinalReturn;
    Mock.timerStop_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.timerStop_CallbackFunctionPointer != NULL)
  {
    return Mock.timerStop_CallbackFunctionPointer(timerId, Mock.timerStop_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_timerId)
  {
    UNITY_SET_DETAILS(CMockString_timerStop,CMockString_timerId);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_timerId, timerId, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_timerStop(CMOCK_timerStop_CALL_INSTANCE* cmock_call_instance, uint8_t timerId)
{
  cmock_call_instance->Expected_timerId = timerId;
  cmock_call_instance->IgnoreArg_timerId = 0;
}

void timerStop_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_timerStop_CALL_INSTANCE));
  CMOCK_timerStop_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerStop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.timerStop_CallInstance = CMock_Guts_MemChain(Mock.timerStop_CallInstance, cmock_guts_index);
  Mock.timerStop_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.timerStop_IgnoreBool = (int)1;
}

void timerStop_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t timerId, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_timerStop_CALL_INSTANCE));
  CMOCK_timerStop_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerStop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.timerStop_CallInstance = CMock_Guts_MemChain(Mock.timerStop_CallInstance, cmock_guts_index);
  Mock.timerStop_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_timerStop(cmock_call_instance, timerId);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void timerStop_StubWithCallback(CMOCK_timerStop_CALLBACK Callback)
{
  Mock.timerStop_IgnoreBool = (int)0;
  Mock.timerStop_CallbackFunctionPointer = Callback;
}

void timerStop_CMockIgnoreArg_timerId(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_timerStop_CALL_INSTANCE* cmock_call_instance = (CMOCK_timerStop_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.timerStop_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_timerId = 1;
}

