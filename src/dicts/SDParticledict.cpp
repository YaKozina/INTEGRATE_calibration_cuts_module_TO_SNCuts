// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdISDParticledict
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
#include "SDParticle.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_SDParticle(void *p = nullptr);
   static void *newArray_SDParticle(Long_t size, void *p);
   static void delete_SDParticle(void *p);
   static void deleteArray_SDParticle(void *p);
   static void destruct_SDParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SDParticle*)
   {
      ::SDParticle *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SDParticle >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("SDParticle", ::SDParticle::Class_Version(), "SDParticle.hh", 14,
                  typeid(::SDParticle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SDParticle::Dictionary, isa_proxy, 4,
                  sizeof(::SDParticle) );
      instance.SetNew(&new_SDParticle);
      instance.SetNewArray(&newArray_SDParticle);
      instance.SetDelete(&delete_SDParticle);
      instance.SetDeleteArray(&deleteArray_SDParticle);
      instance.SetDestructor(&destruct_SDParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SDParticle*)
   {
      return GenerateInitInstanceLocal((::SDParticle*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SDParticle*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr SDParticle::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SDParticle::Class_Name()
{
   return "SDParticle";
}

//______________________________________________________________________________
const char *SDParticle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SDParticle*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SDParticle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SDParticle*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SDParticle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SDParticle*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SDParticle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SDParticle*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void SDParticle::Streamer(TBuffer &R__b)
{
   // Stream an object of class SDParticle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SDParticle::Class(),this);
   } else {
      R__b.WriteClassBuffer(SDParticle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SDParticle(void *p) {
      return  p ? new(p) ::SDParticle : new ::SDParticle;
   }
   static void *newArray_SDParticle(Long_t nElements, void *p) {
      return p ? new(p) ::SDParticle[nElements] : new ::SDParticle[nElements];
   }
   // Wrapper around operator delete
   static void delete_SDParticle(void *p) {
      delete ((::SDParticle*)p);
   }
   static void deleteArray_SDParticle(void *p) {
      delete [] ((::SDParticle*)p);
   }
   static void destruct_SDParticle(void *p) {
      typedef ::SDParticle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SDParticle

namespace {
  void TriggerDictionaryInitialization_SDParticledict_Impl() {
    static const char* headers[] = {
"SDParticle.hh",
nullptr
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/redhat-9-x86_64/snsw/opt2/root-6.26.06/include/root",
"/sps/nemo/scratch/ykozina/Falaise/tutorial/SNCuts/include/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SDParticledict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$SDParticle.hh")))  SDParticle;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SDParticledict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SDParticle.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"SDParticle", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SDParticledict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SDParticledict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SDParticledict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SDParticledict() {
  TriggerDictionaryInitialization_SDParticledict_Impl();
}
