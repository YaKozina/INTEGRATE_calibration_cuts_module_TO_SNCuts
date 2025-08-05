// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dOdOdIlibdIEventdict
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
#include "Event.hh"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_Event(void *p = nullptr);
   static void *newArray_Event(Long_t size, void *p);
   static void delete_Event(void *p);
   static void deleteArray_Event(void *p);
   static void destruct_Event(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Event*)
   {
      ::Event *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Event >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Event", ::Event::Class_Version(), "Event.hh", 20,
                  typeid(::Event), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Event::Dictionary, isa_proxy, 4,
                  sizeof(::Event) );
      instance.SetNew(&new_Event);
      instance.SetNewArray(&newArray_Event);
      instance.SetDelete(&delete_Event);
      instance.SetDeleteArray(&deleteArray_Event);
      instance.SetDestructor(&destruct_Event);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Event*)
   {
      return GenerateInitInstanceLocal((::Event*)nullptr);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Event*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Event::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Event::Class_Name()
{
   return "Event";
}

//______________________________________________________________________________
const char *Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Event*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Event*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Event*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Event::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Event*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class Event.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Event::Class(),this);
   } else {
      R__b.WriteClassBuffer(Event::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Event(void *p) {
      return  p ? new(p) ::Event : new ::Event;
   }
   static void *newArray_Event(Long_t nElements, void *p) {
      return p ? new(p) ::Event[nElements] : new ::Event[nElements];
   }
   // Wrapper around operator delete
   static void delete_Event(void *p) {
      delete ((::Event*)p);
   }
   static void deleteArray_Event(void *p) {
      delete [] ((::Event*)p);
   }
   static void destruct_Event(void *p) {
      typedef ::Event current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Event

namespace ROOT {
   static TClass *vectorlESDParticlegR_Dictionary();
   static void vectorlESDParticlegR_TClassManip(TClass*);
   static void *new_vectorlESDParticlegR(void *p = nullptr);
   static void *newArray_vectorlESDParticlegR(Long_t size, void *p);
   static void delete_vectorlESDParticlegR(void *p);
   static void deleteArray_vectorlESDParticlegR(void *p);
   static void destruct_vectorlESDParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<SDParticle>*)
   {
      vector<SDParticle> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<SDParticle>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<SDParticle>", -2, "vector", 389,
                  typeid(vector<SDParticle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlESDParticlegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<SDParticle>) );
      instance.SetNew(&new_vectorlESDParticlegR);
      instance.SetNewArray(&newArray_vectorlESDParticlegR);
      instance.SetDelete(&delete_vectorlESDParticlegR);
      instance.SetDeleteArray(&deleteArray_vectorlESDParticlegR);
      instance.SetDestructor(&destruct_vectorlESDParticlegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<SDParticle> >()));

      ::ROOT::AddClassAlternate("vector<SDParticle>","std::vector<SDParticle, std::allocator<SDParticle> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<SDParticle>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlESDParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<SDParticle>*)nullptr)->GetClass();
      vectorlESDParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlESDParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlESDParticlegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<SDParticle> : new vector<SDParticle>;
   }
   static void *newArray_vectorlESDParticlegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<SDParticle>[nElements] : new vector<SDParticle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlESDParticlegR(void *p) {
      delete ((vector<SDParticle>*)p);
   }
   static void deleteArray_vectorlESDParticlegR(void *p) {
      delete [] ((vector<SDParticle>*)p);
   }
   static void destruct_vectorlESDParticlegR(void *p) {
      typedef vector<SDParticle> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<SDParticle>

namespace ROOT {
   static TClass *vectorlEPTDParticlegR_Dictionary();
   static void vectorlEPTDParticlegR_TClassManip(TClass*);
   static void *new_vectorlEPTDParticlegR(void *p = nullptr);
   static void *newArray_vectorlEPTDParticlegR(Long_t size, void *p);
   static void delete_vectorlEPTDParticlegR(void *p);
   static void deleteArray_vectorlEPTDParticlegR(void *p);
   static void destruct_vectorlEPTDParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<PTDParticle>*)
   {
      vector<PTDParticle> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<PTDParticle>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<PTDParticle>", -2, "vector", 389,
                  typeid(vector<PTDParticle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEPTDParticlegR_Dictionary, isa_proxy, 0,
                  sizeof(vector<PTDParticle>) );
      instance.SetNew(&new_vectorlEPTDParticlegR);
      instance.SetNewArray(&newArray_vectorlEPTDParticlegR);
      instance.SetDelete(&delete_vectorlEPTDParticlegR);
      instance.SetDeleteArray(&deleteArray_vectorlEPTDParticlegR);
      instance.SetDestructor(&destruct_vectorlEPTDParticlegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<PTDParticle> >()));

      ::ROOT::AddClassAlternate("vector<PTDParticle>","std::vector<PTDParticle, std::allocator<PTDParticle> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<PTDParticle>*)nullptr); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEPTDParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<PTDParticle>*)nullptr)->GetClass();
      vectorlEPTDParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEPTDParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEPTDParticlegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PTDParticle> : new vector<PTDParticle>;
   }
   static void *newArray_vectorlEPTDParticlegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<PTDParticle>[nElements] : new vector<PTDParticle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEPTDParticlegR(void *p) {
      delete ((vector<PTDParticle>*)p);
   }
   static void deleteArray_vectorlEPTDParticlegR(void *p) {
      delete [] ((vector<PTDParticle>*)p);
   }
   static void destruct_vectorlEPTDParticlegR(void *p) {
      typedef vector<PTDParticle> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<PTDParticle>

namespace {
  void TriggerDictionaryInitialization_Eventdict_Impl() {
    static const char* headers[] = {
"Event.hh",
nullptr
    };
    static const char* includePaths[] = {
"/sps/nemo/sw/redhat-9-x86_64/snsw/opt2/root-6.26.06/include/root",
"/sps/nemo/scratch/ykozina/Falaise/tutorial/SNCuts/include/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Eventdict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$Event.hh")))  Event;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Eventdict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Event.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Event", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Eventdict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Eventdict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Eventdict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Eventdict() {
  TriggerDictionaryInitialization_Eventdict_Impl();
}
