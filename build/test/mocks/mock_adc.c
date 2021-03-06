/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "unity.h"
#include "cmock.h"
#include "mock_adc.h"

static const char* CMockString_adcId = "adcId";
static const char* CMockString_adcInit = "adcInit";

typedef struct _CMOCK_adcInit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  uint8_t ReturnVal;
  int CallOrder;
  uint8_t Expected_adcId;
  int IgnoreArg_adcId;

} CMOCK_adcInit_CALL_INSTANCE;

static struct mock_adcInstance
{
  int adcInit_IgnoreBool;
  uint8_t adcInit_FinalReturn;
  CMOCK_adcInit_CALLBACK adcInit_CallbackFunctionPointer;
  int adcInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE adcInit_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_adc_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  if (Mock.adcInit_IgnoreBool)
    Mock.adcInit_CallInstance = CMOCK_GUTS_NONE;
  UNITY_SET_DETAIL(CMockString_adcInit);
  UNITY_TEST_ASSERT(CMOCK_GUTS_NONE == Mock.adcInit_CallInstance, cmock_line, CMockStringCalledLess);
  if (Mock.adcInit_CallbackFunctionPointer != NULL)
    Mock.adcInit_CallInstance = CMOCK_GUTS_NONE;
}

void mock_adc_Init(void)
{
  mock_adc_Destroy();
}

void mock_adc_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  Mock.adcInit_CallbackFunctionPointer = NULL;
  Mock.adcInit_CallbackCalls = 0;
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

uint8_t adcInit(uint8_t adcId)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_adcInit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_adcInit);
  cmock_call_instance = (CMOCK_adcInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.adcInit_CallInstance);
  Mock.adcInit_CallInstance = CMock_Guts_MemNext(Mock.adcInit_CallInstance);
  if (Mock.adcInit_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.adcInit_FinalReturn;
    Mock.adcInit_FinalReturn = cmock_call_instance->ReturnVal;
    return cmock_call_instance->ReturnVal;
  }
  if (Mock.adcInit_CallbackFunctionPointer != NULL)
  {
    return Mock.adcInit_CallbackFunctionPointer(adcId, Mock.adcInit_CallbackCalls++);
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (!cmock_call_instance->IgnoreArg_adcId)
  {
    UNITY_SET_DETAILS(CMockString_adcInit,CMockString_adcId);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_adcId, adcId, cmock_line, CMockStringMismatch);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_adcInit(CMOCK_adcInit_CALL_INSTANCE* cmock_call_instance, uint8_t adcId)
{
  cmock_call_instance->Expected_adcId = adcId;
  cmock_call_instance->IgnoreArg_adcId = 0;
}

void adcInit_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_adcInit_CALL_INSTANCE));
  CMOCK_adcInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_adcInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.adcInit_CallInstance = CMock_Guts_MemChain(Mock.adcInit_CallInstance, cmock_guts_index);
  Mock.adcInit_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.adcInit_IgnoreBool = (int)1;
}

void adcInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t adcId, uint8_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_adcInit_CALL_INSTANCE));
  CMOCK_adcInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_adcInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.adcInit_CallInstance = CMock_Guts_MemChain(Mock.adcInit_CallInstance, cmock_guts_index);
  Mock.adcInit_IgnoreBool = (int)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_adcInit(cmock_call_instance, adcId);
  cmock_call_instance->ReturnVal = cmock_to_return;
  UNITY_CLR_DETAILS();
}

void adcInit_StubWithCallback(CMOCK_adcInit_CALLBACK Callback)
{
  Mock.adcInit_IgnoreBool = (int)0;
  Mock.adcInit_CallbackFunctionPointer = Callback;
}

void adcInit_CMockIgnoreArg_adcId(UNITY_LINE_TYPE cmock_line)
{
  CMOCK_adcInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_adcInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(CMock_Guts_MemEndOfChain(Mock.adcInit_CallInstance));
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringIgnPreExp);
  cmock_call_instance->IgnoreArg_adcId = 1;
}

