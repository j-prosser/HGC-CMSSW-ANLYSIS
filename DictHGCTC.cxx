// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGCTC

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
#include "inc/HGCTC.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HGCTC(void *p = 0);
   static void *newArray_HGCTC(Long_t size, void *p);
   static void delete_HGCTC(void *p);
   static void deleteArray_HGCTC(void *p);
   static void destruct_HGCTC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGCTC*)
   {
      ::HGCTC *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGCTC >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGCTC", ::HGCTC::Class_Version(), "inc/HGCTC.h", 21,
                  typeid(::HGCTC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGCTC::Dictionary, isa_proxy, 4,
                  sizeof(::HGCTC) );
      instance.SetNew(&new_HGCTC);
      instance.SetNewArray(&newArray_HGCTC);
      instance.SetDelete(&delete_HGCTC);
      instance.SetDeleteArray(&deleteArray_HGCTC);
      instance.SetDestructor(&destruct_HGCTC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGCTC*)
   {
      return GenerateInitInstanceLocal((::HGCTC*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGCTC*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGCTC::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGCTC::Class_Name()
{
   return "HGCTC";
}

//______________________________________________________________________________
const char *HGCTC::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCTC*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGCTC::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCTC*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGCTC::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCTC*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGCTC::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCTC*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGCTC::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGCTC.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGCTC::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGCTC::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HGCTC(void *p) {
      return  p ? new(p) ::HGCTC : new ::HGCTC;
   }
   static void *newArray_HGCTC(Long_t nElements, void *p) {
      return p ? new(p) ::HGCTC[nElements] : new ::HGCTC[nElements];
   }
   // Wrapper around operator delete
   static void delete_HGCTC(void *p) {
      delete ((::HGCTC*)p);
   }
   static void deleteArray_HGCTC(void *p) {
      delete [] ((::HGCTC*)p);
   }
   static void destruct_HGCTC(void *p) {
      typedef ::HGCTC current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGCTC

namespace ROOT {
   static TClass *maplEunsignedsPintcOHGCTCgR_Dictionary();
   static void maplEunsignedsPintcOHGCTCgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGCTCgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGCTCgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGCTCgR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGCTCgR(void *p);
   static void destruct_maplEunsignedsPintcOHGCTCgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGCTC>*)
   {
      map<unsigned int,HGCTC> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGCTC>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGCTC>", -2, "map", 96,
                  typeid(map<unsigned int,HGCTC>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGCTCgR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,HGCTC>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGCTCgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGCTCgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGCTCgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGCTCgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGCTCgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGCTC> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGCTC>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGCTCgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGCTC>*)0x0)->GetClass();
      maplEunsignedsPintcOHGCTCgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGCTCgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGCTCgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCTC> : new map<unsigned int,HGCTC>;
   }
   static void *newArray_maplEunsignedsPintcOHGCTCgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCTC>[nElements] : new map<unsigned int,HGCTC>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGCTCgR(void *p) {
      delete ((map<unsigned int,HGCTC>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGCTCgR(void *p) {
      delete [] ((map<unsigned int,HGCTC>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGCTCgR(void *p) {
      typedef map<unsigned int,HGCTC> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGCTC>

namespace ROOT {
   static TClass *maplEintcOHGCTCgR_Dictionary();
   static void maplEintcOHGCTCgR_TClassManip(TClass*);
   static void *new_maplEintcOHGCTCgR(void *p = 0);
   static void *newArray_maplEintcOHGCTCgR(Long_t size, void *p);
   static void delete_maplEintcOHGCTCgR(void *p);
   static void deleteArray_maplEintcOHGCTCgR(void *p);
   static void destruct_maplEintcOHGCTCgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,HGCTC>*)
   {
      map<int,HGCTC> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,HGCTC>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,HGCTC>", -2, "map", 96,
                  typeid(map<int,HGCTC>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOHGCTCgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,HGCTC>) );
      instance.SetNew(&new_maplEintcOHGCTCgR);
      instance.SetNewArray(&newArray_maplEintcOHGCTCgR);
      instance.SetDelete(&delete_maplEintcOHGCTCgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOHGCTCgR);
      instance.SetDestructor(&destruct_maplEintcOHGCTCgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,HGCTC> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<int,HGCTC>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOHGCTCgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,HGCTC>*)0x0)->GetClass();
      maplEintcOHGCTCgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOHGCTCgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOHGCTCgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGCTC> : new map<int,HGCTC>;
   }
   static void *newArray_maplEintcOHGCTCgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGCTC>[nElements] : new map<int,HGCTC>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOHGCTCgR(void *p) {
      delete ((map<int,HGCTC>*)p);
   }
   static void deleteArray_maplEintcOHGCTCgR(void *p) {
      delete [] ((map<int,HGCTC>*)p);
   }
   static void destruct_maplEintcOHGCTCgR(void *p) {
      typedef map<int,HGCTC> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,HGCTC>

namespace {
  void TriggerDictionaryInitialization_DictHGCTC_Impl() {
    static const char* headers[] = {
"inc/HGCTC.h",
0
    };
    static const char* includePaths[] = {
"/home/johannes/root/include",
"/home/johannes/HCA/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGCTC dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$inc/HGCTC.h")))  HGCTC;
namespace std{template <typename _Tp> struct __attribute__((annotate("$clingAutoload$bits/stl_function.h")))  __attribute__((annotate("$clingAutoload$string")))  less;
}
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGCTC dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "inc/HGCTC.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGCTC", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGCTC",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGCTC_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGCTC_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGCTC() {
  TriggerDictionaryInitialization_DictHGCTC_Impl();
}
