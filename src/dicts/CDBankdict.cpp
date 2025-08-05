// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdICDBankdict
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
#include "CDBank.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CDBank(void *p = nullptr);
   static void *newArray_CDBank(Long_t size, void *p);
   static void delete_CDBank(void *p);
   static void deleteArray_CDBank(void *p);
   static void destruct_CDBank(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CDBank*)
   {
      ::CDBank *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CDBank >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CDBank", ::CDBank::Class_Version(), "CDBank.hh", 16,
                  typeid(::CDBank), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CDBank::Dictionary, isa_proxy, 4,
                  sizeof(::CDBank) );
      instance.SetNew(&new_CDBank);
      instance.SetNewArray(&newArray_CDBank);
      instance.SetDelete(&delete_CDBank);
      instance.SetDeleteArray(&deleteArray_CDBank);
      instance.SetDestructor(&destruct_CDBank);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CDBank*)
   {
      return GenerateInitInstanceLocal((::CDBank*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CDBank*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr CDBank::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CDBank::Class_Name()
{
   return "CDBank";
}

//______________________________________________________________________________
const char *CDBank::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CDBank::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CDBank::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CDBank::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CDBank*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void CDBank::Streamer(TBuffer &R__b)
{
   // Stream an object of class CDBank.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CDBank::Class(),this);
   } else {
      R__b.WriteClassBuffer(CDBank::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_CDBank(void *p) {
      return  p ? new(p) ::CDBank : new ::CDBank;
   }
   static void *newArray_CDBank(Long_t nElements, void *p) {
      return p ? new(p) ::CDBank[nElements] : new ::CDBank[nElements];
   }
   // Wrapper around operator delete
   static void delete_CDBank(void *p) {
      delete ((::CDBank*)p);
   }
   static void deleteArray_CDBank(void *p) {
      delete [] ((::CDBank*)p);
   }
   static void destruct_CDBank(void *p) {
      typedef ::CDBank current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CDBank

namespace ROOT {
   static TClass *vectorlECDHitgR_Dictionary();
   static void vectorlECDHitgR_TClassManip(TClass*);
   static void *new_vectorlECDHitgR(void *p = nullptr);
   static void *newArray_vectorlECDHitgR(Long_t size, void *p);
   static void delete_vectorlECDHitgR(void *p);
   static void deleteArray_vectorlECDHitgR(void *p);
   static void destruct_vectorlECDHitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CDHit>*)
   {
      vector<CDHit> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CDHit>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CDHit>", -2, "vector", 389,
                  typeid(vector<CDHit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECDHitgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CDHit>) );
      instance.SetNew(&new_vectorlECDHitgR);
      instance.SetNewArray(&newArray_vectorlECDHitgR);
      instance.SetDelete(&delete_vectorlECDHitgR);
      instance.SetDeleteArray(&deleteArray_vectorlECDHitgR);
      instance.SetDestructor(&destruct_vectorlECDHitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CDHit> >()));

      ::ROOT::AddClassAlternate("vector<CDHit>","std::vector<CDHit, std::allocator<CDHit> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<CDHit>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECDHitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<CDHit>*)nullptr)->GetClass();
      vectorlECDHitgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECDHitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECDHitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<CDHit> : new vector<CDHit>;
   }
   static void *newArray_vectorlECDHitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<CDHit>[nElements] : new vector<CDHit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECDHitgR(void *p) {
      delete ((vector<CDHit>*)p);
   }
   static void deleteArray_vectorlECDHitgR(void *p) {
      delete [] ((vector<CDHit>*)p);
   }
   static void destruct_vectorlECDHitgR(void *p) {
      typedef vector<CDHit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<CDHit>

namespace {
  void TriggerDictionaryInitialization_CDBankdict_Impl() {
    static const char* headers[] = {
"CDBank.hh",
nullptr
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/redhat-9-x86_64/snsw/opt2/root-6.26.06/include/root",
"/sps/nemo/scratch/ykozina/Falaise/tutorial/SNCuts/include/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "CDBankdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$CDBank.hh")))  CDBank;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "CDBankdict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "CDBank.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CDBank", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("CDBankdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_CDBankdict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_CDBankdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_CDBankdict() {
  TriggerDictionaryInitialization_CDBankdict_Impl();
}
