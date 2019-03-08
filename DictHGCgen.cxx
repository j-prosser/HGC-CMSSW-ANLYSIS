// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGCgen

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
#include "inc/HGCgen.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HGCgen(void *p = 0);
   static void *newArray_HGCgen(Long_t size, void *p);
   static void delete_HGCgen(void *p);
   static void deleteArray_HGCgen(void *p);
   static void destruct_HGCgen(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGCgen*)
   {
      ::HGCgen *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGCgen >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGCgen", ::HGCgen::Class_Version(), "inc/HGCgen.h", 25,
                  typeid(::HGCgen), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGCgen::Dictionary, isa_proxy, 4,
                  sizeof(::HGCgen) );
      instance.SetNew(&new_HGCgen);
      instance.SetNewArray(&newArray_HGCgen);
      instance.SetDelete(&delete_HGCgen);
      instance.SetDeleteArray(&deleteArray_HGCgen);
      instance.SetDestructor(&destruct_HGCgen);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGCgen*)
   {
      return GenerateInitInstanceLocal((::HGCgen*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGCgen*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGCgen::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGCgen::Class_Name()
{
   return "HGCgen";
}

//______________________________________________________________________________
const char *HGCgen::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCgen*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGCgen::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCgen*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGCgen::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCgen*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGCgen::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCgen*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGCgen::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGCgen.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGCgen::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGCgen::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HGCgen(void *p) {
      return  p ? new(p) ::HGCgen : new ::HGCgen;
   }
   static void *newArray_HGCgen(Long_t nElements, void *p) {
      return p ? new(p) ::HGCgen[nElements] : new ::HGCgen[nElements];
   }
   // Wrapper around operator delete
   static void delete_HGCgen(void *p) {
      delete ((::HGCgen*)p);
   }
   static void deleteArray_HGCgen(void *p) {
      delete [] ((::HGCgen*)p);
   }
   static void destruct_HGCgen(void *p) {
      typedef ::HGCgen current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGCgen

namespace ROOT {
   static TClass *vectorlEHGCgengR_Dictionary();
   static void vectorlEHGCgengR_TClassManip(TClass*);
   static void *new_vectorlEHGCgengR(void *p = 0);
   static void *newArray_vectorlEHGCgengR(Long_t size, void *p);
   static void delete_vectorlEHGCgengR(void *p);
   static void deleteArray_vectorlEHGCgengR(void *p);
   static void destruct_vectorlEHGCgengR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCgen>*)
   {
      vector<HGCgen> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCgen>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCgen>", -2, "vector", 447,
                  typeid(vector<HGCgen>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCgengR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HGCgen>) );
      instance.SetNew(&new_vectorlEHGCgengR);
      instance.SetNewArray(&newArray_vectorlEHGCgengR);
      instance.SetDelete(&delete_vectorlEHGCgengR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCgengR);
      instance.SetDestructor(&destruct_vectorlEHGCgengR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCgen> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCgen>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCgengR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCgen>*)0x0)->GetClass();
      vectorlEHGCgengR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCgengR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCgengR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgen> : new vector<HGCgen>;
   }
   static void *newArray_vectorlEHGCgengR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgen>[nElements] : new vector<HGCgen>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCgengR(void *p) {
      delete ((vector<HGCgen>*)p);
   }
   static void deleteArray_vectorlEHGCgengR(void *p) {
      delete [] ((vector<HGCgen>*)p);
   }
   static void destruct_vectorlEHGCgengR(void *p) {
      typedef vector<HGCgen> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCgen>

namespace ROOT {
   static TClass *vectorlEHGCgenmUgR_Dictionary();
   static void vectorlEHGCgenmUgR_TClassManip(TClass*);
   static void *new_vectorlEHGCgenmUgR(void *p = 0);
   static void *newArray_vectorlEHGCgenmUgR(Long_t size, void *p);
   static void delete_vectorlEHGCgenmUgR(void *p);
   static void deleteArray_vectorlEHGCgenmUgR(void *p);
   static void destruct_vectorlEHGCgenmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCgen*>*)
   {
      vector<HGCgen*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCgen*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCgen*>", -2, "vector", 447,
                  typeid(vector<HGCgen*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCgenmUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HGCgen*>) );
      instance.SetNew(&new_vectorlEHGCgenmUgR);
      instance.SetNewArray(&newArray_vectorlEHGCgenmUgR);
      instance.SetDelete(&delete_vectorlEHGCgenmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCgenmUgR);
      instance.SetDestructor(&destruct_vectorlEHGCgenmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCgen*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCgen*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCgenmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCgen*>*)0x0)->GetClass();
      vectorlEHGCgenmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCgenmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCgenmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgen*> : new vector<HGCgen*>;
   }
   static void *newArray_vectorlEHGCgenmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgen*>[nElements] : new vector<HGCgen*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCgenmUgR(void *p) {
      delete ((vector<HGCgen*>*)p);
   }
   static void deleteArray_vectorlEHGCgenmUgR(void *p) {
      delete [] ((vector<HGCgen*>*)p);
   }
   static void destruct_vectorlEHGCgenmUgR(void *p) {
      typedef vector<HGCgen*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCgen*>

namespace ROOT {
   static TClass *maplEunsignedsPintcOHGCgengR_Dictionary();
   static void maplEunsignedsPintcOHGCgengR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGCgengR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGCgengR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGCgengR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGCgengR(void *p);
   static void destruct_maplEunsignedsPintcOHGCgengR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGCgen>*)
   {
      map<unsigned int,HGCgen> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGCgen>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGCgen>", -2, "map", 805,
                  typeid(map<unsigned int,HGCgen>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGCgengR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,HGCgen>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGCgengR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGCgengR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGCgengR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGCgengR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGCgengR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGCgen> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGCgen>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGCgengR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGCgen>*)0x0)->GetClass();
      maplEunsignedsPintcOHGCgengR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGCgengR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGCgengR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCgen> : new map<unsigned int,HGCgen>;
   }
   static void *newArray_maplEunsignedsPintcOHGCgengR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCgen>[nElements] : new map<unsigned int,HGCgen>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGCgengR(void *p) {
      delete ((map<unsigned int,HGCgen>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGCgengR(void *p) {
      delete [] ((map<unsigned int,HGCgen>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGCgengR(void *p) {
      typedef map<unsigned int,HGCgen> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGCgen>

namespace ROOT {
   static TClass *maplEintcOHGCgengR_Dictionary();
   static void maplEintcOHGCgengR_TClassManip(TClass*);
   static void *new_maplEintcOHGCgengR(void *p = 0);
   static void *newArray_maplEintcOHGCgengR(Long_t size, void *p);
   static void delete_maplEintcOHGCgengR(void *p);
   static void deleteArray_maplEintcOHGCgengR(void *p);
   static void destruct_maplEintcOHGCgengR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,HGCgen>*)
   {
      map<int,HGCgen> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,HGCgen>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,HGCgen>", -2, "map", 805,
                  typeid(map<int,HGCgen>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOHGCgengR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,HGCgen>) );
      instance.SetNew(&new_maplEintcOHGCgengR);
      instance.SetNewArray(&newArray_maplEintcOHGCgengR);
      instance.SetDelete(&delete_maplEintcOHGCgengR);
      instance.SetDeleteArray(&deleteArray_maplEintcOHGCgengR);
      instance.SetDestructor(&destruct_maplEintcOHGCgengR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,HGCgen> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<int,HGCgen>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOHGCgengR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,HGCgen>*)0x0)->GetClass();
      maplEintcOHGCgengR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOHGCgengR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOHGCgengR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGCgen> : new map<int,HGCgen>;
   }
   static void *newArray_maplEintcOHGCgengR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGCgen>[nElements] : new map<int,HGCgen>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOHGCgengR(void *p) {
      delete ((map<int,HGCgen>*)p);
   }
   static void deleteArray_maplEintcOHGCgengR(void *p) {
      delete [] ((map<int,HGCgen>*)p);
   }
   static void destruct_maplEintcOHGCgengR(void *p) {
      typedef map<int,HGCgen> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,HGCgen>

namespace {
  void TriggerDictionaryInitialization_DictHGCgen_Impl() {
    static const char* headers[] = {
"inc/HGCgen.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/build/include",
"/Users/yoyo/Documents/Project/dev/HGC-CMSSW-ANLYSIS/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGCgen dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$inc/HGCgen.h")))  HGCgen;
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$iosfwd")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
namespace std{inline namespace __1{template <class _Tp> struct __attribute__((annotate("$clingAutoload$__functional_base")))  __attribute__((annotate("$clingAutoload$string")))  less;
}}
namespace std{inline namespace __1{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$utility")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGCgen dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
#include "inc/HGCgen.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGCgen", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGCgen",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGCgen_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGCgen_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGCgen() {
  TriggerDictionaryInitialization_DictHGCgen_Impl();
}
