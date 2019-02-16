// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGChit

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

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "inc/HGChit.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HGChit(void *p = 0);
   static void *newArray_HGChit(Long_t size, void *p);
   static void delete_HGChit(void *p);
   static void deleteArray_HGChit(void *p);
   static void destruct_HGChit(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGChit*)
   {
      ::HGChit *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGChit >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGChit", ::HGChit::Class_Version(), "inc/HGChit.h", 23,
                  typeid(::HGChit), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGChit::Dictionary, isa_proxy, 4,
                  sizeof(::HGChit) );
      instance.SetNew(&new_HGChit);
      instance.SetNewArray(&newArray_HGChit);
      instance.SetDelete(&delete_HGChit);
      instance.SetDeleteArray(&deleteArray_HGChit);
      instance.SetDestructor(&destruct_HGChit);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGChit*)
   {
      return GenerateInitInstanceLocal((::HGChit*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGChit*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGChit::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGChit::Class_Name()
{
   return "HGChit";
}

//______________________________________________________________________________
const char *HGChit::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGChit*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGChit::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGChit*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGChit::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGChit*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGChit::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGChit*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGChit::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGChit.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGChit::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGChit::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HGChit(void *p) {
      return  p ? new(p) ::HGChit : new ::HGChit;
   }
   static void *newArray_HGChit(Long_t nElements, void *p) {
      return p ? new(p) ::HGChit[nElements] : new ::HGChit[nElements];
   }
   // Wrapper around operator delete
   static void delete_HGChit(void *p) {
      delete ((::HGChit*)p);
   }
   static void deleteArray_HGChit(void *p) {
      delete [] ((::HGChit*)p);
   }
   static void destruct_HGChit(void *p) {
      typedef ::HGChit current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGChit

namespace ROOT {
   static TClass *maplEunsignedsPintcOHGChitgR_Dictionary();
   static void maplEunsignedsPintcOHGChitgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGChitgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGChitgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGChitgR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGChitgR(void *p);
   static void destruct_maplEunsignedsPintcOHGChitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGChit>*)
   {
      map<unsigned int,HGChit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGChit>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGChit>", -2, "map", 805,
                  typeid(map<unsigned int,HGChit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGChitgR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,HGChit>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGChitgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGChitgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGChitgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGChitgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGChitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGChit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGChit>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGChitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGChit>*)0x0)->GetClass();
      maplEunsignedsPintcOHGChitgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGChitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGChitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGChit> : new map<unsigned int,HGChit>;
   }
   static void *newArray_maplEunsignedsPintcOHGChitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGChit>[nElements] : new map<unsigned int,HGChit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGChitgR(void *p) {
      delete ((map<unsigned int,HGChit>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGChitgR(void *p) {
      delete [] ((map<unsigned int,HGChit>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGChitgR(void *p) {
      typedef map<unsigned int,HGChit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGChit>

namespace ROOT {
   static TClass *maplEintcOHGChitgR_Dictionary();
   static void maplEintcOHGChitgR_TClassManip(TClass*);
   static void *new_maplEintcOHGChitgR(void *p = 0);
   static void *newArray_maplEintcOHGChitgR(Long_t size, void *p);
   static void delete_maplEintcOHGChitgR(void *p);
   static void deleteArray_maplEintcOHGChitgR(void *p);
   static void destruct_maplEintcOHGChitgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,HGChit>*)
   {
      map<int,HGChit> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,HGChit>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,HGChit>", -2, "map", 805,
                  typeid(map<int,HGChit>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOHGChitgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,HGChit>) );
      instance.SetNew(&new_maplEintcOHGChitgR);
      instance.SetNewArray(&newArray_maplEintcOHGChitgR);
      instance.SetDelete(&delete_maplEintcOHGChitgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOHGChitgR);
      instance.SetDestructor(&destruct_maplEintcOHGChitgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,HGChit> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<int,HGChit>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOHGChitgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,HGChit>*)0x0)->GetClass();
      maplEintcOHGChitgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOHGChitgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOHGChitgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGChit> : new map<int,HGChit>;
   }
   static void *newArray_maplEintcOHGChitgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGChit>[nElements] : new map<int,HGChit>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOHGChitgR(void *p) {
      delete ((map<int,HGChit>*)p);
   }
   static void deleteArray_maplEintcOHGChitgR(void *p) {
      delete [] ((map<int,HGChit>*)p);
   }
   static void destruct_maplEintcOHGChitgR(void *p) {
      typedef map<int,HGChit> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,HGChit>

namespace {
  void TriggerDictionaryInitialization_DictHGChit_Impl() {
    static const char* headers[] = {
"inc/HGChit.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/build/include",
"/Users/yoyo/Documents/Project/dev/HGC-CMSSW-ANLYSIS/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGChit dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$inc/HGChit.h")))  HGChit;
namespace std{inline namespace __1{template <class _Tp> struct __attribute__((annotate("$clingAutoload$__functional_base")))  __attribute__((annotate("$clingAutoload$string")))  less;
}}
namespace std{inline namespace __1{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$utility")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}}
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$memory")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGChit dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
#include "inc/HGChit.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGChit", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGChit",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGChit_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGChit_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGChit() {
  TriggerDictionaryInitialization_DictHGChit_Impl();
}
