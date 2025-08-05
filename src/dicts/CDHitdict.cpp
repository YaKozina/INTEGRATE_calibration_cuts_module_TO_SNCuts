// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdICDHitdict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "CDHit.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CDHit(void *p = nullptr);
   static void *newArray_CDHit(Long_t size, void *p);
   static void delete_CDHit(void *p);
   static void deleteArray_CDHit(void *p);
   static void destruct_CDHit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CDHit*)
   {
      ::CDHit *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CDHit >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CDHit", ::CDHit::Class_Version(), "CDHit.hh", 14,
                  typeid(::CDHit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CDHit::Dictionary, isa_proxy, 4,
                  sizeof(::CDHit) );
      instance.SetNew(&new_CDHit);
      instance.SetNewArray(&newArray_CDHit);
      instance.SetDelete(&delete_CDHit);
      instance.SetDeleteArray(&deleteArray_CDHit);
      instance.SetDestructor(&destruct_CDHit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CDHit*)
   {
      return GenerateInitInstanceLocal((::CDHit*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CDHit*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr CDHit::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CDHit::Class_Name()
{
   return "CDHit";
}

//______________________________________________________________________________
const char *CDHit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CDHit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CDHit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CDHit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDHit*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void CDHit::Streamer(TBuffer &R__b)
{
   // Stream an object of class CDHit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CDHit::Class(),this);
   } else {
      R__b.WriteClassBuffer(CDHit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_CDHit(void *p) {
      return  p ? new(p) ::CDHit : new ::CDHit;
   }
   static void *newArray_CDHit(Long_t nElements, void *p) {
      return p ? new(p) ::CDHit[nElements] : new ::CDHit[nElements];
   }
   // Wrapper around operator delete
   static void delete_CDHit(void *p) {
      delete ((::CDHit*)p);
   }
   static void deleteArray_CDHit(void *p) {
      delete [] ((::CDHit*)p);
   }
   static void destruct_CDHit(void *p) {
      typedef ::CDHit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CDHit

namespace {
  void TriggerDictionaryInitialization_CDHitdict_Impl() {
    static const char* headers[] = {
"CDHit.hh",
nullptr
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/redhat-9-x86_64/snsw/opt2/root-6.26.06/include/root",
"/sps/nemo/scratch/ykozina/Falaise/tutorial/SNCuts/include/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CDHitdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$CDHit.hh")))  CDHit;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CDHitdict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "CDHit.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CDHit", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CDHitdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CDHitdict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CDHitdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CDHitdict() {
  TriggerDictionaryInitialization_CDHitdict_Impl();
}
